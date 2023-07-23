#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
//La resolucion del problema lo encontre en el foro de discusion, realizo la explicacion a fondo para mejorar mi
//entendimiento sobre el codigo, ya saben ejercitando :)
int main(){
    //Almacenamos la cantidad N de lineas de codigo y Q consultas
    int N,Q;
    cin>>N>>Q;
    //Utilizaremos un vector de strings para almacenar las etiquetas
    vector<string> etiquetas;
    //Un diccionario o mapa para almacenar las asignaciones
    unordered_map<string,string>mapa_etiquetas;
    //Un string linea para almacenar una linea,prefijo para almacenar la etiqueta de la linea
    string linea,prefijo;
    //Tenemos que desasernos del espacio en blanco del cin
    getline(cin,linea);
    //Primero iteraremos por las N lineas de codigo
    for(int i = 0; i < N;++i){
        //Leemos la linea i
        getline(cin,linea);
        //Borramos los caracteres "<" y ">" con el metodo erase de string
        linea.erase(linea.end() - 1);//Borramos primero el ">" que se encuentra al final de la linea
        linea.erase(linea.begin(),linea.begin() + 1);//Eliminamos el "<" que se encuentra en la primera posicion
        //Ahora verificamos si la linea no es el final de la etiqueta verificando si tiene un "/" al incio
        if(linea[0] == '/'){//Si es asi entonces continuamos al siguiente **************************************************************
            linea.erase(linea.begin(),linea.begin() + 1);
            etiquetas.pop_back();//Cuando llegamos a </tag_n> damos por terminada la definicion de la etiqueta
            continue;
        }
        //Ahora remplazamos cada "=" y "\"" por espacios en blanco usando el metodo replace()
        replace(linea.begin(),linea.end(),'=',' ');//Desde el inicio al final replazamos "=" por " "   <-Como leer el metodo
        replace(linea.begin(),linea.end(),'\"',' ');//Desde el inico al final remplazamos "\"" por " " <-Como leer el metodo
        //Hasta este punto nos quedaria la siguiente estructura
        //etiqueta atributo valor atributo valor atributo valor ...
        //Con la ayuda de un stringstream obtendremos primero la etiqueta
        stringstream flujo(linea);
        //El cual sera almacenado en un string temporal prefijo
        string prefijo;
        flujo >> prefijo;
        //Almacenamos la etiqueta en el vector de etiquetas
        etiquetas.push_back(prefijo);
        //Ahora haremos un anidamiento de etiquetas
        string temp;
        for(auto &elemento:etiquetas)
            temp = temp + "." + elemento;//Al final nos quedara la siguiente estructura .tag1.tag2.tag3...tagn
        string llave,valor;
        //Con base al anidamiento añadiremos un "~" y su atributo como la llave y su valor con base al flujo
        while(flujo){//Mientras alla elementos en la linea
            flujo >> llave >> valor;
            mapa_etiquetas[temp + "~" + llave] = valor;//Lo que se veria asi .tag1.tag2...tagn~atributo = valor
        }
    }
    //Ahora que ya lo tenemos mapeado sera sencillamente buscar por las consultar
    vector<string>resultados;
    for(int i = 0; i < Q;++i){
        getline(cin,linea);
        linea = "." + linea;
        if(mapa_etiquetas.count(linea) == 1)
            resultados.push_back(mapa_etiquetas[linea]);
        else
            resultados.push_back("Not Found!");
    }
    for(auto elemento:resultados)
        cout<<elemento<<endl;
}
