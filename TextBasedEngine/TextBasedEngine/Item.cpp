#include "Item.h"

Item::Item(unsigned int value)
{
	setValue(value);
}

Item::Item()
{

}

Item::~Item()
{

}

void Item::setValue(unsigned int value)
{
	Item::value = (value > 0) ? value : 1;
}
