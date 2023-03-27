#ifndef LISTA
#define LISTA
#include <iostream>
using namespace std;

struct nodo{//estructura del nodo en donde se almacenara todos los datos de cada producto como su nombre,precio y cantidad
	string producto;
	int cantidad;
	float precio;
	nodo *siguiente;//Apuntador al siguiente nodo del nodo 
};


class Lista{
	public:
		Lista();//construtor
		bool buscar(const string&);//buscara en la lista apartir del nombre del producto
		void eliminar(const string&);//eliminara el elemento apartir del nombre del producto
		void insertar(const string&,float,int);//insertar un nuevo nodo a la lista con los elemento de cada nodo
		void imprimir()const;//Imprima todos los elementos de la lista
		bool vacia()const;//Verifica si la lista esta vacia o no
		int tam()const;//retorna el tamaño de la lista
		void destruirLista();//funcion para eliminar todos los elementos de la lista
		~Lista();//destructor de la clase lista la cual elimina todos los elementos de la lista
		
	private://elementos miembro de la clase lista
		nodo *primero;//un nodo para el primer nodo de la lista
		nodo *ultimo;//un nodo para el ultimo nodo de la lista
		int cont;//contador de la lista
};

void Lista::destruirLista()
{
	nodo *temp;//creamos un nodo temporal para eliminar nodo por nodo de la list
	while(primero != NULL)//mientras la lista no este vacia
	{
		temp = primero;//temporal apuntara a la direccion del primer nodo
		primero = primero->siguiente;//primero apuntara a su siguiente nodo
		delete temp;//primero ya no apunta al primer elemento entonces podemos usar delete sin problema
	}
	ultimo = NULL;//al eliminar todos lo nodo ultimo tiene que apuntar a nulo
	cont = 0;//y cont tiene que tener el valor de 0 que es el total de elementos en la lista
}

Lista::~Lista()//El destructor simplemente usa la funcion para destruir la lista
{
	destruirLista();
}

Lista::Lista()//La lista se inicializara siempre de la misma manera
{
	primero = NULL;//con primero 
	ultimo = NULL;//ultimo siempre apuntando a null 
	cont = 0;//y el contador con 0
}

bool Lista::buscar(const string& item)//la funcion buscar tiene un parametro el cual es una cadena con la cadena a buscar
{
	bool encontrado = false;//supondremos que no hemos encontrado al element
	nodo *actual = primero;//tendremos un nodo actual apuntando al primero elemento
	while(actual != NULL)//si la lista no esta vacia
	{
		if(actual->producto == item)//si la cadena del nombre del producto del nodo actual es igual a la cadena buscada
		{
			encontrado = true;//lo hemos encontrado
			break;//y saldremos del bucle
		}
		actual = actual->siguiente;//en caso de no encontrarlo simplemente apuntaremos a actual a su siguiente nodo
	}	
	return encontrado;//retornaremo si lo hemos encontrado o no
}

void Lista::eliminar(const string& item)//funcion para eliminar un elemento de la lista
{
	bool encontrado = false;//supondremos que no hemos encontrado el elemento
	nodo *actual,*anterior,*temp;//usaremos un elemento actual, uno anterior al actual y un temporal
	if(primero == NULL)//Si primero apunta a null significa que esta vacia
		cout<<"Lista vacia"<<endl;
	else//si no
	{
		if(primero->producto == item)//si el elemento buscado es el primero
		{
			actual = primero;//actual apuntara a primero 
			primero = primero->siguiente;//primero al su siguiente nodo
			--cont;//disminuimos al cont en 1
			delete actual;//borramos a actul ya que primero no apunte al primer elemento
			if(primero == NULL)//si despues de eliminar este nodo primero apunta a nulo
				ultimo = NULL;//ultimo apuntara a null significando que la lista esta vacia
		}
		else//y si el elemento buscado no esta en el primer nodo
		{
			actual = primero->siguiente;//actual apuntara al nodo siguiente de primero
			anterior = primero;//anterio al primero
			while(actual != NULL && encontrado != true)
			{
				if(actual->producto == item)
					encontrado = true;
				else
				{
					anterior = actual;
					actual = actual->siguiente;
				}
			}
			if(encontrado)
			{
				--cont;
				anterior->siguiente = actual->siguiente;
				if(ultimo == actual)
				{
						ultimo = anterior;
				}
				delete actual;
			}
		}

				
	}
}

void Lista::insertar(const string&item,float p,int c)
{
	nodo *nuevoNodo;
	nuevoNodo = new nodo;
	nuevoNodo->producto = item;
	nuevoNodo->precio = p;
	nuevoNodo->cantidad = c;
	nuevoNodo->siguiente = primero;
	primero = nuevoNodo;
	++cont;
	if(ultimo == NULL)
		ultimo = nuevoNodo;
}

void Lista::imprimir()const
{
	nodo *actual;
	actual = primero;
	if(actual == NULL)
		cout<<"Lista vacia";
	else
	{
		cout<<"Producto->\t";
		while(actual != NULL)
		{
			cout<<actual->producto<<"\t";
			actual = actual->siguiente;
		}
		cout<<endl;
		actual = primero;
		cout<<"Precio->\t";
		while(actual != NULL)
		{
			cout<<actual->precio<<"\t";
			actual = actual->siguiente;
		}	
		actual = primero;
		cout<<endl;
		cout<<"Cantidad->\t";
		while(actual != NULL)
		{
			cout<<actual->cantidad<<"\t";
			actual = actual->siguiente;
		}	
	}
}
bool Lista::vacia()const
{
	if(primero == NULL)
	return true;
	else
	return false;
}

int Lista::tam()const
{
	return cont;
}

#endif
