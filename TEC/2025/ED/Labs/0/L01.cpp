#include <iostream>
using namespace std;
int frec[26] ={0}; //Creacion de una lista de 26 elementos para almacenar la frecuencia de las letras 
int main () {
    string entrada; //entrada es un string unicamente 
    cin >> entrada;  // lo que se ponga en consola es mi entrada
    for (int l =0;l<entrada.length();l++){  //esto es o(N), dependiente del largo del la entrada
        int letra = entrada[l]; 
        if (letra >= 65 && letra <= 90) {
            frec[letra - 65]++;
        } else if (letra >= 97 && letra <= 122) {
            frec[letra - 97]++;
        }
        cout << letra << " ";
    }
    int ia=-1,ib=-1,ic=-1,fa=-1,fb=-1,fc=-1;//Almacenamiento de frecuenciasy letras
    for(int i=0;i<26;i++)
        {int f=frec[i]; 
        if(f>fa || (f==fa && i<ia)){
            ic=ib;
            fc=fb;
            ib=ia;
            fb=fa;
            ia=i;
            fa=f;
        }else if(f>fb || (f==fb && i<ib)){
            ic=ib;
            fc=fb;
            ib=i;
            fb=f;
        }else if(f>fc || (f==fc && i<ic)){
            ic=i;
            fc=f;
        }
    }
    cout<<char(65+ia)<<" "<<fa<<" "<<char(65+ib)<<" "<<fb<<" "<<char(65+ic)<<" "<<fc<<"\n";
}

