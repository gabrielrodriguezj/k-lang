#include "TData.h"

TData::TData(const std::variant<std::monostate, int, double, bool, std::string> &value) : value(value) {}

std::variant<std::monostate, int, double, bool, std::string> TData::getValue() {
    return value;
}
