//benchmark cola de prioridad 
#include <iostream>
using namespace std;

//todo : Crear una cola de prioridad con/ SLL

class Node  { 
    public: 
    Node* next ; 
    int pr ; 
    string name ; 
};

class SLL{
    public :
    int size ;
    Node* head ;

    void insertar ( string nombre, int prio) ;
    void pop ();

};

void SLL::insertar (string nombre , int prio ) { //!o(n)
    //revisar si la prioridad de lo que quiero insertar es menor a la del actual, tons se que debo continuar. sino entonces se que va antes del actual. 
    Node *ins = new Node; 
    ins->pr = prio; 
    ins->name= nombre ;
    ins->next= nullptr;
    //*caso 1 : lista vacia 
    if (head==nullptr) { 
        head = ins;
        size ++ ;
        return ;
    }
    //*caso 2 ; lista tamano>=1
    Node*act= head ; 
    //soy mayor al primero  : 
    if (act ->pr < prio ){  //insertar al inicio
        ins->next = act ; 
        head = ins ; 
        size++;
        return ;
    }
                
    while (act->next !=nullptr ) {// si es igual jala despues , solamente me fijo en el siguiente si existe y que sea menor y no es el ultimo elemento 
        if (act->next->pr < prio) {  //mi prioridad es mayor a la del siguiente ?, se que es menor que el actual
            ins->next = act->next ; 
            act->next = ins ; 
            size++;
            return ; 
        }
        act=act->next;
    }
    //insertar de ultimo 
    act ->next = ins;
    size++;
    return ;


