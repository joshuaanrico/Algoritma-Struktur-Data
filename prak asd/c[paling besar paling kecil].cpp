#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

typedef struct {
    address first;
} List;

#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info
#define Infinity 99999
#define Nil NULL 

bool isListEmpty (List L){
    return (First(L)==Nil);
}

void createList (List *L){
    First(*L)=Nil;
}

address alokasi (infotype X){
    address P = address(malloc(sizeof(ElmtList)));
    if(P==Nil)
    
        return Nil;

    Info(P) = X;
    Next(P) = Nil;
    return P;
    
}

void dealokasi (address *P){
    free(*P);
}

void insertFirst (List *L, infotype X){
    address P = alokasi(X);
    if(P!=Nil){
        Next(P)=First(*L);
        First(*L) = P;
    }
}

void insertAfter (address *P, infotype x){
    address newElmt = alokasi(x);
    
    Next(newElmt)=Next(*P);
    Next(*P)=newElmt;
}

void insertLast (List *L, infotype X){
    address P = alokasi(X);
    if(isListEmpty(*L))
        insertFirst(L, X);
    else{
        address last = First(*L);
        while(Next(last)!=Nil) last = Next(last);
        insertAfter(&last, X);
    }
}


void printInfo (List L){
    if(!isListEmpty(L)){
        address P = First(L);
        cout<<"[";
        while(Next(P)!=Nil){
            cout<<Info(P)<<", ";
            P = Next(P);
        }
        cout<<Info(P);
        cout<<"]";
    }
}

infotype max (List L){
    /*    Mengirimkan nilai Info(P) yang maksimum */
    int max = -Infinity;
    address P = First(L);
    while(P!=Nil){
        if(max<Info(P))
        max= Info(P);
        P=Next(P);
    }
    return max;
}

infotype min (List L){
    /*    Mengirimkan nilai Info(P) yang minimum */
    int min = Infinity;
    address P = First(L);
    while(P!=Nil){
        if(min>Info(P))
        
        min= Info(P);
        P=Next(P);
    }
    return min;
}


int main(){
    List L;
    createList(&L);
    int n,x;
    cin>>n;
    for (int i =0;i<n;i++){
        cin>>x;
        insertLast(&L,x);
    }
    cout<<max(L)<<endl;
    cout<<min(L)<<endl;
}


