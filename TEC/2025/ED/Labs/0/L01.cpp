#include <iostream>
using namespace std;
int frec[26] ={0}; //Creacion de una lista de 26 elementos para almacenar la frecuencia de las letras 
int main () {
    string entrada; //entrada es un string unicamente 
    cin >> entrada;  // lo que se ponga en consola es mi entrada
    for (int l =0;l<entrada.length();l++){  //esto es o(N), dependiente del largo del la entrada
        char letra = entrada[l]; 
        if (letra >= 65 && letra <= 90) {
            frec[letra - 'A']++;
        } else if (letra >= 97 && letra <= 122) {
            frec[letra & ~32]++;
        }
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
    cout<<char('A'+ia)<<" "<<fa<<" "<<char('A'+ib)<<" "<<fb<<" "<<char('A'+ic)<<" "<<fc<<"\n";
}

