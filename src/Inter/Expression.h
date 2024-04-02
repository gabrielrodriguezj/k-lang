#ifndef K_LANG_EXPRESSION_H
#define K_LANG_EXPRESSION_H


#include <variant>
#include <string>

class Expression {
public:
    virtual std::variant<std::monostate, int, double, bool, std::string> solve() = 0;
};


#endif //K_LANG_EXPRESSION_H
