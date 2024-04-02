#ifndef K_LANG_TDATA_H
#define K_LANG_TDATA_H


#include <variant>
#include <string>

class TData {
private:
    std::variant<std::monostate, int, double, bool, std::string> value;
public:
    explicit TData(const std::variant<std::monostate, int, double, bool, std::string> &value);
    std::variant<std::monostate, int, double, bool, std::string> getValue();
};


#endif //K_LANG_TDATA_H
