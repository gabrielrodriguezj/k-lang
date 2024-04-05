#ifndef K_LANG_TDATA_H
#define K_LANG_TDATA_H


#include <variant>
#include <string>
#include "KCallable.h"

class TData {
private:
    std::variant<std::monostate, int, double, bool, std::string, KCallable*> value;
public:
    explicit TData(const std::variant<std::monostate, int, double, bool, std::string, KCallable*> &value);
    explicit TData();
    std::variant<std::monostate, int, double, bool, std::string, KCallable*> getValue();

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
