#include "gilded_rose.hpp"

#include <items/item_converter.hpp>

GildedRose::GildedRose(std::vector<Item>& items)
{
    internalItems = convert(items);
}

void GildedRose::updateQuality()
{
    for (auto& item : internalItems) {
        item->update();
    }
}
