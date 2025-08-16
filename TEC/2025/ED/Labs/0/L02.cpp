struct Node {int valor ;Node *next; Node (int v ): valor(v), next (nullptr){}};
class lista {
    Node *head;
public:
    lista(){head=nullptr; } //empeiza aputnando a nada cuando se crea la lsita 
    void insertar(int valor ); 
    void imprimir ();
}
void lista ::insertar  (int val) { 
    if (head == nullptr) {
        head=new Node(val);
    } else {
        Node *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }
}
bool lista::isin(int valor) {
    Node *temp = head;
    while (temp) {
        if (temp->valor == valor) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int main (){
    int m, n;
    cin >> m >> n;
    lista miLista;
    for (int i = 0; i < m; i++) {
        int i,j;
        cin >> i >> j;
        if (miLista.isin(i) )
    }
}
