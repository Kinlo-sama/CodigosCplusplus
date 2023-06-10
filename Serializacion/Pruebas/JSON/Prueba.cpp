#include <iostream>
#include <fstream>
#include <json/json.h>

int main() {
    Json::Value root;
    Json::Value datos;

    datos["nombre"] = "Juan";
    datos["edad"] = 30;
    datos["ciudad"] = "Ciudad de México";

    root["datos"] = datos;

    Json::StreamWriterBuilder writer;
    writer["indentation"] = "\t";
    std::string jsonString = Json::writeString(writer, root);

    std::ofstream file("datos.json");
    file << jsonString;
    file.close();

    std::cout << "Archivo JSON creado exitosamente." << std::endl;

    return 0;
}
