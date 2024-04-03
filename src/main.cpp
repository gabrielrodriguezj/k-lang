#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
#include "Exceptions/ParserException.h"
#include "Exceptions/ScannerException.h"
#include "Exceptions/RuntimeException.h"

void ejecutarArchivo(std::string path);
void repl();
void ejecutar(std::string source);

int main(int argc, char **argv) {
    if(argc > 2) {
        std::cout<<"Uso correcto: k [archivo.k]";

        // Convención defininida en el archivo "system.h" de UNIX
        exit(64);
    } else if(argc == 2){
        ejecutarArchivo(argv[1]);
    } else{
        repl();
    }
}

void ejecutarArchivo(std::string path) {

    std::ifstream fs{ path };
    std::string source((std::istreambuf_iterator<char>(fs)),
                    std::istreambuf_iterator<char>());
    ejecutar(source);
}

void repl() {
    std::string linea;
    for(;;) {

        std::cout << ">>";
        std::cout << " ";
        std::cin >> linea;
        if(!linea.empty()) {
            ejecutar(linea);
        }
    }
}

void ejecutar(std::string source){
    Parser parser = Parser(source);
    try {
        bool res = parser.parse();

        if(res){
            Environment* globalEnvironment = new Environment(nullptr);
            std::list<Statement*> statements = parser.getStatements();
            for(Statement* statement : statements){
                statement->execute(globalEnvironment);
            }
        }
    }
    catch (ParserException e){
        std::cout<< e.what();
    }
    catch (ScannerException e){
        std::cout<< e.what();
    }
    catch (RuntimeException e){
        std::cout<< e.what();
    }
}
