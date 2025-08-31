#include <iostream>
using namespace std;

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
    int pop_back ();
    void insert (int pos , int n );
    void erase(int pos);
    void swap(int n , int m);
    void print();
};

int Vector::size() {
        return tamano;}

int Vector::max_size(){
        return capacidad_max;}

void Vector::resize(int n) { //cambia el tamano maximo por el de entrada si cantidad de elementos del vector es menor o igual a entrada
    if (tamano <= n) capacidad_max = n; //cambia max por n si n mayor a size actual , sino no hace nada
    return ;
}

int Vector:: at(int n ){//no hay que hacer validacion de entradas, voya  ahcerlop supoiniendo que entrada es >=0 y que el tamano de la lista siempre va a ser mayor o igual al de la entrada 
    //!aqui ocurre un ostio que es que si la lista esta vacia, se queda mamando ya que head aputna a un nodo pero este nodo no existe . PONER UN IF NULLPOINTER  
    if (tamano==0 ) {
        return -1;
    };
    Node* actual = head ; 
    for (int i=0; i< n; i++){
        actual= actual-> next;
    }
    return actual ->val ; 
    

};

int& Vector::operator[] (int index){ //devuelve referencia al valor en el nodo en la posición index
    Node* actual = head;
    for (int i = 0; i < index; i++) actual = actual->next;
    return actual->val; }

int Vector:: front() { //poco sucio pero se pude hcer mas eficiente creo
    return at (0) ;
}

int Vector::back() {
    return (tamano > 0 ) ? at(tamano-1) : at(0);
}

void Vector::insert (int pos , int n ) { //!este es un despiche . COMO ES INSERTAR SIEMPRE SE VA A TENER QUE TENER UN NODO NUEVO Y TAMANO ++ 
    Node*nuevo=  new Node ; 
    nuevo->val= n ;
    if (head== nullptr) { //vacia ,head solo apunta a nada cuando tamano = 0 , como tamano no puede ser 0 tons ta bien 
        head=tail=nuevo;
        tamano++; //importantisimo
        return ;
    }
    Node *current = head ;
    if (tamano < capacidad_max ) {//si es menor si puedo 
        for (int i =0 ; i<pos  ; i++) { //recorre hasta llegar a N -1 de ser el caso 
            if (current->next== nullptr) { 
                break;}
            current = current->next ;
        }
        if (pos ==0 ){  //tamano >=1 
            nuevo ->next = current ;
            current->prev = nuevo ;
            head = nuevo ;
        }
        else if (pos < tamano-1) {  //tamano >=2 
            Node * sig_curr = current ->next;
            nuevo->next= sig_curr ;
            nuevo ->prev = current;
            current ->next = nuevo ; 
            sig_curr ->prev = nuevo ; 
        }
        else {
        tail = nuevo ;  //si no es ninguna de las dos , se inserta al final siempre tons 
        current->next = nuevo ;
        nuevo->prev = current ;
        nuevo->val = n ;
        }
        tamano++; //lo sque para que viva una vida libre sin prejuiciso de los Ifs 
    }
}

void Vector::push_back (int n ){  //se puede hacer mas divertido sin usar insert  
    insert (tamano, n ); //inserta al final de la lista 
}

void Vector::print() { 
    if (head == nullptr) {
        cout <<endl;
        return ;
    } //tamano 0 muerto
    Node* actual= head  ; 
    for (int i = 0 ; i < tamano ; i++ ) { 
        cout <<actual->val << " "; 
        actual = actual->next;
    }
    cout <<endl; 
}

int Vector::pop_back() {
    if (tail == nullptr) return -1;
    int valor = tail->val;
    erase(tamano - 1);
    return valor;
}

void Vector::erase(int pos) { //!este es un despiche , igual Misma wea que insert pero al revez xdddd
    if (head == nullptr){
        return ;
    }
    Node* actual = head ; //el tamano es siempre 1 . aqui es el node al cual apunta head
    if (tamano==1 ) { 
        head= tail = nullptr;
        delete (actual) ; 
        tamano --; 
        return ;
    }
    if (pos >= tamano-1){ //se quiere eliminar el ultimo 
        actual = tail ;  //actual se vuelve el ultimo, el que tail esta apuntando 
        Node *anterior = actual->prev; //asigno un a referencia a un nodo , siendo el anterior del actual . 
        tail = anterior; // tail  queda apuntando al anterior del que quiero eliminar , asi no pierdo mi referencia de lista 
        actual ->prev =anterior ->next= nullptr;//se desconecta actual de la lista 
        delete actual; //elimina actual 
        tamano -- ; //tamano se reduce 
        return ;//termina 
    }
    else if (pos == 0 ) { 
        //actual ya es head 
        Node* siguiente = actual -> next; 
        head = siguiente; 
        siguiente -> prev = actual ->next = nullptr ; //!esto no estoy seguro si explota todo , ojala no , igual se ve cool (como si en realidad fuese bueno programando Bp )
        delete actual ;
        tamano --;
        return ; 
    }
    for (int i =0 ; i < pos ; i++ ) {
        actual = actual ->next; //recorro la lista; lista  , (tamano >=3 )
    };//quede apuntando como actual al nodo que quiero eliminar 
    Node* siguiente = actual -> next; //apunto al siguiente del que quiero eliminjar, esto son siempre medios 
    Node*anterior = actual ->prev;
    anterior->next = siguiente;
    siguiente->prev = anterior;
    actual->next = actual ->prev = nullptr ;
    delete actual; 
    tamano --;
    return ;  //return mi amada 

}

