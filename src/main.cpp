#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
#include "Exceptions/ParserException.h"
#include "Exceptions/ScannerException.h"
#include "Semantic.h"
#include "Interpreter.h"
#include "Exceptions/SemanticException.h"
#include "Exceptions/NotImplementedYetException.h"
#include "Exceptions/RuntimeException.h"

void ejecutarArchivo(std::string, Interpreter*);
void repl(Interpreter*);
void ejecutar(std::string source, Interpreter*);

int main(int argc, char **argv) {
    if(argc > 2) {
        std::cout<<"Uso correcto: k [archivo.k]";

        // Convención defininida en el archivo "system.h" de UNIX
        exit(64);
    } else if(argc == 2){
        Interpreter *interpreter = new Interpreter();
        ejecutarArchivo(argv[1], interpreter);
    } else{
        Interpreter *interpreter = new Interpreter();
        repl(interpreter);
    }
}

void ejecutarArchivo(std::string path, Interpreter *interpreter) {

    std::ifstream fs{ path };
    std::string source((std::istreambuf_iterator<char>(fs)),
                    std::istreambuf_iterator<char>());
    ejecutar(source, interpreter);
}

void repl(Interpreter *interpreter) {
    std::string linea;
    for(;;) {

        std::cout << ">>";
        std::cout << " ";
        std::cin >> linea;
        if(!linea.empty()) {
            ejecutar(linea, interpreter);
        }
    }
}

void ejecutar(std::string source, Interpreter *interpreter){
    Parser parser = Parser(source);
    try {
        bool res = parser.parse();

        if(res){
            std::vector<Statement*> statements = parser.getStatements();

            Semantic resolver = Semantic(interpreter);
            resolver.analyse(statements);


            //interpreter.interpret(statements);
        }
    }
    catch (ScannerException e){
        std::cout<< e.what();
    }
    catch (ParserException e){
        std::cout<< e.what();
    }
    catch (SemanticException e){
        std::cout<< e.what();
    }
    catch (NotImplementedYetException e){
        std::cout<< e.what();
    }
    catch (RuntimeException e){
        std::cout<< e.what();
    }
}
