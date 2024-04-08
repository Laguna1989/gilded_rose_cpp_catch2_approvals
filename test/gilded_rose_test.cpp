#include "gilded_rose.hpp"

#include <ApprovalTests.hpp>
#include <catch2/catch_all.hpp>
#include <utility>

namespace {

struct TestData {
    std::vector<Item> item;
    int daysToUpgrade {};
};

std::ostream& operator<<(std::ostream& os, TestData const& obj)
{
    return os << "name: " << obj.item[0].name << ", sellIn: " << obj.item[0].sellIn
              << ", quality: " << obj.item[0].quality << ", daysToUpgrade: " << obj.daysToUpgrade;
}

std::vector<TestData> getAllTestDataCombinations()
{
    std::vector<TestData> testData;

    // clang-format off
    for (auto name : { "foo", "Sulfuras, Hand of Ragnaros", "Aged Brie", "Backstage passes to a TAFKAL80ETC concert" }) {
        // clang-format on
        for (auto sell_in : { -10, -5, -1, 0, 1, 2, 5, 10, 20, 50, 100 }) {
            for (auto quality : { 0, 1, 2, 5, 10, 20, 50, 100 }) {
                for (auto daysToUpgrade : { 0, 1, 2, 5, 10 }) {
                    TestData data;
                    data.item.emplace_back(name, sell_in, quality);
                    data.daysToUpgrade = daysToUpgrade;
                    testData.emplace_back(std::move(data));
                }
            }
        }
    }
    return testData;
}

} // namespace

TEST_CASE("Update Quality")
{
    std::vector<TestData> items = getAllTestDataCombinations();

    for (auto& testData : items) {
        GildedRose gildedRose { testData.item };
        for (auto i = 0; i != testData.daysToUpgrade; ++i) {
            gildedRose.updateQuality();
        }
    }

    ApprovalTests::Approvals::verifyAll(items);
}
