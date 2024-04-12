#include "internal_item.hpp"

void InternalItem::checkAndIncreaseQuality()
{
    if (item.quality < 50) {
        item.quality += 1;
    }
}

InternalItem::InternalItem(Item& item)
    : item { item }
{
}