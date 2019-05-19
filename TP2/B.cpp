#include <iostream>
using namespace std;

int hasil(int x, int y, int z){
    if(y == 0){
        return 1;
    } else if (y == 1) {
        return x;
    } else {
        x = x * z;
        y--;
        hasil(x, y, z);
    }
}

int main(){
 int a, b;
 cin >> a >> b;

 cout <<hasil(a, b, a);
}
