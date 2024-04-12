#include "generic_item.hpp"

GenericItem::GenericItem(Item& item)
    : InternalItem(item)
{
}

void GenericItem::update()
{
    if (item.quality > 0) {
        item.quality -= 1;
    }
    item.sellIn = item.sellIn - 1;

    if (item.sellIn < 0) {
        if (item.quality > 0) {
            item.quality -= 1;
        }
    }
}