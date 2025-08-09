//Hola , este es mi primer programa en C++. espero no morir en el intento :p  este es el ejercicio de los bolos xddd. 
//Se tiene primero el mod 



// sEFINIR TIPO DE DATOS 

//IFS VA DENTRO DE PARENTESIS 
//USA LLAVES {} COMO IDENTACION 
//  >> FLECHAS DE DIRECCION PRA SALIDAS Y ENTRADAS << , COMO UN IMP UT EL COU/CIN
// AND = && 
//OR == ||
//NOT = !
// <>
//MATCH = IF ELIF PERO EFICIENTE 
//FORS SON 3 STATEMENTS, DECLARA EL CONTADOR, CONDICION , INCREMENTADOR 
// 

#include <iostream>
using namespace std;
int mod = 1000000007;

//Raiz cuadrada de 
long double raiz (int n) {
    long double er, inf, sup, m,x ;
    er= 0.00001;
    inf = 1;
    sup = n;
    x=n;
    while (sup-inf > er) {
        m = (inf + sup) / 2;
        if (m * m < x) {
            inf = m;
        } else {
            sup = m;
        }
    }
    return m;
}

int main () {
    int n ;
    cin >> n ;
    cout << raiz(n) << endl;
}
