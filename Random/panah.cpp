#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
using namespace std;

int main (){
	srand(time(0));
	int j=0,k=0;
	for(int i=0; i<6; i++){
		cout<<"\n\n\n\n\n";
		for(j=k; j>=1; j--){
			cout<<"\t";
		}
		k=k+1;
		cout<<"-->>>";
		Sleep(500);
		system("cls");
	}                            
                               
                               
                               

}

