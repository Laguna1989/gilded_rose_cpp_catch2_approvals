#include "item_converter.hpp"

#include <items/aged_brie_item.hpp>
#include <items/generic_item.hpp>
#include <items/backstage_pass_item.hpp>
#include <items/sulfuras_item.hpp>

std::vector<std::shared_ptr<InternalItem>> convert(std::vector<Item>& items)
{
    std::vector<std::shared_ptr<InternalItem>> internalItems;
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

    return internalItems;
}
