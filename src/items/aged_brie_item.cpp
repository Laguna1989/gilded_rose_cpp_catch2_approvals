#include "aged_brie_item.hpp"

AgedBrieItem::AgedBrieItem(Item& item)
    : InternalItem(item)
{
}

void AgedBrieItem::update()
{
    checkAndIncreaseQuality();

    item.sellIn = item.sellIn - 1;

    if (item.sellIn < 0) {
        checkAndIncreaseQuality();
    }
}