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

bool random(double pos) {
    double r = (double)rand() / RAND_MAX;
    return r < pos; }
class SKL { 
public:
    int K;  // niveles
    double P;  // randomizer
    SLL* levels; // arreglo de SLL
    int Hl = 0 ; //nivel mas alto que tiene nodo 

    SKL(int k, int p) {
        K = k; //cantidad de niveles
        P = p; //probabilidad
        levels = new SLL[K]; // ahora FUNCA
    }
    void add(string val, int prio);
    string SKL::pop();
        
};

void SKL::add(string val, int prio) {
    // Arreglo para guardar los nodos donde se hace iuns
    Node* update[K];
    
    // Empezar desde mas alto 
    Node* curr = nullptr;
    for (int lvl = Hl; lvl >= 0; lvl--) {
        if (lvl == Hl) {
            curr = levels[lvl].head;  // Solo en el nivel más alto empezamos desde el principio
        } else if (!curr || !curr->down) {
            // Si no hay nodo actual o no tiene bajada, empezar desde donde quedamos en el nivel anterior
            // y buscar el punto de entrada en este nivel
            Node* prev = nullptr;
            Node* temp = levels[lvl].head;
            while (temp && temp->pr >= curr->pr) {
                prev = temp;
                temp = temp->next;
            }
            curr = prev ? prev : levels[lvl].head;
        } else {
            curr = curr->down;  // Bajar al siguiente nivel desde donde estamos
        }
        
        // Avanzar en este nivel mientras sea necesario
        while (curr && curr->next && curr->next->pr > prio)
            curr = curr->next;
        
        update[lvl] = curr;
}
    
    // Decidir hasta donde incertar
    int new_level = 0;
    while (new_level < K-1 && random(P))
        new_level++;
        
    // Actualizar Hl si es necesario
    if (new_level > Hl) {
        for (int i = Hl+1; i <= new_level; i++)
            update[i] = nullptr;
        Hl = new_level;
    }
    
    Node* down_ptr = nullptr;
    for (int lvl = 0; lvl <= new_level; lvl++) {
        Node* new_node = new Node();
        new_node->name = val;
        new_node->pr = prio;
        
        if (update[lvl] == nullptr) {
            new_node->next = levels[lvl].head;
            levels[lvl].head = new_node;
        } else {
            new_node->next = update[lvl]->next;
            update[lvl]->next = new_node;
        }
        
        new_node->down = down_ptr;
        down_ptr = new_node;
    }
}

string SKL::pop() {
    if (Hl < 0) return "";
    string result = levels[Hl].pop();
    // Actualiza Hl si vacio
    while (Hl >= 0 && levels[Hl].head == nullptr) Hl--;
    return result;
}