#include "Return.h"

Return::Return(const std::string & message, KData value) : message(message), value(value) {

}

const char *Return::what() const throw() {
    return exception::what();
}

KData Return::getValue(){
    return value;
}
