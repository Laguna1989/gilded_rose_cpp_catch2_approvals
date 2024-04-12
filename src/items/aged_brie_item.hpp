#ifndef GILDEDROSEKATA_AGED_BRIE_ITEM_HPP
#define GILDEDROSEKATA_AGED_BRIE_ITEM_HPP

#include "internal_item.hpp"

class AgedBrieItem : public InternalItem {
public:
    explicit AgedBrieItem(Item& item);
    void update() override;
};

#endif // GILDEDROSEKATA_AGED_BRIE_ITEM_HPP
