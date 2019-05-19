#include <iostream>
#include <stdlib.h>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct tElmtStack * address;
typedef struct tElmtStack { 
    infotype Info;
    address Next; 
} ElmtStack; 

typedef struct { 
    address TOP;  
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->Info 
#define Next(P) (P)->Next
#define Info(P) (P)->Info

void Alokasi (address * P, infotype X) {
    (*P) = (address) malloc (sizeof (ElmtStack));
    if ((*P) != Nil) {
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi (address P) {
    Next(P)=Nil;
}

bool IsEmpty (Stack S) {
    return (Top(S) == Nil);
}

void CreateEmpty (Stack * S) {
    Top(*S) = Nil;
}

void Push (Stack * S, infotype X) {
    address P;
    Alokasi(&P,X);
    if (P != Nil) {
        Next(P) = Top(*S);
        Top(*S) = P;
    }
}

void Pop (Stack * S, infotype * X) {
    address P;
    P = Top(*S);
    *X= Info(P);
    if (!IsEmpty(*S)) {
        Top(*S)=Next(P);
        Dealokasi(P);
    }
}

struct Nilai{
    string kata;
};

int main(){
    int del;
    int x;
    cin >> x;
    
    Nilai a[x];
    
    for(int i=0; i<x; i++){
        cin >> a[i].kata;
    }
    
    Stack Q;
    CreateEmpty(&Q);
    
    for(int i=0; i<x; i++){
        for(int j=0; j<((a[i].kata).length()); j++){
            if(a[i].kata[j]=='0'){
                Push(&Q,0);
            }else if(a[i].kata[j]=='1'){
                Push(&Q,1);
            }else if(a[i].kata[j]=='2'){
                Push(&Q,2);
            }else if(a[i].kata[j]=='3'){
                Push(&Q,3);
            }else if(a[i].kata[j]=='4'){
                Push(&Q,4);
            }else if(a[i].kata[j]=='5'){
                Push(&Q,5);
            }else if(a[i].kata[j]=='6'){
                Push(&Q,6);
            }else if(a[i].kata[j]=='7'){
                Push(&Q,7);
            }else if(a[i].kata[j]=='8'){
                Push(&Q,8);
            }else if(a[i].kata[j]=='9'){
                Push(&Q,9);
            }else if(a[i].kata[j]=='_'){
                Pop(&Q,&del);
            }
        }
        while(!IsEmpty(Q)){
            Pop(&Q,&del);
            cout <<del<<" ";
        }
        if(i+1<x){
            cout << endl;
        }
    }
}

