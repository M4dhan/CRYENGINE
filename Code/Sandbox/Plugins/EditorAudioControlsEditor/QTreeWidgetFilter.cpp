// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#include "StdAfx.h"
#include "QTreeWidgetFilter.h"
#include <QTreeWidgetItemIterator>
#include <QTreeWidget>

QTreeWidgetFilter::QTreeWidgetFilter()
	: m_pTreeWidget(nullptr)
{
}

void QTreeWidgetFilter::SetTree(QTreeWidget* pTreeWidget)
{
	m_pTreeWidget = pTreeWidget;
}

void QTreeWidgetFilter::AddFilter(ITreeWidgetItemFilter* filter)
{
	m_filters.push_back(filter);
}

void QTreeWidgetFilter::ApplyFilter()
{
	if (m_pTreeWidget)
	{
		// Apply filter to each item in the tree.
		// The traversal is guaranteed to be in pre-order (visit parent before children).
		// This means if a parent is filtered-out but a child is filtered-in, the parent
		// is shown again to be able to show the child.
		// In essence, visibility of a child rules over visibility of a parent.
		QTreeWidgetItemIterator it(m_pTreeWidget);
		while (*it)
		{
			bool bValid = IsItemValid(*it);
			QTreeWidgetItem* pItem = *it;
			pItem->setHidden(!bValid);
			if (bValid)
			{
				QTreeWidgetItem* pParent = pItem->parent();
				while (pParent)
				{
					pParent->setHidden(!bValid);
					pParent = pParent->parent();
				}
			}
			++it;
		}
	}
}

bool QTreeWidgetFilter::IsItemValid(QTreeWidgetItem* pItem)
{
	size_t size = m_filters.size();
	for (int i = 0; i < size; ++i)
	{
		if (!m_filters[i]->IsItemValid(pItem))
		{
			return false;
		}
	}
	return true;
}
