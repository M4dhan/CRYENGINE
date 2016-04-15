// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

// -------------------------------------------------------------------------
//  Created:     06/04/2014 by Filipe amim
//  Description:
// -------------------------------------------------------------------------
//
////////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include <CrySystem/CryUnitTest.h>
#include "ParticleSystem.h"
#include "ParticleContainer.h"
#include "../ParticleEffect.h"
#include "ParticleEffect.h"
#include <CryMath/SNoise.h>
#include <CryMath/RadixSort.h>

#include <CrySerialization/IArchiveHost.h>
#include <CrySerialization/Color.h>

CRY_PFX2_DBG

CRY_UNIT_TEST_SUITE(CryParticleSystemTest)
{

	using namespace pfx2;

#define arraysize(array) (sizeof(array) / sizeof(array[0]))

#define CRY_PFX2_UNIT_TEST_ASSERT(cond) \
  CRY_PFX2_ASSERT(cond)                 \
  CRY_UNIT_TEST_ASSERT(cond)

	CRY_UNIT_TEST_FIXTURE(CParticleContainerRemoveTests)
	{
		void Test(size_t containerSz, TParticleId* toRemove, size_t toRemoveSz)
		{
			// create particles with SpawnId
			TParticleHeap heap;
			pfx2::CParticleContainer container;
			container.AddParticleData(EPDT_SpawnId);
			pfx2::CParticleContainer::SSpawnEntry spawn;
			spawn.m_count = containerSz;
			spawn.m_parentId = 0;
			container.AddRemoveParticles(&spawn, 1, 0, 0);
			container.ResetSpawnedParticles();
			IOPidStream spawnIds = container.GetIOPidStream(EPDT_SpawnId);
			for (uint i = 0; i < containerSz; ++i)
				spawnIds.Store(i, i);

			// remove particles
			TParticleIdArray toRemoveMem(heap);
			toRemoveMem.reserve(toRemoveSz);
			for (size_t i = 0; i < toRemoveSz; ++i)
				toRemoveMem.push_back(toRemove[i]);
			TParticleIdArray swapIds(heap, container.GetNumParticles());
			container.AddRemoveParticles(0, 0, &toRemoveMem, &swapIds);

			// check if none of the particles are in the toRemove list
			for (uint i = 0; i < containerSz - toRemoveSz; ++i)
			{
				for (uint j = 0; j < toRemoveSz; ++j)
				{
					CRY_PFX2_UNIT_TEST_ASSERT(spawnIds.Load(i) != toRemove[j]);
				}
			}

			// check that no ids are repeated
			for (uint i = 0; i < containerSz - toRemoveSz; ++i)
			{
				for (uint j = 0; j < containerSz - toRemoveSz; ++j)
				{
					if (i == j)
						continue;
					CRY_PFX2_UNIT_TEST_ASSERT(spawnIds.Load(i) != spawnIds.Load(j));
				}
			}

			// check if SwapIds is consistent with the actual final locations of the particles
			TParticleIdArray expected(heap, containerSz);
			for (uint i = 0; i < containerSz - toRemoveSz; ++i)
				expected[spawnIds.Load(i)] = i;
			for (uint i = 0; i < toRemoveSz; ++i)
				expected[toRemove[i]] = gInvalidId;
			CRY_PFX2_UNIT_TEST_ASSERT(memcmp(swapIds.data(), expected.data(), sizeof(TParticleId) * containerSz) == 0);
		}
	};

	CRY_UNIT_TEST_WITH_FIXTURE(CParticleContainer_Remove_Case1, CParticleContainerRemoveTests)
	{
		TParticleId toRemove[] = { 3, 4 };
		Test(5, toRemove, arraysize(toRemove));
	}

	CRY_UNIT_TEST_WITH_FIXTURE(CParticleContainer_Remove_Case2, CParticleContainerRemoveTests)
	{
		TParticleId toRemove[] = { 8, 12 };
		Test(13, toRemove, arraysize(toRemove));
	}

	CRY_UNIT_TEST_WITH_FIXTURE(CParticleContainer_Remove_Case3, CParticleContainerRemoveTests)
	{
		TParticleId toRemove[] = { 0, 4 };
		Test(5, toRemove, arraysize(toRemove));
	}

	CRY_UNIT_TEST_WITH_FIXTURE(CParticleContainer_Remove_Case4, CParticleContainerRemoveTests)
	{
		TParticleId toRemove[] = { 4, 7, 9 };
		Test(10, toRemove, arraysize(toRemove));
	}

	CRY_UNIT_TEST_WITH_FIXTURE(CParticleContainer_Remove_Case5, CParticleContainerRemoveTests)
	{
		TParticleId toRemove[] = { 0, 1, 2, 4, 5, 6 };
		Test(7, toRemove, arraysize(toRemove));
	}

	CRY_UNIT_TEST_WITH_FIXTURE(CParticleContainer_Remove_Case6, CParticleContainerRemoveTests)
	{
		TParticleId toRemove[] = { 0 };
		Test(1, toRemove, arraysize(toRemove));
	}

	CRY_UNIT_TEST_WITH_FIXTURE(CParticleContainer_Remove_Case7, CParticleContainerRemoveTests)
	{
		TParticleId toRemove[] = { 9, 11 };
		Test(21, toRemove, arraysize(toRemove));
	}

#if CRY_PFX2_PARTICLESGROUP_STRIDE == 4

	CRY_UNIT_TEST_FIXTURE(CParticleContainerSpawn)
	{
	public:
		virtual void Init()
		{
			static_assert(CRY_PFX2_PARTICLESGROUP_STRIDE == 4, "This unit test is assuming vectorization of 4 particles");
			pContainer = std::unique_ptr<pfx2::CParticleContainer>(new pfx2::CParticleContainer());
			pContainer->AddParticleData(EPDT_ParentId);
			pContainer->AddParticleData(EPDT_State);
		};

		virtual void Done()
		{
			pContainer.reset();
		};

		void AddParticles(uint32 count)
		{
			ResetSpawnedParticles();
			pfx2::CParticleContainer::SSpawnEntry spawn;
			spawn.m_count = count;
			spawn.m_parentId = 0;
			pContainer->AddRemoveParticles(&spawn, 1, 0, 0);
		}

		void ResetSpawnedParticles()
		{
			pContainer->ResetSpawnedParticles();
		}

		const pfx2::CParticleContainer& GetContainer() const
		{
			return *pContainer;
		}

		void ResetAll()
		{
			pContainer->Clear();
		}

		bool TestNewBornFlags(uint numParticles)
		{
			const uint bufferSize = 128;
			const uint8 validMask = ES_Alive;
			const uint8 overrunMask = 0xff;
			pContainer->Resize(bufferSize);
			uint8* pData = static_cast<uint8*>(pContainer->GetData(EPDT_State));

			AddParticles(numParticles);
			pContainer->ResetSpawnedParticles();
			memset(pData, validMask | ESB_NewBorn, numParticles);
			memset(pData + numParticles, overrunMask, bufferSize - numParticles);

			pContainer->RemoveNewBornFlags();

			for (uint i = 0; i < numParticles; ++i)
				if (pData[i] != validMask)
					return false;
			for (uint i = numParticles; i < bufferSize; ++i)
				if (pData[i] != overrunMask)
					return false;
			return true;
		}

	private:
		std::unique_ptr<pfx2::CParticleContainer> pContainer;
	};

	CRY_UNIT_TEST_WITH_FIXTURE(CParticleContainer_VectorizeSpawn, CParticleContainerSpawn)
	{
		// PFX2_TODO : right now new born vectorization is a bit too simple. Should be profiled and tested later
		// particle memory should be segmented.

		const pfx2::CParticleContainer& container = GetContainer();
		AddParticles(6);

		AddParticles(3);
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetNumParticles() == 9);
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetLastParticleId() == 11);
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetFirstSpawnParticleId() == 8);
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetNumSpawnedParticles() == 3);
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetMaxParticles() > 11);

		ResetSpawnedParticles();
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetNumParticles() == 9);
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetLastParticleId() == 9);
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetFirstSpawnParticleId() == 9);
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetNumSpawnedParticles() == 0);
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetMaxParticles() > 9);
	}

	CRY_UNIT_TEST_WITH_FIXTURE(CParticleContainer_RealId, CParticleContainerSpawn)
	{
		const pfx2::CParticleContainer& container = GetContainer();

		AddParticles(1);
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetRealId(4) == 0);
		ResetSpawnedParticles();

		ResetAll();
		AddParticles(6);
		AddParticles(3);
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetRealId(3) == 3);
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetRealId(8) == 8);
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetRealId(10) == 7);
		ResetSpawnedParticles();
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetRealId(3) == 3);
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetRealId(8) == 8);
		CRY_PFX2_UNIT_TEST_ASSERT(container.GetRealId(6) == 6);
	}

	CRY_UNIT_TEST_WITH_FIXTURE(CParticleContainer_NewBornFlags_Case1, CParticleContainerSpawn)
	{
		const bool result = TestNewBornFlags(16);
		CRY_PFX2_UNIT_TEST_ASSERT(result);
	}
	CRY_UNIT_TEST_WITH_FIXTURE(CParticleContainer_NewBornFlags_Case2, CParticleContainerSpawn)
	{
		const bool result = TestNewBornFlags(18);
		CRY_PFX2_UNIT_TEST_ASSERT(result);
	}
	CRY_UNIT_TEST_WITH_FIXTURE(CParticleContainer_NewBornFlags_Case3, CParticleContainerSpawn)
	{
		const bool result = TestNewBornFlags(39);
		CRY_PFX2_UNIT_TEST_ASSERT(result);
	}
	CRY_UNIT_TEST_WITH_FIXTURE(CParticleContainer_NewBornFlags_Case4, CParticleContainerSpawn)
	{
		const bool result = TestNewBornFlags(52);
		CRY_PFX2_UNIT_TEST_ASSERT(result);
	}

	CRY_UNIT_TEST_FIXTURE(CParticleEffectTests)
	{
	public:
		virtual void Init() override
		{
			m_pEffect = std::unique_ptr<pfx2::CParticleEffect>(new pfx2::CParticleEffect());
		};

		virtual void Done() override
		{
			m_pEffect.reset();
		}

		pfx2::CParticleEffect& GetEffect()
		{
			return *m_pEffect;
		}

		void LoadSimpleEffect()
		{
			const char* jsonCode =
			  "{ \"Version\": 3,\n"
			  "	\"Components\": [\n"
			  "		{ \"Component\": { \"Name\": \"Test01\" }},\n"
			  "		{ \"Component\": { \"Name\": \"Test02\" }}]}\n";
			Serialization::LoadJsonBuffer(GetEffect(), jsonCode, strlen(jsonCode));
		}

		void LoadDefaultComponent(TComponentId componentId)
		{
			const char* jsonCode =
			  "{ \"Name\": \"Default\", \"Features\": [\n"
			  "	{ \"RenderSprites\": { \"SortMode\": \"None\" } },\n"
			  "	{ \"SpawnRate\": {\n"
			  "		\"Amount\": { \"value\": 1.0, \"modifiers\": [ ] },\n"
			  "		\"Delay\": { \"State\": false, \"Value\": { \"value\": 0.0, \"modifiers\": [ ] } },\n"
			  "		\"Duration\": { \"State\": false, \"Value\": { \"value\": 0.0, \"modifiers\": [ ] } },\n"
			  "		\"Mode\": \"ParticlesPerSecond\"} },\n"
			  "	{ \"LifeTime\": { \"LifeTime\": { \"value\": 1, \"var\": 0 } } },\n"
			  "	{ \"FieldSize\": { \"value\": { \"value\": 1, \"modifiers\": [ ] } } } ] }\n";
			Serialization::LoadJsonBuffer(*GetEffect().GetComponent(componentId), jsonCode, strlen(jsonCode));
		}

	private:
		std::unique_ptr<pfx2::CParticleEffect> m_pEffect;
	};

	CRY_UNIT_TEST_WITH_FIXTURE(CParticleSystem_USimpleEffect, CParticleEffectTests)
	{
		pfx2::CParticleEffect& effect = GetEffect();
		LoadSimpleEffect();
		CRY_PFX2_UNIT_TEST_ASSERT(strcmp(effect.GetComponent(0)->GetName(), "Test01") == 0);
		CRY_PFX2_UNIT_TEST_ASSERT(strcmp(effect.GetComponent(1)->GetName(), "Test02") == 0);
	}

	CRY_UNIT_TEST_WITH_FIXTURE(CParticleSystem_UniqueAutoName, CParticleEffectTests)
	{
		pfx2::CParticleEffect& effect = GetEffect();
		effect.AddComponent(0);
		effect.AddComponent(1);
		CRY_PFX2_UNIT_TEST_ASSERT(strcmp(effect.GetComponent(0)->GetName(), "Component01") == 0);
		CRY_PFX2_UNIT_TEST_ASSERT(strcmp(effect.GetComponent(1)->GetName(), "Component02") == 0);
	}

	CRY_UNIT_TEST_WITH_FIXTURE(CParticleSystem_UniqueCustomName, CParticleEffectTests)
	{
		pfx2::CParticleEffect& effect = GetEffect();
		effect.AddComponent(0);
		effect.GetComponent(0)->SetName("Test");
		effect.AddComponent(1);
		effect.GetComponent(1)->SetName("Test");
		effect.AddComponent(2);
		effect.GetComponent(2)->SetName("Test");
		CRY_PFX2_UNIT_TEST_ASSERT(strcmp(effect.GetComponent(0)->GetName(), "Test") == 0);
		CRY_PFX2_UNIT_TEST_ASSERT(strcmp(effect.GetComponent(1)->GetName(), "Test01") == 0);
		CRY_PFX2_UNIT_TEST_ASSERT(strcmp(effect.GetComponent(2)->GetName(), "Test02") == 0);
	}

	CRY_UNIT_TEST_WITH_FIXTURE(CParticleSystem_UniqueLoadedName, CParticleEffectTests)
	{
		pfx2::CParticleEffect& effect = GetEffect();
		effect.AddComponent(0);
		LoadDefaultComponent(0);
		effect.AddComponent(1);
		LoadDefaultComponent(1);
		effect.AddComponent(2);
		LoadDefaultComponent(2);
		CRY_PFX2_UNIT_TEST_ASSERT(strcmp(effect.GetComponent(0)->GetName(), "Default") == 0);
		CRY_PFX2_UNIT_TEST_ASSERT(strcmp(effect.GetComponent(1)->GetName(), "Default01") == 0);
		CRY_PFX2_UNIT_TEST_ASSERT(strcmp(effect.GetComponent(2)->GetName(), "Default02") == 0);
	}

