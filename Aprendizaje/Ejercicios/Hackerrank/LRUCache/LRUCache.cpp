//Termine al fin este problema :)
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache{
    public:
        LRUCache(int c){
            cp = c;
            tail = nullptr;
            head = nullptr;
        }
        void set(int k,int v){
        //Para empezar tenemos tres casos y la verificacion si ya existe dentro del mapa
        Node *nodo = new Node(k,v);
        if(mp.count(k)== 1){//En caso de ya existir la lleva
            mp[k] = nodo;//Solo actualizamos su value o valor
            return;//Y salimos de la funcion con un return para evitar las otras condiciones
        }
        if(mp.size() == 0){//Si la lista esta vacia
            head = nodo;
            tail = nodo;
            mp[k] = nodo;
        }
        else if(mp.size() < cp){//Si aun no llenamos con su maxima capacidad
            Node *newHead = head;//Pondremos los nodos de derecha a izquierda por ejemplo
            newHead->prev = nodo;//nodo_n,nodo_(n-1),...n_2,n_1 el menos significado sera el n_1
            nodo->next = newHead;
            nodo->prev = nullptr;
            head = nodo;
            mp[k] = nodo;
        }
        else if(mp.size() >= cp){//Si llegamos a la capacidad maxima
            Node *antTail = tail->prev;
            Node *finalNodo = tail;
            int keyTail = tail->key;
            if(mp.size() == 1){
                tail = nullptr;
                head = nullptr;
            }else{
                antTail->next = nodo;
                tail = nodo;
            }
            delete finalNodo;//Eliminamos el nodo final el menos significativo
            mp.erase(keyTail);//borramos el nodo en la llave encontrada al final
            mp[k] = nodo;//Actualizamos con el nuevo nodo
        }
        }

        int get(int k){//Para obtenerlo es sencillo solo con la clase
            if(mp.count(k) != 0){//Comprobamos si exite dicha llave
                return mp[k]->value;//Si es asi entonces simplemente retornamos el nodo en esa llave y su valor
            }
            return -1;//en caso de no encontrar la llave
        }


};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
