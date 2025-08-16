#include <iostream>
using namespace std;
int  sum_bolos_niv (int n) {
    long double inf, sup, m;
    inf = 0; sup = n;
    while (sup-inf > 0.000001) {          //este es el algoritmo de busqueda biaria. si es que se hiciese con formua directa, el tiempo seraia exponencial no cuadrado, por un elevado al cubo.
        m = (inf + sup) / 2;
        if ((m * (m+1))/2 < n) {
            inf = m;
        } else {
            sup = m;
        }
    }
    long long M = (long long)(m);
    long long resultado = (M * (M+1) * (M+2)) / 6;   //este es el resultado de la sumatoria de todos los niveles. para esto no se ocupa biusqueda biaryia ya que es una formula pro.
    int  mod = 1e9+7;
    return (resultado % mod);
}
int main () {
    int entrada ;
    cin >> entrada ;
    int lista [entrada];
    for (int i=0 ; i<entrada ; i++) {int c_p;cin >> c_p;lista[i] = c_p;}
    for (int j=0 ; j<entrada ; j++) {cout << sum_bolos_niv(lista[j]) << endl;
    }
}
