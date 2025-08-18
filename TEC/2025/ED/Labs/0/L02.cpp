#include <iostream>
using namespace std;
class Node  {public : int id ;int indegree; int* from;};
int main (){
    int m , n ;
    cin >> n >> m;
    int perm[n];
    Node* nodoArray= new Node [n]; ''' Aqui es donde empieza la incializacion de nodos apenas '''
    for (int i = 0; i < n; i++) 
        {  
        nodoArray[i].id = -1;
        nodoArray[i].indegree = 0;
        nodoArray[i].from = new int[n-1];
        for (int j = 0; j < n-1; j++) 
        {
            nodoArray[i].from[j] = -1;      // inicializar todos a -1
        }
    }
    for (int i=0 ; i<m ; i++ ){        //ESTE ES EL FOR QUE CREA LAS INCIDENCIAS DE CADA NUMERO Y LAS GUARDA EN UNA LISTA DE INCIDENCIAS.
        int a , b;
        cin >> a >> b;
        int c = 0;
        bool encontrado = false;
        while (c < n && !encontrado)  //recorre el nodo array hasta que encuentre el nodo o se acabe el array
        {
            if (nodoArray[c].id == b) {
                encontrado = true;
                for (int j = 0; j < n-1; j++) {
                    if (nodoArray[c].from[j] == a) { //verifica si el nodo ya existe y si no se ha agregado el nodo A
                        break;
                    }
                    if (nodoArray[c].from[j] == -1) { //evita falsos positivos, lo agrega solo si no hay A y es -1 
                        nodoArray[c].from[j] = a;
                        nodoArray[c].indegree++;
                        break;
                    }
                }
            }
            c++;
        }
        if (!encontrado) {nodoArray[c].id = b; nodoArray[c].from[0] = a; nodoArray[c].indegree = 1; }
    }   //hasta aqui esta lista la creacion de nodos y sus reduncancias, ahora toca  ordenarlos de forma lexicograficamente minima 

    while True {

    }


        //dos parametros importantes
        //revisar si el nodo ya existe. si si existe, incidencia++ , reordar que nodo se basa en B de( A B )
            //se recorre su lista de adyacencia mientras el from  sea diferente del numero O sea igual a -1 (ya que se agrega siempre al final los numeros )
                //agregar si es -1 y no se ha encontrado 
        //si el nodo no existe, poner el node id en donde array se haya quedado en ese while que recorria el nodearray . 

        //algoritmo para sacar levicograficamente

