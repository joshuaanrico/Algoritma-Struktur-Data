#include <iostream>
#include <stdlib.h>
using namespace std;

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef char infotype;

/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack * address;
typedef struct tElmtStack {
	infotype Info;
	address Next;
} ElmtStack;

/* Type stack dengan ciri TOP : */
typedef struct {
	address TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/*	----- Prototype Manajemen Memori ----- */
void Alokasi (address * P, infotype X) {
	/* Kamus Lokal */

	/* Algoritma */
	(*P) = (address) malloc (sizeof (ElmtStack));
	if ((*P) != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void Dealokasi (address P) {
	/* Kamus Lokal */

	/* Algoritma */
	Next(P)=Nil;
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
bool IsEmpty (Stack S) {
	/* Kamus Lokal */

	/* Algoritma */
	return (Top(S) == Nil);
}
void CreateEmpty (Stack * S) {
	/* Kamus Lokal */

	/* Algoritma */
	Top(*S) = Nil;
}
/*	----- Operator Dasar Stack ----- */
void Push (Stack * S, infotype X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	Alokasi(&P,X);
	if (P != Nil) {
		Next(P) = Top(*S);
		Top(*S) = P;
	}
}

void Pop (Stack * S, infotype * X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = Top(*S);
	*X= Info(P);
	if (!IsEmpty(*S)) {
		Top(*S)=Next(P);
		Dealokasi(P);
	}
}

void OutStack (Stack S){
    char x;
    while(!IsEmpty(S)){
        Pop(&S, &x);
        cout<<x<<" ";
    }
    cout<<endl;
}

int main (){
    Stack L;
    string w;
    char x;
    int n;

    cin>>n;

    for (int i = 0; i<n; i++){
        CreateEmpty(&L);
        cin>>w;
        for(int j = 0; j < w.length(); j++){
            if(w[j]=='1'||w[j]=='2'||w[j]=='3'||w[j]=='4'||w[j]=='5'||w[j]=='6'||w[j]=='7'||w[j]=='8'||w[j]=='9'||w[j]=='0'){
                Push(&L, w[j]);
            } else if (w[j]=='_'){
                Pop(&L, &x);
            }
        }
        OutStack(L);
    }
}
