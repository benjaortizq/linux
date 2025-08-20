#include <iostream>
using namespace std;
const long long MOD = 1000000007; //mod que hay que usar 
const int MAX_N = 2005;//maximo rango de primos 

bool esPrimo[MAX_N];
long long fact[MAX_N], invFact[MAX_N];

void criba() { ///funcion para encontrar todos los primos hasta MAX_N usando la criba de eratostenes
    for (int i = 0; i < MAX_N; i++) {
        esPrimo[i] = true;
    }
    esPrimo[0] = esPrimo[1] = false;
    for (int i = 2; i * i < MAX_N; i++) {
        if (esPrimo[i]) {
            for (int j = i * i; j < MAX_N; j += i) {
                esPrimo[j] = false;
            }
        }
    }
}

long long potencia(long long a, long long b) { //funcion para calcular a^b mod MOD usando exponenciacion rapida
    long long res = 1;
    a = a % MOD;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        b = b >> 1;
        a = (a * a) % MOD;
    }
    return res;
}

long long modInverso(long long n) {
    return potencia(n, MOD - 2); //usando el teorema de fermat para calcular el inverso modular
}

void precomputarFactoriales() { //funcion para precomputar factoriales e inversos modulares de factoriales
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX_N - 1] = modInverso(fact[MAX_N - 1]);
    for (int i = MAX_N - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long coeficiente_binomial (int n, int k) {
    if (k < 0 || k > n) return 0;
    return (((fact[n] * invFact[k]) % MOD) * invFact[n - k]) % MOD;
}


int main() {
    criba();
    precomputarFactoriales(); 
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int Y, X;
        cin >> Y >> X;
        long long result = 0;
        // para cada len entre x y y inclusive
        for (int length = Y; length <= X; length++) {
            // Para cada posible cantidad de unos
            for (int ones = 0; ones <= length; ones++) {
                int zeros = length - ones;
                
                // Verificar si dos son primas
                if (esPrimo[ones] && esPrimo[zeros]) {
                    result = (result + coeficiente_binomial(length, ones)) % MOD;
                }
            }
        }
        cout << result << endl;
    }
}
