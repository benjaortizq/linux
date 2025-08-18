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
    char matriz[F][C];
    for (int i=0 ; i< F; i++ ) {
        for (int j = 0 ; j < C; j++) {
            cin >> matriz[i][j];
        }
    }
}
