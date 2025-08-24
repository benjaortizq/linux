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
    ;
    public :
    Node* head; // Cabeza de la lista
    Node* tail; // Cola de la lista 
    int tamano ;
    int  capacidad_max ;
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
    int front(); //*done
    int back(); //*done
    void push_back(int n );//!hacer
    int pop_back ();//!hacer
    void insert (int pos , int n );
};

int Vector::size() {
        return tamano;}
int Vector::max_size(){
        return capacidad_max;}
void Vector::resize(int n) { //cambia el tamano maximo por el de entrada si cantidad de elementos del vector es menor o igual a entrada
    ((tamano >= n)? capacidad_max = n : 0 ); //cambia max por n si n mayor a size actual , sino no hace nada
    return ;
}

int Vector:: at(int n ){//no hay que hacer validacion de entradas, voya  ahcerlop supoiniendo que entrada es >=0 y que el tamano de la lista siempre va a ser mayor o igual al de la entrada 
    //!aqui ocurre un ostio que es que si la lista esta vacia, se queda mamando ya que head aputna a un nodo pero este nodo no existe . PONER UN IF NULLPOINTER  
    Node* actual = head ; 
    if (tamano==0 ) {
        return -1;
    };
    for (int i=0; i< n; i++){
        actual= actual-> next;
    }
    return actual ->val ; 
    

};

int& Vector::operator[] (int index){ //llama al de arriba xd . quedaria chuzo hacerlo en una sola linea pero no es python tons toco en 2 >:C
    int valor = at (index ) ; 
    return valor ; 
} 

int Vector:: front() {
    return at(0);
}

int Vector::back() {
    return (tamano > 0 ) ? at(tamano-1) : at(0);
}

void Vector::insert (int pos , int n ) {
    Node *current = head ;
    for (int i ; i< pos ; i++) { 
        current = current -> next ; 
    };
    current-> val = n ;
}




//! en cuenta que -> es como el :: pero en punteros 

//eliminacion de dll por vector . funciona igual que una dll pero se llama vector xd 


