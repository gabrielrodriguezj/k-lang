#ifndef K_LANG_KDATA_H
#define K_LANG_KDATA_H


#include <variant>
#include <string>
#include "KCallable.h"

class KData {
private:
    std::variant<std::monostate, int, double, bool, std::string, KCallable*> value;
public:
    explicit KData(const std::variant<std::monostate, int, double, bool, std::string, KCallable*> &value);
    explicit KData();
    std::variant<std::monostate, int, double, bool, std::string, KCallable*> getValue();

    // Sobrecarga de operadores
    KData operator - ();
    KData operator ! ();

    KData operator + (KData&);
    KData operator - (KData&);
    KData operator * (KData&);
    KData operator / (KData&);

    KData operator < (KData&);
    KData operator <= (KData&);
    KData operator > (KData&);
    KData operator >= (KData&);
    KData operator != (KData&);
    KData operator == (KData&);

    KData operator || (KData&);
    KData operator && (KData&);
};


#endif //K_LANG_KDATA_H
