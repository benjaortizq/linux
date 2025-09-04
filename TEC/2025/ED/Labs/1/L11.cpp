//benchmark cola de prioridad 
#include <iostream>
#include <fstream>
#include <ctime>
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

int main() {
    string in ; 
    cin >> in ;
    ifstream archivo(in);
    string linea;
    SLL lista ; //crea nueva lsita 
    // Procesa el resto de líneas
    while (getline(archivo, linea)) {
        clock_t start = clock();
        if (linea[0] == 'V') {
            // Es un pop
            string resultado = lista.pop();
            clock_t end = clock();
            cout << resultado << endl;
            double elapsed = double(end - start) / CLOCKS_PER_SEC ;
            cout << "pop: " << elapsed << " segundos\n";

        } 
        else {
            // Es un add 
            size_t espacio = linea.find(' ');//
            string nombre = linea.substr(0, espacio); //nom,bre de la wea 
            int prioridad = stoi(linea.substr(espacio+1)); //
            lista.add(nombre, prioridad);
            clock_t end = clock();
            double elapsed = double(end - start) / CLOCKS_PER_SEC ;
            cout << "add: " << elapsed << " segundos\n";

        }
    } 
    // Cerrar el archivo
    archivo.close();
}