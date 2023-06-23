#include <iostream>
#include <cstring>
#include <dirent.h>
using namespace std;
int main(){
    cout<<"Ingrese cadena a eliminar de nombre de archivos:";
    const char* directorio = "./";  // Especifica la ruta relativa al directorio
    string basura;
    cin >> basura;
    DIR* dir;
    struct dirent* entrada;

    dir = opendir(directorio);

    if (dir) {
        while ((entrada = readdir(dir)) != nullptr) {
            // Ignora las entradas "." y ".."
            if (strcmp(entrada->d_name, ".") != 0 && strcmp(entrada->d_name, "..") != 0) {
                string linea = entrada->d_name;
                if(linea.find(basura) != string::npos){
                    string nuevo = linea.substr(13,30);
                    rename(&linea[0],&nuevo[0]);
                }
            }
        }
        closedir(dir);
    }
}