#endif

#ifdef CRY_PFX2_USE_SSE

	CRY_UNIT_TEST(ParticleSSE_IndexedLoad4)
	{
		using namespace pfx2::detail;
		CRY_ALIGN(16) float stream[] = { 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f };
		__m128i index;
		__m128 expected, got;

		index = _mm_set1_epi32(2);
		expected = _mm_set_ps(2.0f, 2.0f, 2.0f, 2.0f);
		got = LoadIndexed4(stream, index, -1.0f);
		CRY_PFX2_UNIT_TEST_ASSERT(AllEqual(got, expected));

		index = _mm_set_epi32(7, 6, 5, 4);
		expected = _mm_set_ps(7.0f, 6.0f, 5.0f, 4.0f);
		got = LoadIndexed4(stream, index, -1.0f);
		CRY_PFX2_UNIT_TEST_ASSERT(AllEqual(got, expected));

		index = _mm_set_epi32(0, 1, 2, 0);
		expected = _mm_set_ps(0.0f, 1.0f, 2.0f, 0.0f);
		got = LoadIndexed4(stream, index, -1.0f);
		CRY_PFX2_UNIT_TEST_ASSERT(AllEqual(got, expected));

		index = _mm_set_epi32(0, -1, 2, -1);
		expected = _mm_set_ps(0.0f, -1.0f, 2.0f, -1.0f);
		got = LoadIndexed4(stream, index, -1.0f);
		CRY_PFX2_UNIT_TEST_ASSERT(AllEqual(got, expected));

		index = _mm_set_epi32(-1, -1, -1, -1);
		expected = _mm_set_ps(-1.0f, -1.0f, -1.0f, -1.0f);
		got = LoadIndexed4(stream, index, -1.0f);
		CRY_PFX2_UNIT_TEST_ASSERT(AllEqual(got, expected));

		index = _mm_set_epi32(9, 9, 2, 2);
		expected = _mm_set_ps(9.0f, 9.0f, 2.0f, 2.0f);
		got = LoadIndexed4(stream, index, -1.0f);
		CRY_PFX2_UNIT_TEST_ASSERT(AllEqual(got, expected));
	}

