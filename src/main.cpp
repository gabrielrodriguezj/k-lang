#include <iostream>
#include <fstream>
#include <string>

void ejecutarArchivo(std::string path);
void repl();
void ejecutar();
char* readFile(std::string);

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

    //ejecutar();
}

void repl() {
    std::string linea;
    for(;;) {

        std::cout << ">>";
        std::cout << " ";
        std::cin >> linea;
        if(!linea.empty()) {
            // std::cout<< linea <<std::endl;
            ejecutar();
        }

    }
}

void ejecutar(){
    //Token t = Token(NombreToken::LEFT_PAREN, "and");
    //std::cout << t;
}

char* readFile(std::string path){
    std::ifstream ifs;
    int length;
    ifs.open(path);                     // Abrir el archivo
    ifs.seekg(0, std::ios::end);            // Mover hasta el final
    length = ifs.tellg();                   // Reportar la ubicación (en este caso es el final del archivo)
    ifs.seekg(0, std::ios::beg);            // Volver al inicio del archivo
    char *buffer  = new char[length + 1];    // Asignar suficiente memoria para el buffer
    ifs.read(buffer, length);           // Leer el archivo y colocarlo completo en el buffer
    ifs.close();                            // Cerrar el manejador
    buffer[length] = '\0';                  // Colcocar el fin de cadena
    //std::cout<<buffer;

    return buffer;
}
