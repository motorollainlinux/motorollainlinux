#include <iostream>
#include <math.h>

void UserEnter(int* &Arr) {
    for (int i = 0; i < 10; i++) {
        std::cin >> Arr[i];
    }
}
void MathWait(int* &Arr) {
    int Summ;
    for (int i = 1; i < 10; i++) {
        Summ += Arr[i-1]*Arr[i];
    }
}
void Dispersion(int* &Arr) {
    int SrArifm, Srqvadrat, Despersion;
    for (int i = 0; i < 10; i++) {
        SrArifm += Arr[i];
    }
    SrArifm = SrArifm/10;
}
void RootMeanSquare(int* &Arr) {
    int S, Summ;
    for (int i = 1; i < 10; i++) {
        Summ += Arr[i-1] - Arr[i];
    }
    Summ = pow(Summ, 2);
    S = Summ/10;
}
void Divalition(int* &Arr) {
    
}
void MaxNormalase(int* &Arr) {
    
}
void MinNormalase(int* &Arr) {
    
}
int main() {
    int Arr[11];
    UserEnter(/** Arr /**/);
}
