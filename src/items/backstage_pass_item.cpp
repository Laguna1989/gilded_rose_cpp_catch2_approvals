#include "backstage_pass_item.hpp"

BackstagePassItem::BackstagePassItem(Item& item)
    : InternalItem(item)
{
}

void BackstagePassItem::update()
{
    checkAndIncreaseQuality();

    if (item.sellIn <= 10) {
        checkAndIncreaseQuality();
    }

    if (item.sellIn <= 5) {
        checkAndIncreaseQuality();
    }
    item.sellIn = item.sellIn - 1;

    if (item.sellIn < 0) {
        item.quality = 0;
    }
}