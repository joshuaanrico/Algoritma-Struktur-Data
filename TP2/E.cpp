#include <iostream>
using namespace std;
void balik (int *A){
    if(*A<10){
        *A = *A * 10;
    } else {
        *A = (*A%10) * 10 + *A/10;
    }
}

void Urut (int a[], int n){
/*gunakan algoritma sorting*/
    for (int i = 0; i<n-1; i++){
            for(int j = 0; j<n-1; j++){
                int temp;
                if (a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
int main (){
    int N;
    cin >> N;
    int X[N], i=0;
    while (i < N){
        cin >> X[i];
        balik(&X[i]);
        i++;
    }

    Urut(X, N);
    i=0;
    while (i < N){
        balik(&X[i]);
        cout << X[i] <<endl;
        i++;
    }
    return 0;
}
