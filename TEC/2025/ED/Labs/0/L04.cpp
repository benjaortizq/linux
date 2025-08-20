#include <iostream>
#include <cmath>
using namespace std;
//me parecee a primera vista busqueda binaria 
//tiene H1 , desea volverlo a h2 . 
long long  calculoN(long double H1 , long double H2, int B ){
    long double r = H1 / H2, A = (long double)B / (long double)(B - 1), x = logl(r) / logl(A);;
    return ceil(x); // redondea hacia arriba el resultado de la division
}
int main (){
    int T;
    cin >> T; // numero de casos de prueba
    int respuestas[T]; // arreglo para guardar las respuestas de cada caso
    for (int t=0; t<T; t++) {
        long double H1, H2 ;
        int B;
        cin >> H1 >> H2 >> B;
        if (H1 <= H2) {
            cout << 0 << endl; // si ya son iguales o mayora, 0
            continue;}
        respuestas[t] = calculoN(H1, H2, B);}
    for (int t=0; t<T; t++) {cout << respuestas[t] << endl; }
}