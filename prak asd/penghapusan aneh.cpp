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


//SELEKTOR 
#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info

//KONSTANTA
#define Nil NULL
#define Infinity 99999

 

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
    cout<<'[';
    if(!isListEmpty(L)){
        address P = First(L);
        while(Next(P)!=Nil){
            cout<<Info(P)<<", ";
            P = Next(P);
        }
        cout<<Info(P);
    }
    cout<<']';
}

void deletefirst(List *L){
    if(!isListEmpty(*L)){
        address p = First(*L);
        First(*L) = (*L).first->next;
        Next(p) = NULL;
        dealokasi(&p);
    }
}

void deleteAfter(address *pred){
        address p = Next(*pred);
        Next(*pred) = Next(p);
        Next(p) = NULL;
        dealokasi(&p);
    
}

void deleteLast(List *L){
    if(!isListEmpty(*L)){
        address temp, predTemp;
        predTemp = NULL;
        temp = (*L).first;
        while(Next(temp)!=NULL){
            predTemp = temp;
            temp = Next(temp);
        }
        if(temp == (*L).first) deletefirst(L);
        else deleteAfter(&predTemp);
    }
}


void del(List *L){
    address cek = First(*L);
    while(Next(cek)!=NULL){
        if(Info(cek)%2==0) deletefirst(L);
        else if(Info(cek)%3==0) deleteLast(L);
        cek = Next(cek);
    }
        if(Info(cek)%2==0) deletefirst(L);
        else if(Info(cek)%3==0) deleteLast(L);
}

int main(){
    List L;
    createList(&L);
    int n, hapus;
    infotype x;
    cin>>n;
    cin>>x;
    insertFirst(&L, x);
    for(int i=0; i<n-1; i++){
        cin>>x;
        insertLast(&L, x);
    }
    del(&L);
    printInfo(L);
}


