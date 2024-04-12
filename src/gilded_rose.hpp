#include <memory>
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

class InternalItem {
public:
    explicit InternalItem(Item& item);
    virtual void update() = 0;

    void checkAndIncreaseQuality();

    Item& item;
};

class GenericItem : public InternalItem {
public:
    explicit GenericItem(Item& item);
    void update() override;
};

class AgedBrieItem : public InternalItem {
public:
    explicit AgedBrieItem(Item& item);
    void update() override;
};

class SulfurasItem : public InternalItem {
public:
    explicit SulfurasItem(Item& item);
    void update() override;
};

class BackstagePassItem : public InternalItem {
public:
    explicit BackstagePassItem(Item& item);
    void update() override;
};

class GildedRose {
public:
    explicit GildedRose(std::vector<Item>& items);

    void updateQuality();

private:
    //    std::vector<Item>& items;
    std::vector<std::shared_ptr<InternalItem>> internalItems;
};
