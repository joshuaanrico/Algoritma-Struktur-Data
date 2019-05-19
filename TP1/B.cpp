#include<iostream>
using namespace std;
void loop(int n, int i){
    if(n == i){
        cout<<i<<"\n";
    } else  {
        loop(n, i +1 );
        cout<<i<<endl;
    }
}
int main(){
    int n;
    int i = 1;
    cin>>n;
    loop(n, i);
}
