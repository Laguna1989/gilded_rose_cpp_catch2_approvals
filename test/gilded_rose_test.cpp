#include "gilded_rose.hpp"

#include <ApprovalTests.hpp>
#include <catch2/catch_test_macros.hpp>

std::ostream& operator<<(std::ostream& os, Item const& obj)
{
    return os << "name: " << obj.name << ", sellIn: " << obj.sellIn << ", quality: " << obj.quality;
}

TEST_CASE("Single item")
{
    std::vector<Item> items { Item { "Axe", 10, 15 } };
    GildedRose gildedRose { items };

    gildedRose.updateQuality();

    ApprovalTests::Approvals::verify(items[0]);
}

TEST_CASE("Multiple items")
{
    std::vector<Item> items { Item { "Axe", 10, 15 },
        Item { "Backstage passes to a TAFKAL80ETC concert", 10, 15 } };
    GildedRose gildedRose { items };

    gildedRose.updateQuality();

    ApprovalTests::Approvals::verifyAll(items);
}

TEST_CASE("full set of combinations")
{
    auto const f = [](std::string const& name, int sellIn, int quality, int days) {
        std::vector<Item> items { Item { name, sellIn, quality } };

        GildedRose gildedRose { items };
        for (auto i = 0; i != days; ++i) {
            gildedRose.updateQuality();
        }
        return items[0];
    };

    // clang-format off
    std::vector<std::string> const names = {
        "Foo",
        "+5 Dexterity Vest",
        "Aged Brie",
        "Elixir of the Mongoose",
        "Sulfuras, Hand of Ragnaros",
        "Backstage passes to a TAFKAL80ETC concert"
};
    // clang-format on

    std::vector<int> sellIns = { -10, -5, -1, 0, 1, 2, 5, 10, 20, 50, 100 };
    std::vector<int> qualities = { 0, 1, 2, 5, 10, 20, 50, 100 };
    std::vector<int> days = { 0, 1, 2, 5, 10 };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(f, names, sellIns, qualities, days);
}