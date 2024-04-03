#include "TData.h"
#include "../Exceptions/RuntimeException.h"

TData::TData(const std::variant<std::monostate, int, double, bool, std::string> &value) : value(value) {}

std::variant<std::monostate, int, double, bool, std::string> TData::getValue() {
    return value;
}

TData TData::operator + (TData &other) {
    auto rightValue = other.value;

    if (std::holds_alternative<int>(value) && std::holds_alternative<int>(rightValue)) {
        int lvalue = std::get<int>(value);
        int rvalue = std::get<int>(rightValue);
        int res = lvalue + rvalue;
        return TData(res);
    }
    else if (std::holds_alternative<int>(value) && std::holds_alternative<double>(rightValue)) {
        int lvalue = std::get<int>(value);
        double rvalue = std::get<double>(rightValue);
        double res = lvalue + rvalue;
        return TData(res);
    }
    else if (std::holds_alternative<double>(value) && std::holds_alternative<int>(rightValue)) {
        double lvalue = std::get<double>(value);
        int rvalue = std::get<int>(rightValue);
        double res = lvalue + rvalue;
        return TData(res);
    }
    else if (std::holds_alternative<double>(value) && std::holds_alternative<double>(rightValue)) {
        double lvalue = std::get<double>(value);
        double rvalue = std::get<double>(rightValue);
        double res = lvalue + rvalue;
        return TData(res);
    }
    else if (std::holds_alternative<std::string>(value) && std::holds_alternative<std::string>(rightValue)) {
        std::string lvalue = std::get<std::string>(value);
        std::string rvalue = std::get<std::string>(rightValue);
        std::string res = lvalue + rvalue;
        return TData(res);
    }

    throw RuntimeException("El operador '+' no es aplicable a los operandos");
}

TData TData::operator - (TData &other) {
    auto rightValue = other.value;

    if (std::holds_alternative<int>(value) && std::holds_alternative<int>(rightValue)) {
        int lvalue = std::get<int>(value);
        int rvalue = std::get<int>(rightValue);
        int res = lvalue - rvalue;
        return TData(res);
    }
    else if (std::holds_alternative<int>(value) && std::holds_alternative<double>(rightValue)) {
        int lvalue = std::get<int>(value);
        double rvalue = std::get<double>(rightValue);
        double res = lvalue - rvalue;
        return TData(res);
    }
    else if (std::holds_alternative<double>(value) && std::holds_alternative<int>(rightValue)) {
        double lvalue = std::get<double>(value);
        int rvalue = std::get<int>(rightValue);
        double res = lvalue - rvalue;
        return TData(res);
    }
    else if (std::holds_alternative<double>(value) && std::holds_alternative<double>(rightValue)) {
        double lvalue = std::get<double>(value);
        double rvalue = std::get<double>(rightValue);
        double res = lvalue - rvalue;
        return TData(res);
    }

    throw RuntimeException("El operador '-' no es aplicable a los operandos");
}

TData TData::operator * (TData &other) {
    auto rightValue = other.value;

    if (std::holds_alternative<int>(value) && std::holds_alternative<int>(rightValue)) {
        int lvalue = std::get<int>(value);
        int rvalue = std::get<int>(rightValue);
        int res = lvalue * rvalue;
        return TData(res);
    }
    else if (std::holds_alternative<int>(value) && std::holds_alternative<double>(rightValue)) {
        int lvalue = std::get<int>(value);
        double rvalue = std::get<double>(rightValue);
        double res = lvalue * rvalue;
        return TData(res);
    }
    else if (std::holds_alternative<double>(value) && std::holds_alternative<int>(rightValue)) {
        double lvalue = std::get<double>(value);
        int rvalue = std::get<int>(rightValue);
        double res = lvalue * rvalue;
        return TData(res);
    }
    else if (std::holds_alternative<double>(value) && std::holds_alternative<double>(rightValue)) {
        double lvalue = std::get<double>(value);
        double rvalue = std::get<double>(rightValue);
        double res = lvalue * rvalue;
        return TData(res);
    }

    throw RuntimeException("El operador '*' no es aplicable a los operandos");
}

TData TData::operator / (TData &other) {
    auto rightValue = other.value;

    if (std::holds_alternative<int>(value) && std::holds_alternative<int>(rightValue)) {
        int lvalue = std::get<int>(value);
        int rvalue = std::get<int>(rightValue);

        if(rvalue == 0){
            throw RuntimeException("El divisor no puede ser 0");
        }

        int res = lvalue / rvalue;
        return TData(res);
    }
    else if (std::holds_alternative<int>(value) && std::holds_alternative<double>(rightValue)) {
        int lvalue = std::get<int>(value);
        double rvalue = std::get<double>(rightValue);

        if(rvalue == 0){
            throw RuntimeException("El divisor no puede ser 0");
        }

        double res = lvalue / rvalue;
        return TData(res);
    }
    else if (std::holds_alternative<double>(value) && std::holds_alternative<int>(rightValue)) {
        double lvalue = std::get<double>(value);
        int rvalue = std::get<int>(rightValue);

        if(rvalue == 0){
            throw RuntimeException("El divisor no puede ser 0");
        }

        double res = lvalue / rvalue;
        return TData(res);
    }
    else if (std::holds_alternative<double>(value) && std::holds_alternative<double>(rightValue)) {
        double lvalue = std::get<double>(value);
        double rvalue = std::get<double>(rightValue);

        if(rvalue == 0){
            throw RuntimeException("El divisor no puede ser 0");
        }

        double res = lvalue / rvalue;
        return TData(res);
    }

    throw RuntimeException("El operador '/' no es aplicable a los operandos");
}
