#include "gilded_rose.hpp"

#include <ApprovalTests.hpp>
#include <catch2/catch_all.hpp>
#include <utility>

std::ostream& operator<<(std::ostream& os, Item const& obj)
{
    return os << "name: " << obj.name << ", sellIn: " << obj.sellIn
              << ", quality: " << obj.quality;
}

TEST_CASE("Update Quality")
{
    auto const f = [](const std::string& name, int sellIn, int quality, int days) {
        std::vector<Item> items = { Item(name, sellIn, quality) };
        GildedRose app(items);
        for (int day = 0; day != days; ++day) {
            app.updateQuality();
        }
        return items[0];
    };
    // clang-format off
    std::vector<std::string> const names = {"Foo", "+5 Dexterity Vest", "Aged Brie", "Elixir of the Mongoose", "Sulfuras, Hand of Ragnaros", "Backstage passes to a TAFKAL80ETC concert"};
    // clang-format on

    std::vector<int> sellIns = { -10, -5, -1, 0, 1, 2, 5, 10, 20, 50, 100 };
    std::vector<int> qualities = { 0, 1, 2, 5, 10, 20, 50, 100 };
    std::vector<int> days ={ 0, 1, 2, 5, 10 };

    ApprovalTests::CombinationApprovals ::verifyAllCombinations(f, names, sellIns, qualities, days);
}
