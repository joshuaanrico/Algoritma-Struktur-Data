#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
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

 //SELEKTOR 
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).first)
#define Last(L) ((L).last)

//KONSTANTA
#define Nil NULL
#define Infinity 99999


/****************** TEST LIST KOSONG ******************/
bool IsEmpty(List L) {
    return (First(L) == NULL && Last(L) == NULL);
}


/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *L) {
    First(*L) = NULL;
    Last(*L) = NULL;
}


/****************** Manajemen Memori ******************/
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



void tuker(List *L, address P, infotype baru){
	Info(P)=baru;
}


address SearchB (List L, infotype X, infotype Y){
	address P = Next(First(L));
	while (P != Last(L)){
		if(Info(P) == 0){
			if ( Info(Next(P)) == Y && Info(Prev(P)) == X  ){
				return P;
			}
		}
		P = Next(P);
	}
	if(P == Last(L)){
		return Nil;
	}
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst(List *L, infotype x) {
    address NewElmt;
    NewElmt = Allocation(x);
    if (NewElmt != NULL) {
        if(IsEmpty(*L)){
        	First(*L) = NewElmt;
        	Last(*L) = NewElmt;
        } else{
        	Next(NewElmt) = First(*L);
        	Prev(First(*L)) = NewElmt;
        	First(*L) = NewElmt;
        }
    }
}


void InsertLast(List *L, infotype x) {
    address NewElmt;
    NewElmt = Allocation(x);
    if (NewElmt != NULL) {
        if(IsEmpty(*L)){
        	InsertFirst(L,x);
        } else{
        	Next(Last(*L)) = NewElmt;
        	Prev(NewElmt) = Last(*L);
        	Last(*L) = NewElmt;
        }
    }
}



/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
	if(IsEmpty(*L)){
       	First(*L) = P;
    	Last(*L) = P;
    } else{
       	Next(P) = First(*L);
       	Prev(First(*L)) = P;
       	First(*L) = P;
    }
}

void InsertLast (List *L, address P){
	if(IsEmpty(*L)){
       	InsertFirst(L,P);
    } else{
       	Next(Last(*L)) = P;
       	Prev(P) = Last(*L);
       	Last(*L) = P;
    }
}

void DelFirst (List *L, address *P){
	*P = First(*L);
	First(*L) = Next(*P);
	Prev(First(*L)) = Nil;
	Deallocation(*P);
}

void DelLast (List *L, address *P){
	*P = Last(*L);
	Last(*L) = Prev(*P);
	Next(Last(*L)) = Nil;
	Prev(*P) = Nil;
	Deallocation(*P);
}

void PrintForward (List L){ 
	cout<<"[";
	if(!IsEmpty(L)){
		address temp =First(L);
		while(Next(temp)!=NULL){
			if(Info(temp)  == 0){
				cout<<"_"<<"  ";
			}else{
				cout<<Info(temp) <<"  ";
			}
			temp = Next(temp);
		}
		if(Info(temp)  == 0){
			cout<<"_"<<"  ";
		}else{
			cout<<Info(temp);
		}
	}
	cout<<"]"<<endl;
}

int cekawal (List L){
	address P = First(L);
	if(Info(P) == Info(Next(P)) && Info(P) == Info(Next(Next(P))) && Info(P) != 0 ) {
		return 0;
	}else{
		return 1;
	}
}

int cekakhir (List L){
	address P = Last(L);
	if( Info(P) == Info(Prev(P)) && Info(P) == Info(Prev(Prev(P))) && Info(P) != 0) {
		return 0;
	}else{
		return 1;
	}
}

