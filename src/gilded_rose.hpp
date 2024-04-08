#include <string>
#include <vector>

class Item {
public:
    std::string name;
    int sellIn;
    int quality;

    Item(std::string const& name, int sellIn, int quality)
        : name(name)
        , sellIn(sellIn)
        , quality(quality)
    {
    }
};

class GildedRose {
public:
    explicit GildedRose(std::vector<Item>& items);

    void updateQuality();

private:
    std::vector<Item>& items;
};
