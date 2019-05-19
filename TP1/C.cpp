#include<iostream>
using namespace std;
void loop(int n){
    if(n == 0){
        cout<<n<<"\n";
    } else  {
        loop(n-1);
        cout<<n<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    loop(n);
}
