#include <iostream>
using namespace std;

void sub(int a){
    if ( a ==1){
        cout<<"PRIMA\n";
    } else{
        cout<<"KOMPOSIT\n";
    }
}
int fungsi (int x, int y, int n){
    if( y == 1){
        return n;
    } else if (y == 0){
        return 1;
    } else {
        if (x%y==0){
            n++;
        }
        fungsi(x,y-1,n);
    }
}


int main(){
    int n, b;
    cin>>n;
    int A[n];
    for (int i = 0; i<n; i++){
        cin>>A[i];
    }
    for (int i = 0; i<n; i++){
        b = fungsi(A[i], A[i], 0);
        sub (b);
    }

}
