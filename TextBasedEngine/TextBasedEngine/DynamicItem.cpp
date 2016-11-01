#include "DynamicItem.h"

DynamicItem::DynamicItem(bool state)
{
	setState(state);
}

DynamicItem::DynamicItem()
{

}

DynamicItem::~DynamicItem()
{

}

void DynamicItem::setState(bool state)
{
	DynamicItem::state = (state != false) ? state : true;
}