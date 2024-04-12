#ifndef GILDEDROSEKATA_INTERNAL_ITEM_HPP
#define GILDEDROSEKATA_INTERNAL_ITEM_HPP

#include "item.hpp"

class InternalItem {
public:
    explicit InternalItem(Item& item);
    virtual void update() = 0;

    void checkAndIncreaseQuality();

    Item& item;
};

#endif // GILDEDROSEKATA_INTERNAL_ITEM_HPP
