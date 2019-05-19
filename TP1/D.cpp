#include<iostream>
using namespace std;
void persegi(int x, int y, int z){
    if(y>0){
        if ( x==1){
            cout<<"*\n";
            persegi(z,y-1,z);
        }
        else{
            cout<<"*";
            persegi(x-1, y, z);
        }
    }
}
int main(){
    int p, l;
    cin>>p>>l;
    persegi(p, l, p);
    return 0;
}
