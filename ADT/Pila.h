//Pila
#ifndef PILA
#define PILA

template <class T>
struct  nodo{
	T inf;
	nodo<T> *sig;
	nodo<T> *ant;
};
template <class T>
class Pila{
	private:
		nodo<T> *primero;
		nodo<T> *ultimo;
		int tam;
	public:
		Pila(){
			primero = nullptr;
			ultimo = nullptr;
			tam = 0;
		}
		bool vacia(){
			return (primero == nullptr && ultimo == nullptr);
		}
		void push(T elem){
			nodo<T> *nuevo = new nodo<T>;
			nuevo->inf = elem;
			nuevo->sig = nullptr;
			nuevo->ant = nullptr;
			if(vacia()){
				primero = nuevo;
				ultimo = nuevo;
			}
			else{
				ultimo->sig = nullptr;
				nuevo->ant = ultimo;
				ultimo = nuevo;
			}
			++tam;
		}
		T top(){
			return ultimo->inf;
		}
		T pop(){
			nodo<T> *temp;
			temp = ultimo;
			T tempDato = temp->inf;
			if(ultimo == primero){
				ultimo = nullptr;
				primero = nullptr;
			}
			else{
				ultimo = ultimo->ant;
				ultimo->sig = nullptr;
			}

			delete temp;
			--tam;
			return tempDato;
		}
		int size(){
			return tam;
		}

};
//BY KINLO_SAMA :3
#endif