#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int info;
typedef struct Gerbong* alamat;
typedef struct Gerbong {
	info nilai;
	alamat kiri;
	alamat kanan;
} Node;

//==================================
typedef Node* tree;
//==================================

alamat alokasi(info x) {
	alamat P = alamat(malloc(sizeof(Node)));
	
	if(P != NULL) {
		P->kanan = NULL;
		P->kiri = NULL;
		P->nilai = x;
	}
	
	return P;
}

void dealok (alamat P) {
	cout << P->nilai;
	P->kanan = NULL;
	P->kiri = NULL;
	free(P);
}

tree create(info X, alamat L, alamat R) {
	alamat P = alokasi(X);
	if(P != NULL) {
		P->kanan = R;
		P->kiri = L;
	}
	return P;
}

void insert (info x, tree* T) {
	if(*T != NULL) {
		if(x < (*T)->nilai) return insert(x, &((*T)->kiri));
		else return insert(x, &((*T)->kanan));
	}
	*T = create(x, NULL, NULL);
}

int kedalaman(tree T) {
	if(T==NULL) return 0;
		if(T->kanan == NULL && T->kiri == NULL) return 1;
		if(kedalaman(T->kanan) < kedalaman(T->kiri)) return 1+kedalaman(T->kiri);
		else return 1+kedalaman(T->kanan);
}

void CobaDel(tree *T, info *x) {
	alamat P;
	if((*T)->kiri == NULL && (*T)->kanan==NULL) {
		*x = (*T)->nilai;
		P = *T;
		*T = NULL;
		dealok(P);
	}
}

bool cari (tree T, info x) {
	if(T==NULL) return false;
	if(T->nilai == x) return true;
	if(T->nilai > x) return cari(T->kiri, x);
	else return cari(T->kanan, x);
}

//void heap();
//void graph();
//priority Queue;

void cetak(tree T) {
	
		if(T != NULL) {
			cout << T->nilai;
			if(T->kiri != NULL) {
				cout << " ";
				cetak(T->kiri);
			}
			if(T->kanan != NULL) {
				cout << " ";
				cetak(T->kanan);
			}
		}
}

void preorder(tree T) {
	if(T==NULL) return;
	cout << T->nilai << " ";
	preorder(T->kiri);
	preorder(T->kanan);
}

void inorder(tree T) {
	if(T==NULL) return;
	inorder(T->kiri);
	cout << T->nilai << " ";
	inorder(T->kanan);
}

void postorder(tree T) {
	if(T==NULL) return;
	postorder(T->kiri);
	postorder(T->kanan);
	cout << T->nilai <<" ";
}

int main () {
	tree T = NULL;
	int x;
	
	for(int i=0; i<10; i++){
		cin>>x;
		insert(x, &T);
	}
	
	cout << "Pre : ";
	preorder(T); cout << endl;
	cout << "Ino : ";
	inorder(T); cout << endl;
//	postorder(T); cout << endl;
	cout<<endl;
	cetak(T);
	
}
