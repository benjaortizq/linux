#include <iostream>
using namespace std;
//ejercicio 4 , matriz cuadrada mas grande 
int main (){
    int F , C  ;
    cin >> F >> C ;
    if (F <=0 || F >=1e4|| C <=0 || C>=1e4) {
        cout << -1 << endl ;
        return 0 ;
    }
    int matriz[F][C]; //crea matriz de caracteres 
    for (int i=0 ; i< F; i++ ) { // recibe la matriz 
        for (int j = 0 ; j < C; j++) {
            char letra ;
            cin >> letra ;
            if (letra >='A' && letra <= 'Z') {
                matriz[i][j] = 1; // si es mayuscula , escribe un 1 en la matriz 
            } else if (letra >= 'a' && letra <= 'z') {
                matriz[i][j] = 0; // si es minuscula , escribe un 0 en la matriz 
            } else {
                cout << -1 << endl ; // si no es una letra , devuelve -1
                return 0 ;
            }
        }
    }
    int maximo_actual=0 ;
    for (int i = 1 ; i < F ; i++) { //recorre filas 
        for (int j = 1 ; j < C ; j++) { //cols 
            if (matriz[i][j] == 1) { // si el valor en la posicion es >=1 
                    matriz[i][j] = min(matriz[i-1][j], min(matriz[i][j-1], matriz[i-1][j-1])) + 1;
                    maximo_actual = max(maximo_actual, matriz[i][j]); // actualizo el maximo actual
            }
        }
    }
    cout << maximo_actual << endl ; // devuelvo el area del cuadrado
}

//el toque para resolver esta vaina 
//al puro inicio en la creacion de la matriz. cada que reciba un caracter . si el caracter es una mayuscula escribe un 1 en la matriz . 
//tengo una variable en la que guardo el numero mas grande hasta ahora encontrado (para no recorrer la amtriz un monton de veces)
//despues , al tener ya la matriz creada , se recorre buscando numeros >=1. si ubicacion de este numero es (i,j) , e i > 0 y j> 0 y i < F y j < C , me fijo si en (i-1, j ) hay un numeor >=1 , y si en(i, j-1) hay un numero >=1 . si los dos nunmeros son iguales , le doy a ni munero ese numero +1 . ))
