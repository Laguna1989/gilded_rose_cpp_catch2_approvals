#include <items/internal_item.hpp>
#include <items/item.hpp>

#include <memory>
#include <string>
#include <vector>

class GildedRose {
public:
    explicit GildedRose(std::vector<Item>& items);

    void updateQuality();

private:
    std::vector<std::shared_ptr<InternalItem>> internalItems;
};
