#include "StmtPrint.h"
#include "../KFunction.h"

StmtPrint::StmtPrint(Expression *expression) : expression(expression) {}

void StmtPrint::execute(Environment* environment) {
    TData data = expression->solve(environment);
    auto value = data.getValue();

    if(std::holds_alternative<std::monostate>(value)){
        std::cout<<"null"<<std::endl;
    }
    else if (std::holds_alternative<int>(value)) {
        std::cout<<std::get<int>(value)<<std::endl;
    }
    else if (std::holds_alternative<double>(value)) {
        std::cout<<std::get<double>(value)<<std::endl;
    }
    else if (std::holds_alternative<bool>(value)) {
        bool boolValue = std::get<bool>(value);
        std::cout<< (boolValue == 0 ? "false" : "true") <<std::endl;
    }
    else if (std::holds_alternative<std::string>(value)) {
        std::cout<<std::get<std::string>(value)<<std::endl;
    }
    else if (std::holds_alternative<KCallable*>(value)) {
        KCallable *callable = std::get<KCallable*>(value) ;
        if(dynamic_cast<KFunction*>(callable)){
            KFunction *function = dynamic_cast<KFunction*>(callable);
            std::cout<<function->toString()<<std::endl;
        }
    }
}
