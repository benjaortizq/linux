#include <iostream>
using namespace std;
//me parecee a primera vista busqueda binaria 
//tiene H1 , desea volverlo a h2 . 
int main (){
    int T;
    cin >> T; // numero de casos de prueba
    for (int t=0; t<T; t++) {
        int H1, H2, B ;
        cin >> H1 >> H2 >> B;
        if (H1 < 1|| H1 > 1e12 || H2 < 1 || H2 > H1 || B < 2  || B > 2* 1e5) { //valores limite 
            cout << -1 << endl; // si los valores estan fuera de rango , devuelve -1
            return 0;
        }

        

    }
}