int cek (List L, address X){
	if(X == Prev(Last(L)) && Info(Prev(X)) != Info(X) ) {
		return 1;
	}else if( X == Next(First(L)) && Info(X) != Info(Next(X))  ){
		return 1;
	}
	
	if ( Info(X) == Info(Prev(X)) && Info(X) == Info(Next(X)) ){
		return 0;
	}else if (Info(X) == Info(Next(X)) && Info(X) == Info(Next(Next(X))) ){
		return 0;
	}else if (Info(X) == Info(Prev(X)) && Info(X) == Info(Prev(Prev(X)))){
		return 0;
	}else{
		return 1;
	}
	return 1;
}

int main () {
	srand(time(0));
	
	//deklarasi
	int banyakpercobaan=1,angkatebakan=1;
	char pilihmenu,posisipilihan;
	int pilihsoal=1, check=0, score=0;
	address P, posisiA, posisiB;
	int  posisi_A, posisi_B, posisi;
	List L;
	CreateList(&L);	
	InsertLast(&L, 9);
	InsertLast(&L, 2);
	InsertLast(&L, 0);
	InsertLast(&L, 0);
	InsertLast(&L, 0);
	InsertLast(&L, 1);
	InsertLast(&L, 1);
	InsertLast(&L, 0);
	InsertLast(&L, 2);
	InsertLast(&L, 0);
	
	int soal[10][10];
	int x,y,z,array[10];
	int A,B,C,D,E,F,G,H,I,J;
	
	//array
	soal[0][0]=9;
	soal[0][1]=2;
	soal[0][2]=0;
	soal[0][3]=0;
	soal[0][4]=0;
	soal[0][5]=1;
	soal[0][6]=1;
	soal[0][7]=0;
	soal[0][8]=2;
	soal[0][9]=0;
	
	//awal
	awal:
	cout<<"==========================================================\n";
	cout<<"\t\t ZUMA \n";
	cout<<"==========================================================\n";
	cout<<"\t 1. Pilih Soal \n";
	cout<<"\t 2. Pilih Banyak Percobaan \n";
	cout<<"\t 3. Mulai Permainan \n";
	cout<<"\t 4. Keluar \n";
	cout<<"\t Score : "<<score<<" \n";
	cout<<"\t Pilih Menu : ";
	cin>>pilihmenu;
	if(pilihmenu!='1'&&pilihmenu!='2'&&pilihmenu!='3'&&pilihmenu!='4'){
		cout<<"\t Inputan Salah";
		Sleep(1000);
		system("cls");
		goto awal;
	}
	system("cls");
	goto pilih_menu;
	
	
	//pemilihansoal
	pemilihan_soal:
	for(int i=0; i<10; i++){
		int j=0;
		cout<<"\t "<<i+1<<". ";
		do{
			x=rand()%9+1;
			y=rand()%9+1;
			z=rand()%9+1;
		}while(x == y || x == z || y == z);
		array[0]=x;
		array[1]=x;
		array[2]=z;
		array[3]=y;
		array[4]=y;
		for(int k=5; k<10; k++){
			array[k]=0;
		}

		//random
		A=rand()%10;
		soal[i][j] = array[A];
		if(soal[i][j] == 0){
			cout<<"_ ";
		}else{
			cout<<soal[i][j]<<" ";
		}
		
		B=rand()%10;
		while(B == A){
			B=rand()%10;
		}
		soal[i][j+1] = array[B];
		if(soal[i][j+1] == 0){
			cout<<"_ ";
		}else{
			cout<<soal[i][j+1]<<" ";
		}
		
		C=rand()%10;
		while(C == B || C == A){
			C=rand()%10;
		}
		soal[i][j+2] = array[C];
		if(soal[i][j+2] == 0){
			cout<<"_ ";
		}else{
			cout<<soal[i][j+2]<<" ";
		}
		
		D=rand()%10;
		while(D == B || D == A || D == C){
			D=rand()%10;
		}
		soal[i][j+3] = array[D];
		if(soal[i][j+3] == 0){
			cout<<"_ ";
		}else{
			cout<<soal[i][j+3]<<" ";
		}
		
		E=rand()%10;
		while(E == B || E == A || E == C || E == D){
			E=rand()%10;
		}
		soal[i][j+4] = array[E];
		if(soal[i][j+4] == 0){
			cout<<"_ ";
		}else{
			cout<<soal[i][j+4]<<" ";
		}
		
		F=rand()%10;
		while(F == B || F == A || F == C || F == D || F == E){
			F=rand()%10;
		}
		soal[i][j+5] = array[F];
		if(soal[i][j+5] == 0){
			cout<<"_ ";
		}else{
			cout<<soal[i][j+5]<<" ";
		}
		
		G=rand()%10;
		while(G == B || G == A || G == C || G == D || G == E || G == F){
			G=rand()%10;
		}
		soal[i][j+6] = array[G];
		if(soal[i][j+6] == 0){
			cout<<"_ ";
		}else{
			cout<<soal[i][j+6]<<" ";
		}
		
		H=rand()%10;
		while(H == B || H == A || H == C || H == D || H == E || H == F || H == G){
			H=rand()%10;
		}
		soal[i][j+7] = array[H];
		if(soal[i][j+7] == 0){
			cout<<"_ ";
		}else{
			cout<<soal[i][j+7]<<" ";
		}
		
		I=rand()%10;
		while(I == B || I == A || I == C || I == D || I == E || I == F || I == G || I == H){
			I=rand()%10;
		}
		soal[i][j+8] = array[I];
		if(soal[i][j+8] == 0){
			cout<<"_ ";
		}else{
			cout<<soal[i][j+8]<<" ";
		}
		
		J=rand()%10;
		while(J == B || J == A || J == C || J == D || J == E || J == F || J == G || J == H || J == I){
			J=rand()%10;
		}
		soal[i][j+9] = array[J];
		if(soal[i][j+9] == 0){
			cout<<"_ ";
		}else{
			cout<<soal[i][j+9]<<" ";
		}
		cout<<endl;
	}
	goto pemilihan_soal2;
	
	pemilihan_soal3:
	CreateList(&L);
	for(int i=0; i<10; i++){
		InsertLast(&L, soal[pilihsoal-1][i]);
	}
	goto awal;
	
	
	//pilihmenu
	pilih_menu :
	switch(pilihmenu){
		case '2' : {
			banyak_percobaan:
			cout<<"\n";
			cout<<"\t Banyak Percobaan : "<<banyakpercobaan<<endl;
			cout<<"\t Masukkan Banyak Percobaan Baru (1-5) : ";
			cin>>banyakpercobaan;
			if(banyakpercobaan < 1 || banyakpercobaan > 5){
				cout<<"\t Inputan Invalid";
				banyakpercobaan=1;
				Sleep(1000);
				system("cls");
				goto banyak_percobaan;
			}
			Sleep(1000);
			system("cls");
			goto awal;
		}
		case '4' : {
			return 0;
		}
		case '1': {
			pilih_soal:
			cout<<"\n";
			cout<<"\t Kamus Soal \n";
			goto pemilihan_soal;
			pemilihan_soal2:
			cout<<"\t Pilih Soal : ";
			cin>>pilihsoal;
			if(pilihsoal < 1 && pilihsoal > 10){
				cout<<"\t Inputan Invalid";
				pilihsoal=1;
				Sleep(1000);
				system("cls");
				goto pilih_soal;
			}
			cout<<"\t Anda Telah Memilih Soal "<<pilihsoal;
			Sleep(1000);
			system("cls");
			goto pemilihan_soal3;
		}
		case '3' : {
			Sleep(1000);
			system("cls");
			goto mulai_permainan;
		}
		default : {
			cout<<"\t Inputan Invalid";
			Sleep(1000);
			system("cls");
			goto awal;
		}
	}
	
	
	//mulaipermainan
	mulai_permainan :
	cout<<"\n";
	cout<<"\t "; PrintForward(L);
	cout<<"\t Kesempatan Menebak : "<<banyakpercobaan<<"\n";
	if(banyakpercobaan == 0){
		system("cls");
		cout<<"\n\t Kesempatan Habis";
		Sleep(3000);
		system("cls");
		banyakpercobaan=1;
		goto pemilihan_soal3;
	}
	cout<<"\t Masukan Angka Tebakan Anda : ";
	cin>>angkatebakan;
	cout<<"\t Tentukan Posisi Angka Tebakan Anda : \n";
	cout<<"\t a. Sebelum \n";
	cout<<"\t b. Sesudah \n";
	cout<<"\t c. Awal \n";
	cout<<"\t d. Akhir \n";
	cout<<"\t Masukan Posisi : ";
	cin>>posisipilihan;
	
	switch(posisipilihan){
		case 'a' : {
			cout<<"\t Angka : ";
			cin>>posisi_A;
			cout<<"\t Masukan Posisi : b"<<endl;
			cout<<"\t Angka : ";
			cin>>posisi_B;
			cout<<endl;
			posisiB=SearchB(L, posisi_B, posisi_A);
			tuker(&L, posisiB, angkatebakan);
			cout<<"\t"; PrintForward(L); cout<<endl;
			check = cek(L, posisiB);
			if(check == 0){
				cout<<"\t Selamat Anda Berhasil";
				Sleep(3000);
				system("cls");
				score = score +100;
				goto pemilihan_soal3;
			}else if (check == 1){
				cout<<"\t Maaf Anda Kurang Beruntung";
				banyakpercobaan = banyakpercobaan-1;
				Sleep(3000);
				system("cls");
				goto mulai_permainan;
			}
		}
		case 'b' : {
			cout<<"\t Angka : ";
			cin>>posisi_B;
			cout<<"\t Masukan Posisi : a"<<endl;
			cout<<"\t Angka : ";
			cin>>posisi_A;
			cout<<endl;
			posisiB=SearchB(L, posisi_B, posisi_A);
			tuker(&L, posisiB, angkatebakan);
			cout<<"\t"; PrintForward(L); cout<<endl;
			check = cek(L, posisiB);
			if(check == 0){
				cout<<"\t Selamat Anda Berhasil";
				Sleep(3000);
				system("cls");
				score = score +100;
				goto pemilihan_soal3;
			}else if (check == 1){
				cout<<"\t Maaf Anda Kurang Beruntung";
				banyakpercobaan = banyakpercobaan-1;
				Sleep(3000);
				system("cls");
				goto mulai_permainan;
			}
		}
		case 'c' : {
			DelFirst(&L, &P);
			InsertFirst(&L, angkatebakan);
			cout<<"\t"; PrintForward(L); cout<<endl;
			check = cekawal(L);
			if(check == 0){
				cout<<"\t Selamat Anda Berhasil";
				Sleep(3000);
				system("cls");
				score = score +100;
				goto pemilihan_soal3;
			}else if (check == 1){
				cout<<"\t Maaf Anda Kurang Beruntung";
				banyakpercobaan = banyakpercobaan-1;
				Sleep(3000);
				system("cls");
				goto mulai_permainan;
			}
		}
		case 'd' : {
			DelLast(&L, &P);
			InsertLast(&L, angkatebakan);
			cout<<"\t"; PrintForward(L); cout<<endl;
			check = cekakhir(L);
			if(check == 0){
				cout<<"\t Selamat Anda Berhasil";
				Sleep(3000);
				system("cls");
				score = score +100;
				goto pemilihan_soal3;
			}else if (check == 1){
				cout<<"\t Maaf Anda Kurang Beruntung";
				banyakpercobaan = banyakpercobaan-1;
				Sleep(3000);
				system("cls");
				goto mulai_permainan;
			}
		}
		default : {
			input_invalid:
			cout<<"\t Inputan Invalid";
			Sleep(1000);
			system("cls");
			goto mulai_permainan;
		}
	}
	
	
	Sleep(1000);
	system("cls");
	goto awal;
	
	
}
