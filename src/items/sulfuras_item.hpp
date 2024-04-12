#ifndef GILDEDROSEKATA_SULFURAS_ITEM_HPP
#define GILDEDROSEKATA_SULFURAS_ITEM_HPP

#include <items/internal_item.hpp>

class SulfurasItem : public InternalItem {
public:
    explicit SulfurasItem(Item& item);
    void update() override;
};

#endif // GILDEDROSEKATA_SULFURAS_ITEM_HPP
