/* Pakai Fungsi-Fungsi yang ada di Master 
dan tambahkan int main dibawah */
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype 	info;
	address 	next;
} ElmtList;

typedef struct {
	address		first;
} List;


//SELEKTOR 
#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info

//KONSTANTA
#define Nil NULL
#define Infinity 99999

 

bool isListEmpty (List L){
	/* Mengirim true jika list kosong */
	return (First(L)==Nil);
}

void createList (List *L){
	/*	I.S. sembarang
		F.S. Terbentuk list kosong 
	*/
	First(*L)=Nil;

}

address alokasi (infotype X){
	/*	Mengirimkan address hasil alokasi sebuah elemen
		Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, maka
		Info(P) = X, Next(P) = Nil
		Jika alokasi gagal, mengirimkan Nil
	*/
	address P = address(malloc(sizeof(ElmtList)));
	if(P==Nil)
		return Nil;

	Info(P) = X;
	Next(P) = Nil;
	return P;
	
}

void dealokasi (address *P){
	/*	I.S. P terdefinisi
		F.S. P dikembalikan ke sistem
		Melakukan dealokasi/pengembalian address P
	*/
	free(*P);
}

void insertFirst (List *L, infotype X){
	/*	I.S. L mungkin kosong
		F.S. X ditambahkan sebagai elemen pertama L
		Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen pertama dengan
		nilai X jika alokasi berhasil.
		Jika alokasi gagal: I.S.= F.S.
	*/
	address P = alokasi(X);
	if(P!=Nil){
		Next(P)=First(*L);
		First(*L) = P;
	}
}

void insertAfter (List *L, address P, address Prec){
	/*	I.S. Prec pastilah elemen list dan bukan elemen terakhir,
		P sudah dialokasi
		F.S. Insert P sebagai elemen sesudah elemen beralamat Prec
	*/
	Next(P)=Next(Prec);
	Next(Prec)=P;
}



void insertLast (List *L, infotype X){
	/*	I.S. L mungkin kosong
		F.S. X ditambahkan sebagai elemen terakhir L
		Proses : Melakukan alokasi sebuah elemen dan menambahkan elemen list di akhir :
		elemen terakhir yang baru bernilai X jika alokasi berhasil.
		Jika alokasi gagal: I.S.= F.S.
	*/
	address P = alokasi(X);
	if(isListEmpty(*L))
		insertFirst(L, X);
	else{
		address last = First(*L);
		while(Next(last)!=Nil) last = Next(last);
		insertAfter(L,P,last);
	}
}

void printInfo (List L){
	/*	I.S. List mungkin kosong
		F.S. Jika list tidak kosong,
		Semua info yg disimpan pada elemen list diprint dengan format [elemen-1, elemen-2, elemen-3, ...]
		Jika list kosong, hanya menuliskan "[]"
	*/
	cout<<'[';
	if(!isListEmpty(L)){
		address P = First(L);
		while(Next(P)!=Nil){
			cout<<Info(P)<<", ";
			P = Next(P);
		}
		cout<<Info(P);
	}
	cout<<']'<<endl;
}

/* Gunakan Fungsi di master.cpp tambahkan fungsi dibawah dan int main */

infotype max (List L){
	/*	Mengirimkan nilai Info(P) yang maksimum */
	int max = -Infinity;
	address P = First(L);
	while(Next(P)!=Nil){
		if(max<Info(P)) max=Info(P);
		P=Next(P);
	}
	if(max<Info(P)) max=Info(P);
	return max;
}

infotype min (List L){
	/*	Mengirimkan nilai Info(P) yang minimum */
	int min = Infinity;
	address P = First(L);
	while(Next(P)!=Nil){
		if(min>Info(P)) min=Info(P);
		P=Next(P);
	}
	if(min>Info(P)) min=Info(P);
	return min;
}


int main(){
	List L;
	createList(&L);

	//Soal A
	int n,mins=Infinity, maxs=-Infinity;
	int x;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>x;
		insertLast(&L, x);
	}
	maxs=max(L);
	mins=min(L);
	cout<<maxs<<endl<<mins;//printInfo(L);
	

	
}

