#ifndef NUMERO
#define NUMERO
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

namespace Numeros{
	class Numero{
		private:
			string numero;
			int digitos;
			bool negativo;
			vector<string>unidades;
			vector<string>deuni;
			vector<string>decenas;
			vector<string>centenas;	
		//Funcion base tresDig
			string tresDig(string numero){
				int dig = numero.length();
				string nombre = "";
				bool deciuno = false;
				bool dece = false;
				for(auto num: numero){//num es de tipo char 
					//Para las centenas**************************************************+
					int n = num - '0';//No hace falta poner mucho texto con el static_cast<int>, podemos usar esto
					if (dig == 3){
						nombre += centenas[n] + " ";
						--dig;
					}
					//Para las decenas**************************************************+
					else if(dig == 2){
						if(n == 0){
							--dig;
							continue;
						}
						else if(n == 1)
							deciuno = true;
						
						else{
							nombre += decenas[n];
							dece = true;
						}
						
						--dig;	
					}
					//Para las unidades***********************************************+
					else if(dig == 1){
						if(deciuno){
							nombre += deuni[n];
							--dig;
							continue;
						}
						else if(n == 0)
							continue;
						else if(dece){
							nombre += " y " + unidades[n];
						}
						else
							nombre += unidades[n];
						
						--dig;
					}
				}
				return nombre;	
			}
		//Constructor con parametro entero
		public:
			Numero(int num){
				numero = to_string(num);
				if(numero[0] == '-'){
					numero = numero.substr(1);
					negativo = true;
				}
				else
					negativo = false;
				digitos = numero.length();
				inicializarNombre();
			}
		//Retornar el numero expresado como un string
			string masDig(){
				string numero = this->numero;
				string nombre = "";
				vector<string> grupos;
				int dig = digitos;
				if( dig <= 3)
					return tresDig(numero);
				else{
					int i;
					for(i = numero.length() - 3; i >= 0; i -= 3 ){
						string g = numero.substr(i,3);
						grupos.push_back(g);
					}
					grupos.push_back(numero.substr(0,i + 3));
				}
				reverse(grupos.begin(),grupos.end());
				int num_grupos = grupos.size();
				
				for(auto numero: grupos){

					if(num_grupos == 3 && !numero.empty()){
						nombre += tresDig(numero);
						nombre += " millones ";
					}					
					if(num_grupos == 2 && !numero.empty()){
						nombre += tresDig(numero);
						nombre += " mil ";
					}					
					if(num_grupos == 1){
						nombre += tresDig(numero);
						--num_grupos;
					}
					--num_grupos;
					
				}
				return nombre;		
			}
			//Sobrecarga de los operadores "+" "-" y "*"
			Numero operator +(Numero numero){
				int total = this->numeroInt() + numero.numeroInt();
				return Numero(total);
			}	
			
			Numero operator -(Numero numero){
				int total = this->numeroInt() - numero.numeroInt();
				return Numero(total);
			}		
			
			Numero operator *(Numero numero){
				int total = this->numeroInt() * numero.numeroInt();
				return Numero(total);
			}
			//Sobrecargando el operador << para mostrar el formato del numero directamente con cout
			friend ostream& operator <<(ostream& os,Numero numero){
				if(numero.esNegativo())
					os << "menos ";
				else if(numero.numeroInt() == 0)
					os << "cero" <<endl;
				else
				os << numero.masDig()<< endl; 
				return os;
			}
			bool esNegativo(){
				return negativo;
			}
			
			int numeroInt(){
				return stoi(numero);
			}
			
			//*********************************************************Para inicializar la representacion de los numeros
			void inicializarNombre(){
				string linea;
				vector<string> lista;
				ifstream archivo("Numeros.txt");
				if(archivo.is_open()){
					while(getline(archivo,linea)){
					lista.push_back(linea);
				}
				}
				archivo.close();
				//Repitiendo los mismos pasos que en Python
				vector<vector<string>> grupos;
				vector<string> grupoAct;
				for ( auto elemento: lista){
					if(elemento == "-"){
						grupos.push_back(grupoAct);
						grupoAct.clear();
						continue;
					}
					grupoAct.push_back(elemento);
				}
				if(!grupoAct.empty()){
					grupos.push_back(grupoAct);
				}
				unidades = grupos[0];
				deuni = grupos[1];
				decenas = grupos[2];
				centenas = grupos[3];		
			}					
	};
}
	
#endif