#include <iostream>
#include <string>
using namespace std;

#define Nil -1        
#define MaxEl 20       /*ukuran maksimum table penampung */

typedef char infotype;
typedef struct {
	infotype T[MaxEl]; 
	int TOP;           
} Stack;


void CreateEmpty (Stack *S){
    (*S).TOP = Nil;
}


bool IsEmpty (Stack S){
    return ( (S).TOP == Nil );
}

bool IsFull (Stack S){
    return( (S).TOP == MaxEl );
}



void Push (Stack *S, infotype X) {
    if(!IsFull(*S)){
        (*S).TOP++;
        (*S).T[(*S).TOP]=X;
    } else {
        cout<<"\nStack Penuh\n";
    }
}



void Pop (Stack *S) {
    if(!IsEmpty(*S)){
        (*S).TOP--;
    } else {
        cout<<"\nStack Kosong\n";
    }
}

void OutStack (Stack S){
    for (int i = 0; i<=(S).TOP; i++){
        cout<<(S).T[i]<<" ";
    }
    cout<<endl;
}

int main(){
   int n,y;
   string a;
   cin>>n;
   Stack L;
  
   infotype X;
   for(int i=0; i<n; i++){
   	 	CreateEmpty(&L);
   		cin>>a;
   		for(int j=0; j<a.length(); j++){
   			if(a[j] == '1' || a[j] == '2' || a[j] == '3' || a[j] == '4' || a[j] == '5' || a[j] == '6' || a[j] == '7' || a[j] == '8' || a[j] == '9' || a[j] == '0' ){
   				Push(&L, a[j]);
			}else if(a[j] == '_'){
				Pop(&L);
			}
		}
		OutStack(L);
   }
}
