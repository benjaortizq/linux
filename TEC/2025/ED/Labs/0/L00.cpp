#include <iostream>
using namespace std;
//Raiz cuadrada de 
int  sum_bolos_niv (int n) {
    long double inf, sup, m,x ;
    inf = 0;
    sup = n;
    x=n;
    while (sup-inf > 0.000001) {          //este es el algoritmo de busqueda biaria. si es que se hiciese con formua directa, el tiempo seraia exponencial no cuadrado, por un elevado al cubo.
        m = (inf + sup) / 2;
        if ((m * (m+1))/2 < x) {
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
    for (int i=0 ; i<entrada ; i++) { //Se usa un for de lista por que se necesita almacenar los valores , lista de n elementos . 
        int c_p;
        cin >> c_p;
        lista[i] = c_p;
    }
    for (int j=0 ; j<entrada ; j++) {//for que recorre la lista para asi tirar el calculo. 
        cout << sum_bolos_niv(lista[j]) << endl;
    }
}
//Hola , este es mi primer programa en C++. espero no morir en el intento :p  este es el ejercicio de los bolos xddd. 
//Se tiene primero el mod 



// DEFINIR TIPO DE DATOS 
//IFS VA DENTRO DE PARENTESIS 
//USA LLAVES {} COMO IDENTACION 
//  >> FLECHAS DE DIRECCION PRA SALIDAS Y ENTRADAS << , COMO UN IMP UT EL COU/CIN
// AND = && 
//OR == ||
//NOT = !
// <>
//MATCH = IF ELIF PERO EFICIENTE 
//FORS SON 3 STATEMENTS, DECLARA EL CONTADOR, CONDICION , INCREMENTADOR 
// MAIN TIRA 0 POR DEFEFCTO ]
// N= ; N ES EL PUNTERO A ESE VALOR EN MEMORIA , LITERALMENTE ES COMO DEFINIR UNA VARIABLE. 

