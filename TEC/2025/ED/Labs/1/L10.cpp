#include <iostream>
using namespace std;
//creacion de clase vector (con DLL )

class Node {
    public : 
    int val ; // Valor del nodo
    Node* next; // Siguiente nodo en la lista
    Node* prev; // Nodo anterior en la lista
};

class DLL {
    public :
    Node* head; // Cabeza de la lista
    Node* tail; // Cola de la lista 
    DLL() { //creador
        head = nullptr;
        tail = nullptr;
    }

    int size() {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    };
    int max_size(){
        int tamano = size() ;
        return (tamano  < 0) ? (tamano) :  2147483647 ;
    }

};
