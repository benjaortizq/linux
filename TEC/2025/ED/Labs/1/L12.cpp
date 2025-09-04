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
    int Hl = 0 ; //nivel mas alto 

    SKL(int k, int p) {
        K = k; //cantidad de niveles
        P = p; //probabilidad
        levels = new SLL[K]; // ahora FUNCA
    }
    void SKL::add(string val, int prio) {
    Node* down_node = nullptr;
    for (int lvl = 0; lvl < K; ++lvl) {
        if (lvl == 0 || random(P)) {
            Node* new_node = new Node();
            new_node->name = val;
            new_node->pr = prio;
            new_node->down = down_node;
            new_node->next = nullptr;
            levels[lvl].add(val, prio);
            // Buscar el nodo recién insertado en el nivel actual
            Node* curr = levels[lvl].head;
            while (curr && curr->name != val) curr = curr->next;
            if (curr) curr->down = down_node;
            down_node = curr;
            Hl = max(Hl, lvl);
        } else {
            break;
        }
    }
}
        
};


