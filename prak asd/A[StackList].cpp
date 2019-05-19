#include <iostream>
#include<cstdlib>
using namespace std;

typedef int infotype;
typedef struct TElmtList *address;
typedef struct TElmtList{
	 infotype info;
 	address next;
 	address prev;
} ElmtList;

typedef struct {
 	address first;
 	address last;
}List ;

#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).first)
#define Last(L) ((L).last)
#define Nil NULL

void CreateEmpty(List *L) {
	(*L).first = NULL;
}

bool IsEmpty(List L) {
 	return (First(L) == NULL && Last(L) == NULL);
}

void createList(List *L) {
 	First(*L) = NULL;
 	Last(*L) = NULL;
}

address Allocation(infotype x) {
 	address NewElmt;
 	NewElmt = (ElmtList*) malloc (sizeof(ElmtList));
 	Info(NewElmt) = x;
 	Next(NewElmt) = Nil;
 	Prev(NewElmt) = Nil;
 	return NewElmt;
}

void Deallocation(address hapus) {
 	free(hapus);
}

void insertFirst (List *L , infotype x){
    address p = Allocation(x);
    if(IsEmpty(*L)){
        First(*L)=p;
        Next(First(*L))=First(*L);
    }else{
        Next(p)=First(*L);
        address temp=First(*L);
        while(Next(temp) != First(*L)){
        temp = Next(temp);
        }
    Next(temp)=p;
    First(*L)=p;
    }
    
}

void InsertAfter (List *L, address P, address Prec){
    
    if(Next(Prec) == First(*L)){
    Next(Prec)=P;
    Next(P)=First(*L);
    }else{
    Next(P)=Next(Prec);
    Next(Prec)=P;
    }
}

void InsertLast (List *L, infotype x){
    if(IsEmpty(*L)){
        insertFirst(L,x);
    }else{
        address p = Allocation(x);
        address temp;
        temp=First(*L);
        while(Next(temp) != First(*L)){
            temp=Next(temp);
        }
    Next(temp)=p;
    Next(p)=First(*L);
    }
}


void printInfo (List L){
    if(!IsEmpty(L)){
        address P = First(L);
        while(Next(P)!= First(L)){
            cout<<Info(P)<<endl;
            P = Next(P);
        }
        cout<<Info(P);
    }
}

int main(){
    List L;
    createList(&L);
    int n,x;
    int sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        insertFirst(&L,x);
        sum+=x;
    }
    printInfo (L);
    cout<<endl;
    cout<<sum;
    
    
    return 0;
}

