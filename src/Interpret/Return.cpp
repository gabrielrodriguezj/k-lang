#include "Return.h"

Return::Return(const std::string & message, TData value) : message(message), value(value) {

}

const char *Return::what() const throw() {
    return exception::what();
}

TData Return::getValue(){
    return value;
}
