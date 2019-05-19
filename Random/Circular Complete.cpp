#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist {
	infotype info;
	address next;
}ElmtList;

typedef struct {
	address First;
}List;

#define First(L) ((L).First)
#define Next(P) (P)->next
#define Info(P) (P)->info

bool IsEmpty (List L){
	return (First(L)==NULL);
}

void CreateEmpty (List *L){
	First(*L) = NULL;
}

address alokasi (infotype X){
	address P = address(malloc(sizeof(ElmtList)));
	
	if(P==NULL){
		return NULL;
	}
	
	Info(P) = X;
	Next(P) = NULL;
	return P;
	
}

void dealokasi (address hapus){
	free(hapus);
}

void InsertFirst (List *L, infotype X){
	address P = alokasi(X);
	if(IsEmpty(*L)){
		First(*L)=P;
		Next(P)=First(*L);
	}else{
		Next(P)=First(*L);
		address temp=First(*L);
		while(Next(temp) != First(*L)){
			temp=Next(temp);
		}
		Next(temp)=P;
		First(*L)=P;
		
	}
}

void InsertAfter (List *L, address P, address Prev){
	Next(P)=Next(Prev);
	Next(Prev)=P;
}

void InsertLast (List *L, infotype X){
	address P = alokasi(X);
	if(IsEmpty(*L)){
		InsertFirst(L, X);
	}else{
		address temp=First(*L);
		while(Next(temp) != First(*L)){
			temp=Next(temp);
		}
		Next(temp) = P;
		Next(P) = First(*L); 
	}
}

void DeleteFirst (List *L, infotype* del){
	if(First(*L) != NULL){
		if(Next(First(*L)) == First(*L)){
			*del = Info(First(*L));
			dealokasi(First(*L));
			First(*L) = NULL;
			return;
		}
		address temp = First(*L);
		*del = Info(temp);
		while(Next(temp) != First(*L)){
			temp = Next(temp);
		}
		Next(temp) = Next(Next(temp));
		dealokasi(First(*L));
		First(*L) = Next(temp);
	}
}

void DeleteAfter (List *L, address Prev, infotype *del){
	if(Next(Prev) == First(*L)){
		DeleteFirst(L, del);
		return;
	}
	*del = Info(Next(Prev));
	address X = Next(Prev);
	dealokasi(X);
}

void DeleteLast (List *L, infotype *del){
	if(First(*L) != NULL){
		address temp = First(*L);
		while(Next(Next(temp)) != First(*L)){
			temp = Next(temp);
		}
		DeleteAfter(L, temp, del);
	}
}

void PrintInfo (List L){
	cout<<"[";
	if(!IsEmpty(L)){
		address P = First(L);
		while(Next(P) != First(L)){
			cout<<Info(P)<<", ";
			P = Next(P);
		}
		cout<<Info(P);
	}
	cout<<"]"<<endl;
}

int main(){

int a,b;
cin >> a;
List L;
CreateEmpty(&L);
InsertFirst (&L,a);
PrintInfo (L);
cin>>b;
InsertLast (&L,b);
PrintInfo (L);
cin >> a;
InsertFirst (&L,a);
PrintInfo (L);
cin>>b;
InsertLast (&L,b);
PrintInfo (L);
DeleteFirst(&L, &a);
PrintInfo (L);
}


