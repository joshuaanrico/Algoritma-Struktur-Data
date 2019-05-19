#include<iostream>
using namespace std;
void loop(int n, int m){
    if(m == 0){
        cout<<n;
    } else  {
        cout<<n<<"+";
        loop(n, m-1);
    }
}
int main(){
    int n;
    int m;
    cin>>n;
    cin>>m;
    loop(n, m);
}
