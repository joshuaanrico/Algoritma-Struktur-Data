/*
Nama/NIM Kelompok :
	Laurensius Joshua Anrico Agustinus 	14117141
	Steven Hermadoni					14117109
Kelas :
	Teori Bahasa Formal dan Otomata - RD
*/
	
/* 
	pengguna hanya bisa menginputkan 
	#cetak "<inputan>"; 	-> tidak case sensitive
	#selesai;				-> tidak case sensitive
	jika menginputkan selain diatas akan salah
*/

#include <bits/stdc++.h>
using namespace std;

// mengeluarkan input dari " awal sampai " terakhir
int cekCetak6(char input[], int ukuran){
	if(input[ukuran-2] == '"' && input[ukuran-1] == ';' && input[8] !=';'){
		cout<<"> ";
		for(int i=8; i<ukuran-2; i++){
			cout<<input[i];
		}
		cout<<endl;
		return 3;
	}else{
		return 1;
	}
}

int cekCetak5(char input[], int ukuran){
	if(input[7]=='"'){
		return cekCetak6(input,ukuran);
	}else{
		return 1;
	}
}

int cekCetak4(char input[], int ukuran){
	if(input[6]==' '){
		return cekCetak5(input,ukuran);
	}else{
		return 1;
	}
}

int cekCetak3(char input[], int ukuran){
	if(input[5]=='k' || input[5]=='K'){
		return cekCetak4(input,ukuran);
	}else{
		return 1;
	}
}

int cekCetak2(char input[], int ukuran){
	if(input[4]=='a' || input[4]=='A'){
		return cekCetak3(input,ukuran);
	}else{
		return 1;
	}
}

int cekCetak1(char input[], int ukuran){
	if(input[3]=='t' || input[3]=='T'){
		return cekCetak2(input,ukuran);
	}else{
		return 1;
	}
}

int cekCetak(char input[], int ukuran){
	if(input[2]=='e' || input[2]=='E'){
		return cekCetak1(input,ukuran);
	}else{
		return 1;
	}
}

// cek apakah input adalah #selesai;
int cekSelesai6(char input[],int ukuran){
	if(input[ukuran-1]==';' && ukuran==9 ){
		return 2;
	}else{
		return 1;
	}
}

int cekSelesai5(char input[],int ukuran){
	if(input[7]=='i' || input[7]=='I'){
		return cekSelesai6(input,ukuran);
	}else{
		return 1;
	}
}

int cekSelesai4(char input[], int ukuran){
	if(input[6]=='a' || input[6]=='A'){
		return cekSelesai5(input,ukuran);
	}else{
		return 1;
	}
}

int cekSelesai3(char input[], int ukuran){
	if(input[5]=='s' || input[5]=='S'){
		return cekSelesai4(input, ukuran);
	}else{
		return 1;
	}
}

int cekSelesai2(char input[], int ukuran){
	if(input[4]=='e' || input[4]=='E'){
		return cekSelesai3(input,ukuran);
	}else{
		return 1;
	}
}

int cekSelesai1(char input[],int ukuran){
	if(input[3]=='l' || input[3]=='L'){
		return cekSelesai2(input,ukuran);
	}else{
		return 1;
	}
}

int cekSelesai(char input[], int ukuran){
	if(input[2]=='e' || input[2]=='E'){
		return cekSelesai1(input,ukuran);
	}else{
		return 1;
	}
}

int cek1(char input[], int ukuran){
	if(input[1]=='C' || input[1]=='c'){
		return cekCetak(input,ukuran);
	}else if (input[1]=='S' || input[1]=='s'){
		return cekSelesai(input,ukuran);
	}else{
		return 1;
	}
}

int cek(char input[], int ukuran){
	if(input[0]=='#'){
		return cek1(input,ukuran);
	}else{
		return 1;
	}
}

int main () {
	
	//mengulang sampai muncul kata #selesai;
	//check == 1 -> ngulang dan input salah
	//check == 2 -> input selesai
	//check == 3 -> ngulang tapi input bener
	int check=1;
	while(check==1 || check == 3){
		string input;
		getline(cin, input);
		
		//mengubah string ke char
		char inputChar[input.length()];
		for (int i = 0; i < sizeof(inputChar); i++) { 
        	inputChar[i] = input[i]; 
    	}
    	
		//masuk ke dalam fungsi cek dan mengecek selesai atau tidak
		check = cek(inputChar,sizeof(inputChar));
		if(check==1){
			cout<<"> Kode tidak sesuai dengan peraturan\n";
		}
	}
	cout<<"\nTerima kasih sudah menggunakan compiler ini";

}
