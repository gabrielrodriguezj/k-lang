#ifndef K_LANG_OBJECT_H
#define K_LANG_OBJECT_H


#include <variant>
#include <string>

class Object {
private:
    std::variant<std::monostate, int, double, bool, std::string> value;
public:
    explicit Object(const std::variant<std::monostate, int, double, bool, std::string> &value);
    std::variant<std::monostate, int, double, bool, std::string> getValue();
};


#endif //K_LANG_OBJECT_H
