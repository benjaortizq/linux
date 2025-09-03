//!este que viene es bonitamente jodido ; osea una skipped list 
#include <iostream>
using namespace std ; 

class Node { 
    public: 
    Node* next ; 
    Node* down ; 
    int pr ;
    string name; 
} ;
class SLL{
    public :
    Node* head ;
    void add ( string nombre, int prio) ;
    string pop ();
    SLL(){
        head= nullptr ;
    }
};

void SLL::add (string nombre , int prio ) { //!o(n)
    //revisar si la prioridad de lo que quiero insertar es menor a la del actual, tons se que debo continuar. sino entonces se que va antes del actual. 
    Node *ins = new Node; 
    ins->pr = prio; 
    ins->name= nombre ;
    ins->next= nullptr;
    //*caso 1 : lista vacia 
    if (head==nullptr) { 
        head = ins;
        return ;
    }
    //*caso 2 ; lista tamano>=1
    Node*act= head ; 
    //soy mayor al primero  : 
    if (act ->pr < prio ){  //insertar al inicio
        ins->next = act ; 
        head = ins ; 
        return ;
    }
                
    while (act->next !=nullptr ) {// si es igual jala despues , solamente me fijo en el siguiente si existe y que sea menor y no es el ultimo elemento 
        if (act->next->pr < prio) {  //mi prioridad es mayor a la del siguiente ?, se que es menor que el actual
            ins->next = act->next ; 
            act->next = ins ; 
            return ; 
        }
        act=act->next;
    }
    //insertar de ultimo 
    act ->next = ins;
    return ;
}

string SLL::pop() {  //!O(1)
    if (head== nullptr ) { 
        return "";
    }
    Node*act= head ; 
    string tmp ;
    //tamano 1 
    if (act ->next == nullptr) { 
        head = nullptr;
    }
    else{
        head = act->next; 
        act->next = nullptr ; }
    tmp = act->name;
    delete act;
    return tmp;
}

//aq
class SKL{ 
    //tiene una arreglo de listas una picha asi
    int K ;  //cantidad de niveles 
    int P ; //ramdomizer 
    //puedo tener una lsita que tenga como valor de nodos a otra la Sll , o puedo tener el arreglo como tal xd , que no se como putas accesar cada lista por tal . si, es un arreglo pero qwea con el tamano
    
    SKL(int k, int p ){
        K = k ;
        P=p;
        SLL hello [K] ; 
    };

};