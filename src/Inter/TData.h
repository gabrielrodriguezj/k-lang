#ifndef K_LANG_TDATA_H
#define K_LANG_TDATA_H


#include <variant>
#include <string>

class TData {
private:
    std::variant<std::monostate, int, double, bool, std::string> value;
public:
    explicit TData(const std::variant<std::monostate, int, double, bool, std::string> &value);
    explicit TData();
    std::variant<std::monostate, int, double, bool, std::string> getValue();

    // Sobrecarga de operadores
    TData operator - ();
    TData operator ! ();

    TData operator + (TData&);
    TData operator - (TData&);
    TData operator * (TData&);
    TData operator / (TData&);

    TData operator < (TData&);
    TData operator <= (TData&);
    TData operator > (TData&);
    TData operator >= (TData&);
    TData operator != (TData&);
    TData operator == (TData&);

    TData operator || (TData&);
    TData operator && (TData&);
};


#endif //K_LANG_TDATA_H
