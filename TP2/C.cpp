#include<iostream>
using namespace std;
int pangkat(int x, int n, int sum, int c){
    if (sum == x){
        cout<<" = "<<n<<"^2";
    } else {
        sum +=c;
        cout<<c;
        if(sum!=x){
            cout<<"+";
        }
        n++;
        c+=2;
        pangkat(x, n, sum, c);

    }
}

int main(){
    int x, n = 0, sum = 0, c = 1;
    cin>>x;
    pangkat(x, n, sum , c);
}
