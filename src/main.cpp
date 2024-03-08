#include <iostream>
#include <fstream>
#include <string>

void ejecutarArchivo(std::string path);
void ejecutarPrompt();

int main(int argc, char **argv) {
    if(argc > 2) {
        std::cout<<"Uso correcto: k [archivo.k]";

        // Convención defininida en el archivo "system.h" de UNIX
        exit(64);
    } else if(argc == 2){
        ejecutarArchivo(argv[1]);
    } else{
        ejecutarPrompt();
    }
}

void ejecutarArchivo(std::string path) {
    std::string line;
    std::ifstream file (path);
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            std::cout << line << '\n';
        }
        file.close();
    }

    else std::cout << "Unable to open file";
}

void ejecutarPrompt() {
    std::string linea;
    for(;;) {

        std::cout << ">>";
        std::cout << " ";
        std::cin >> linea;
        if(!linea.empty()) {
            std::cout<< linea <<std::endl;
        }

    }
}

void ejecutar(){

}
