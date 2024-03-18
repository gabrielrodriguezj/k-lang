#include <iostream>
#include <fstream>
#include <string>

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

    std::cout<<source;

    ejecutar(source);
}

void repl() {
    std::string linea;
    for(;;) {

        std::cout << ">>";
        std::cout << " ";
        std::cin >> linea;
        if(!linea.empty()) {
            // std::cout<< linea <<std::endl;
            ejecutar(linea);
        }

    }
}

void ejecutar(std::string source){
    //Token t = Token(NombreToken::LEFT_PAREN, "and");
    //std::cout << t;
}
