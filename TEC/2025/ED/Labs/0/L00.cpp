//Hola , este es mi primer programa en C++. espero no morir en el intento :p  este es el ejercicio de los bolos xddd. 
//Se tiene primero el mod 

int mod = 1000000007;

//Raiz cuadrada de 
long double raiz (int x) {
    long double er, inf, sup, m;
    er= 0.00001;
    inf = 1;
    sup = m;
    while (sup-inf > er) {
        m = (inf + sup) / 2;
        if (m * m < x) {
            inf = m;
        } else {
            inf = m;
        }
    }
    return m;
}
