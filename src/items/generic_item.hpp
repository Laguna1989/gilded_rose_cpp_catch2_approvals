#ifndef GILDEDROSEKATA_GENERIC_ITEM_HPP
#define GILDEDROSEKATA_GENERIC_ITEM_HPP

#include "internal_item.hpp"

class GenericItem : public InternalItem {
public:
    explicit GenericItem(Item& item);
    void update() override;
};

#endif // GILDEDROSEKATA_GENERIC_ITEM_HPP
