#ifndef GILDEDROSEKATA_BACKSTAGE_PASS_ITEM_HPP
#define GILDEDROSEKATA_BACKSTAGE_PASS_ITEM_HPP

#include <items/internal_item.hpp>

class BackstagePassItem : public InternalItem {
public:
    explicit BackstagePassItem(Item& item);
    void update() override;
};

#endif // GILDEDROSEKATA_BACKSTAGE_PASS_ITEM_HPP
