#include "ExprLiteral.h"

ExprLiteral::ExprLiteral(std::variant<std::monostate, int, double, bool, std::string> value){
    this->value = value;
}
ExprLiteral::ExprLiteral(){}

TData ExprLiteral::solve(Environment* environment) {

    if (std::holds_alternative<int>(value) ) {
        int litVale = std::get<int>(value);
        return TData(litVale);
    }

    if (std::holds_alternative<double>(value) ) {
        double litVale = std::get<double>(value);
        return TData(litVale);
    }

    if (std::holds_alternative<bool>(value) ) {
        bool litVale = std::get<bool>(value);
        return TData(litVale);
    }

    if (std::holds_alternative<std::string>(value) ) {
        std::string litVale = std::get<std::string>(value);
        return TData(litVale);
    }

    return TData();
}