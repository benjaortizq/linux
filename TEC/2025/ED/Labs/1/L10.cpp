#include <iostream>
using namespace std;
//creacion de clase vector (con DLL )

class Node {
    public : 
    int val ; // Valor del nodo
    Node* next; // Siguiente nodo en la lista
    Node* prev; // Nodo anterior en la lista
};

class Vector {          //para no hacer tanto despelote, class vector funciona igual que una dll , solo que se llama vector xd 
    private : 
    int  capacidad_max ;
    public :
    Node* head; // Cabeza de la lista
    Node* tail; // Cola de la lista 
    int tamano ;
    Vector() { //creador
        head = nullptr;
        tail = nullptr;
        capacidad_max = 2147483647; //capacidad por defecto
        tamano = 0;
    }
    Vector (int cap) { //creador con capacidad
        head = nullptr;
        tail = nullptr;
        capacidad_max = cap;
        tamano = 0;
    }
    int size(); //funcion para obtener el tamaño actual de la lista
    int max_size(); //funcion para obtener la capacidad maxima de la lista
    void resize(int n); //funcion para redimensionar la lista
    int at(int n); // devuelve elemento en N posicion
    int&  operator[]( int index) ;


};

int Vector::size() {
        return tamano;}
int Vector::max_size(){
        return capacidad_max;}
void Vector::resize(int n) { //cambia el tamano maximo por el de entrada si cantidad de elementos del vector es menor o igual a entrada
    ((tamano >= n)? capacidad_max = n : 0 ); //cambia max por n si n mayor a size actual , sino no hace nada
    return ;
}

int Vector:: at(int n ){
    int valor = at (n);
    return valor ;
    Node* actual = head ; 
    for (int i=0; i< n; i++){
        actual= actual-> next;
    }
    return actual ->val ; 
    

};

int& Vector::operator[] (int index){ //no hay que hacer validacion de entradas, voya  ahcerlop supoiniendo que entrada es >=0 y que el tamano de la lista siempre va a ser mayor o igual al de la entrada 
    int valor = at (index ) ; 
    return valor ; 
}



//tener en cuenta que -> es como el :: pero en punteros 

//eliminacion de dll por vector . funciona igual que una dll 