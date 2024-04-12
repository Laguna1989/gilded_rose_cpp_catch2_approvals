#ifndef GILDEDROSEKATA_ITEM_HPP
#define GILDEDROSEKATA_ITEM_HPP

#include <string>

class Item {
public:
    std::string name;
    int sellIn;
    int quality;

    Item(std::string const& name, int sellIn, int quality)
        : name{name}
        , sellIn{sellIn}
        , quality{quality}
    {
    }
};
#endif // GILDEDROSEKATA_ITEM_HPP