#endif

}

CRY_UNIT_TEST_SUITE(CryVectorTest)
{

#if defined(CRY_PFX2_USE_SSE) && CRY_COMPILER_MSVC

	bool operator==(__m128 a, __m128 b)
	{
		return _mm_movemask_ps(_mm_cmpeq_ps(a, b)) == 0xf;
	}

	template<typename Real>
	void MathTest()
	{
		using namespace crydetail;
		Real v0, v1, v2, v3, v4;

		v0 = crydetail::floorf(ToReal<Real>(257.35f));
		v1 = crydetail::floorf(ToReal<Real>(252.0f));
		v2 = crydetail::floorf(ToReal<Real>(-102.4f));
		v3 = crydetail::floorf(ToReal<Real>(0.806228399f));
		v4 = crydetail::floorf(ToReal<Real>(0.733564019));
		CRY_PFX2_UNIT_TEST_ASSERT(v0 == ToReal<Real>(257.0f));
		CRY_PFX2_UNIT_TEST_ASSERT(v1 == ToReal<Real>(252.0f));
		CRY_PFX2_UNIT_TEST_ASSERT(v2 == ToReal<Real>(-103.0f));
		CRY_PFX2_UNIT_TEST_ASSERT(v3 == ToReal<Real>(0.0f));
		CRY_PFX2_UNIT_TEST_ASSERT(v4 == ToReal<Real>(0.0f));

		v0 = crydetail::max(ToReal<Real>(257.35f), ToReal<Real>(510.0f));
		v1 = crydetail::max(ToReal<Real>(-102.0f), ToReal<Real>(-201.4f));
		CRY_PFX2_UNIT_TEST_ASSERT(v0 == ToReal<Real>(510.0f));
		CRY_PFX2_UNIT_TEST_ASSERT(v1 == ToReal<Real>(-102.0f));

		v0 = crydetail::saturate(ToReal<Real>(0.75f));
		v1 = crydetail::saturate(ToReal<Real>(-0.35f));
		v2 = crydetail::saturate(ToReal<Real>(2.05f));
		CRY_PFX2_UNIT_TEST_ASSERT(v0 == ToReal<Real>(0.75f));
		CRY_PFX2_UNIT_TEST_ASSERT(v1 == ToReal<Real>(0.0f));
		CRY_PFX2_UNIT_TEST_ASSERT(v2 == ToReal<Real>(1.0f));

		v0 = crydetail::step(ToReal<Real>(0.75f), ToReal<Real>(1.25f));
		v1 = crydetail::step(ToReal<Real>(0.25f), ToReal<Real>(-0.2f));
		v2 = crydetail::step(ToReal<Real>(0.35f), ToReal<Real>(0.35f));
		CRY_PFX2_UNIT_TEST_ASSERT(v0 == ToReal<Real>(1.0f));
		CRY_PFX2_UNIT_TEST_ASSERT(v1 == ToReal<Real>(0.0f));
		CRY_PFX2_UNIT_TEST_ASSERT(v2 == ToReal<Real>(1.0f));

		v0 = crydetail::absf(ToReal<Real>(104.35f));
		v1 = crydetail::absf(ToReal<Real>(-24.75f));
		v2 = crydetail::absf(ToReal<Real>(0.0f));
		CRY_PFX2_UNIT_TEST_ASSERT(v0 == ToReal<Real>(104.35f));
		CRY_PFX2_UNIT_TEST_ASSERT(v1 == ToReal<Real>(24.75f));
		CRY_PFX2_UNIT_TEST_ASSERT(v2 == ToReal<Real>(0.0f));

		v0 = crydetail::lessThan(ToReal<Real>(257.35f), ToReal<Real>(510.0f));
		v1 = crydetail::lessThan(ToReal<Real>(-102.0f), ToReal<Real>(-201.4f));
		CRY_PFX2_UNIT_TEST_ASSERT(v0 == ToReal<Real>(1.0f));
		CRY_PFX2_UNIT_TEST_ASSERT(v1 == ToReal<Real>(0.0f));
	}

	CRY_UNIT_TEST(MathTestAll)
	{
		MathTest<float>();
		MathTest<__m128>();
	}

	template<typename Real>
	void SnoiseTest()
	{
		using namespace crydetail;
		const Vec4_tpl<Real> s0 = ToVec4(ToReal<Real>(0.0f));
		const Vec4_tpl<Real> s1 = Vec4_tpl<Real>(ToReal<Real>(104.2f), ToReal<Real>(504.85f), ToReal<Real>(32.0f), ToReal<Real>(10.25f));
		const Vec4_tpl<Real> s2 = Vec4_tpl<Real>(ToReal<Real>(-104.2f), ToReal<Real>(504.85f), ToReal<Real>(-32.0f), ToReal<Real>(1.25f));
		const Vec4_tpl<Real> s3 = Vec4_tpl<Real>(ToReal<Real>(-257.07f), ToReal<Real>(-25.85f), ToReal<Real>(-0.5f), ToReal<Real>(105.5f));
		const Vec4_tpl<Real> s4 = Vec4_tpl<Real>(ToReal<Real>(104.2f), ToReal<Real>(1504.85f), ToReal<Real>(78.57f), ToReal<Real>(-0.75f));
		Real p0 = SNoise(s0);
		Real p1 = SNoise(s1);
		Real p2 = SNoise(s2);
		Real p3 = SNoise(s3);
		Real p4 = SNoise(s4);
		CRY_PFX2_UNIT_TEST_ASSERT(p0 == ToReal<Real>(0.0f));
		CRY_PFX2_UNIT_TEST_ASSERT(p1 == ToReal<Real>(-0.291425288f));
		CRY_PFX2_UNIT_TEST_ASSERT(p2 == ToReal<Real>(-0.295406163f));
		CRY_PFX2_UNIT_TEST_ASSERT(p3 == ToReal<Real>(-0.127176195f));
		CRY_PFX2_UNIT_TEST_ASSERT(p4 == ToReal<Real>(-0.0293087773f));
	}

	CRY_UNIT_TEST(SNoiseTest)
	{
		// SnoiseTest<float>();
		SnoiseTest<__m128>();
	}

	CRY_UNIT_TEST(RadixSortTest)
	{
		pfx2::TParticleHeap heap;

		const uint64 data[] = { 15923216, 450445401561561, 5061954, 5491494, 56494109840, 500120, 520025710, 58974, 45842669, 3226, 995422665 };
		const uint sz = sizeof(data) / sizeof(data[0]);
		const uint32 expectedIndices[sz] = { 9, 7, 5, 2, 3, 0, 8, 6, 10, 4, 1 };
		uint32 indices[sz];

		RadixSort(indices, indices + sz, data, data + sz, heap);

		CRY_PFX2_UNIT_TEST_ASSERT(memcmp(expectedIndices, indices, sz * 4) == 0);
	}

#endif

}
