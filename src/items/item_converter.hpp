#ifndef GILDEDROSEKATA_ITEM_CONVERTER_HPP
#define GILDEDROSEKATA_ITEM_CONVERTER_HPP

#include <items/item.hpp>
#include <items/internal_item.hpp>

#include <vector>
#include <memory>

std::vector<std::shared_ptr<InternalItem>> convert(std::vector<Item>& items);


#endif // GILDEDROSEKATA_ITEM_CONVERTER_HPP