void Vector::swap(int m, int n){ //creacion de 2 punteros , se amtneiene una relacion de mayor menor entre los dos . la relacion es estatica . se revisa por cual inciar , si head o tail . 
    if (m==n) return ; //validacion de weas ; ya es costumbre sorry 
    if(m>n) {//m<n 
        int tmp = m ; 
        m=n ;
        n = tmp ;
    }
    Node* nodo_m ;
    Node* nodo_n ;
    if (m<=tamano / 2 ) { //buscador de N 
        nodo_m = head ;
        for (int i =0 ; i<m ; i++) {
            nodo_m = nodo_m->next;
        }; 
    }
    else {
        nodo_m = tail ;
        for (int i = tamano ; i>m ; i--) {
            nodo_m=nodo_m->prev;
        }
    }
    if (n <= tamano / 2) {
        nodo_n = head;
        for (int i = 0; i < n; i++) {
            nodo_n = nodo_n->next;
        }
    } else {
        nodo_n = tail;
        for (int i = tamano - 1; i > n; i--) {
            nodo_n = nodo_n->prev;
        }
    }
    nodo_m->val = nodo_m->val ^ nodo_n->val;
    nodo_n->val = nodo_m->val ^ nodo_n->val;
    nodo_m->val = nodo_m->val ^ nodo_n->val;
}

//!crear un manejador de instruccciones tipo automata ? trie maybe ? 

void inicar_vect(string linea, Vector arreglo_vect[], int n) {
    int pos = 0;
    string numActual = "";
    int indiceVector = 0;
    
    while (pos <= linea.length() && indiceVector < n) {
        // Si encontramos espacio o final de línea
        if (pos == linea.length() || linea[pos] == ' ') {
            if (!numActual.empty()) {
                int capacidad = stoi(numActual);
                if (capacidad != -1) {
                    // Crear vector con capacidad especifica
                    arreglo_vect[indiceVector] = Vector(capacidad);
                }
                // Si es -1 el constructor por defecto ya usa el int amx
                indiceVector++;
                numActual = "";
            }
        } else {
            numActual += linea[pos];
        }
        pos++;
    }
    
   
}
//funcion para wea de input . a hacer un chorro de ifs mae 



void procesar_comando(string ins , Vector arr_vect [] , int n  ) { //!ME OCUPO DESHACER DE [] PARA YA QUE SINO CRASHEA TODO
    string tokens[5] ; //5 palabras maximo pormlinea , veo que es que
    string act ;
    int count =0 ;
    for (int i = 0; i <= ins.length(); i++) {
        if (i == ins.length() || ins[i] == ' ') {
            if (!act.empty()) {
                tokens[count++] = act;
                act = "";
        }
    } else {
        act += ins[i];
        }
    }
    if (count == 1 && tokens[0]== "print") { 
        for (int i =0 ; i< n ; i ++) {
            arr_vect[i].print();
        }
        return ; 
    }
    int ind ; 
    ind= stoi(tokens[0]);
    if (count == 2) {  //!verificar bien aca , que hay unos que no retoirnan nada 
        if (tokens[1]== "sz") { cout<<arr_vect[ind].size() <<endl ;return; } //int 
        if (tokens[1]== "msz") { cout<<arr_vect[ind].max_size()<<endl ;return; } //int 
        if (tokens[1]== "ft") { cout<<arr_vect[ind].front()<<endl ;return; } //int
        if (tokens[1]== "bk") { cout<<arr_vect[ind].back() <<endl;return; }//int 
        if (tokens[1]== "pbk") { cout<<arr_vect[ind].pop_back()<<endl ;return; }//int 
    }
    int a ;
    a = stoi(tokens[2]);
    if (count == 3 ) { 
        if (tokens[1]== "rzs") { arr_vect[ind].resize(a) ;return; } //void
        if (tokens[1]== "at") { cout<<arr_vect[ind].at(a)<<endl ;return; } //int
        if (tokens[1]== "pb") { arr_vect[ind].push_back(a) ;return; } //void
        if (tokens[1]== "es") { arr_vect[ind].erase(a) ;return; } //void
    }
    int b ; 
    b= stoi(tokens[3]) ; 
    if (tokens[1]== "in") { arr_vect[ind].insert(a,b) ;return; } //void
    if (tokens[1]== "swp") { arr_vect[ind].swap(a,b) ;return; } //int


}

int main () { 
    int n , q ; 
    cin >> n >> q ; 
    Vector arreglo_vect [n] ; //arerglo de vectores
    string arr_ins [q] ; //arreglo de instruscfiones, vacio actualmente
    string linea ;
    cin.ignore();
    getline(cin, linea);
    inicar_vect (linea , arreglo_vect,n );
    for (int i = 0 ; i<q ; i++){ 
        getline  (cin , linea) ; //lo de4 cin se va a linea 
        arr_ins [i] = linea ;
    }
    for (string ins : arr_ins) { 
        procesar_comando (ins , arreglo_vect, n );
    }
}

/*!keys


*/

//! tener en cuenta que en c++  -> es como el :: pero en punteros o el .attribute de python (aunque py se hace un despiche con att y method )
 
//eliminacion de dll por vector . funciona igual que una dll pero se llama vector xd 

//!error importante . Al hacer push back , hay que verificar si el tamano ya es el maximo , que sino entro en errores pe casusa 
//!todo : : modificar los delete e insert de inicio y final ; funciones unicas ya que esos son con head y tail ltierlamente 