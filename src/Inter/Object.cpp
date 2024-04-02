#include "Object.h"

Object::Object(const std::variant<std::monostate, int, double, bool, std::string> &value) : value(value) {}

std::variant<std::monostate, int, double, bool, std::string> Object::getValue() {
    return value;
}
