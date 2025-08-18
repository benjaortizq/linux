#include <iostream>
using namespace std;
// Nodo para la lista doblemente enlazada
class Node {
public:
    int id;       // ID interno
    int value;    // Valor real del nodo
    int indegree; // Indegree del nodo
    Node* next;   // Siguiente en la lista , va a aputnar a otro nodo 
    Node* prev;   // Anterior en la lista , va a apuntar a otro nodo 
    Node* adj;    // Lista de adyacencia , la 

    Node( int _value) {
        value = _value;
        indegree = 0;
        next = nullptr;
        prev = nullptr;
        adj = nullptr;
    }
};

// Lista doblemente enlazada
class DLL {
public:
    Node* head;
    Node* tail;
    int size;

    DLL() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Insertar al final
    void push_back(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
    }

    // Remover un nodo
    void remove(Node* node) {
        if (node == head) head = node->next;
        if (node == tail) tail = node->prev;
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        node->next = node->prev = nullptr;
        size--;
    }

    // Insertar nodo en lista de adyacencia
    void add_edge(Node* from, Node* to) {
        Node* edge = new Node(to->value);
        edge->next = from->adj;
        from->adj = edge;
        to->indegree++;
    }

    Node* find_or_create(int value) {
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        if (curr->value == value) return curr;
    }
    // No existe, crear nuevo
    Node* new_node = new Node(value);
    push_back(new_node);
    return new_node;
    }
};

class MinHeap {
private:
    Node** arr; // Array de punteros a nodos
    int capacity;
    int heap_size;
    
    // Funciones auxiliares
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
    
    void heapify_up(int i) {
        while (i > 0 && arr[parent(i)]->value > arr[i]->value) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    
    void heapify_down(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);
        
        if (l < heap_size && arr[l]->value < arr[smallest]->value)
            smallest = l;
        
        if (r < heap_size && arr[r]->value < arr[smallest]->value)
            smallest = r;
        
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify_down(smallest);
        }
    }
    
public:
    MinHeap(int cap) {
        heap_size = 0;
        capacity = cap;
        arr = new Node*[cap];
    }
    
    ~MinHeap() {
        delete[] arr;
    }
    
    bool empty() { return heap_size == 0; }
    
    Node* extract_min() {
        if (heap_size <= 0)
            return nullptr;
        
        Node* root = arr[0];
        arr[0] = arr[heap_size-1];
        heap_size--;
        heapify_down(0);
        
        return root;
    }
    
    void insert(Node* node) {
        if (heap_size == capacity)
            return;
        heap_size++;
        int i = heap_size - 1;
        arr[i] = node;
        heapify_up(i);
    }
};

int main (){
    int n,m ;
    cin >> n >> m;
    DLL lista; // Crear la lista doblemente enlazada para el grafo
    for (int i =0 ; i< m ; i++) { 
        int a , b;
        cin >> a >> b;
        Node* from = lista.find_or_create(a);
        Node* to = lista.find_or_create(b);
        lista.add_edge(from, to);
        }
    int node_count = 0;
    for (Node* node = lista.head; node != nullptr; node = node->next) {
        node_count++;
    }
    
    MinHeap ready(node_count) ; //creaacion del arbol para busqueda de nodos con id 0 , ademas de orden lexicograficamente minimo 
    for (Node* node = lista.head; node != nullptr; node = node->next) {
        if (node->indegree == 0) {
            ready.insert(node);
        }
    }
    DLL result ; 
    int processado = 0 ; 
    while (!ready.empty()) { //mientras no este vacio minheap 
        Node* current = ready.extract_min();    //funcion extraer minimo para nodo con id 0 y lexicograficamente minimo
        result.push_back(new Node(current->value));  // Crear nuevo nodo
        processado++;       //+1 porocedaso 
        Node* adj = current->adj;
        while (adj != nullptr) {
            for (Node* node = lista.head; node != nullptr; node = node->next) {
                if (node->value == adj->value) {
                    node->indegree--;
                if (node->indegree == 0) {
                        ready.insert(node);
                    }
                        break;
                    }
                }
                adj = adj->next;
            }
        }
    
    // Verificar ciclo
    if (processado < lista.size) {
        cout << "El grafo tiene ciclos" << endl;
    } else {
        for (Node* node = result.head; node != nullptr; node = node->next) {
            cout << node->value << " ";
        }
        cout << endl;
    }
}
        

