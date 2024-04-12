#include "gilded_rose.hpp"

GildedRose::GildedRose(std::vector<Item>& items)
{
    constexpr auto nameAgedBrie = "Aged Brie";
    constexpr auto nameBackstagePass = "Backstage passes to a TAFKAL80ETC concert";
    constexpr auto nameSulfuras = "Sulfuras, Hand of Ragnaros";

    for (auto& item : items) {
        if (item.name == nameAgedBrie) {
            internalItems.push_back(std::make_shared<AgedBrieItem>(item));
        } else if (item.name == nameBackstagePass) {
            internalItems.push_back(std::make_shared<BackstagePassItem>(item));
        } else if (item.name == nameSulfuras) {
            internalItems.push_back(std::make_shared<SulfurasItem>(item));
        } else {
            internalItems.push_back(std::make_shared<GenericItem>(item));
        }
    }
}

void InternalItem::checkAndIncreaseQuality()
{
    if (item.quality < 50) {
        item.quality += 1;
    }
}

void GildedRose::updateQuality()
{
    for (auto& item : internalItems) {
        item->update();
    }
}

InternalItem::InternalItem(Item& item)
    : item { item }
{
}

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

SulfurasItem::SulfurasItem(Item& item)
    : InternalItem(item)
{
}

void SulfurasItem::update() { }

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
