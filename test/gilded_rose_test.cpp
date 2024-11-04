#include "gilded_rose.hpp"

#include <ApprovalTests.hpp>
#include <catch2/catch_test_macros.hpp>

std::ostream& operator<<(std::ostream& os, Item const& obj)
{
    return os << "name: " << obj.name << ", sellIn: " << obj.sellIn
              << ", quality: " << obj.quality;
}

TEST_CASE("Single item")
{
    std::vector<Item> items {Item{"Axe", 10, 15}};
    GildedRose gildedRose{items};

    gildedRose.updateQuality();

    ApprovalTests::Approvals::verify(items[0]);
}
