#include <iostream>
#include <string>
using namespace std;

#define Nil -1         /* Nil adalah stack dengan elemen kosong */
#define MaxEl 20       /* MaxEl adalah ukuran maksimum table penampung */

typedef char infotype;
typedef struct {
	infotype T[MaxEl]; /* tabel penyimpan elemen */
	int TOP;           /* alamat TOP: elemen puncak */
} Stack;

/*** Konstruktor/Kreator ***/
void CreateEmpty (Stack *S){
    (*S).TOP = Nil;
}

/* Predikat Untuk test keadaan KOLEKSI */
bool IsEmpty (Stack S){
    return ( (S).TOP == Nil );
}

bool IsFull (Stack S){
    return( (S).TOP == MaxEl );
}


/* Menambahkan sebuah elemen ke Stack */
void Push (Stack *S, infotype X) {
    if(!IsFull(*S)){
        (*S).TOP++;
        (*S).T[(*S).TOP]=X;
    } else {
        cout<<"\nStack Penuh\n";
    }
}


/* Menghapus sebuah elemen Stack */
void Pop (Stack *S) {
    if(!IsEmpty(*S)){
        (*S).TOP--;
    } else {
        cout<<"\nStack Kosong\n";
    }
}

void OutStack (Stack S){
    for (int i = 0; i<=(S).TOP; i++){
        cout<<(S).T[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Stack data;
    string w;
    int n;

    cin>>n;

    for (int i = 0; i<n; i++){
        CreateEmpty(&data);
        cin>>w;
        for(int j = 0; j < w.length(); j++){
            if(w[j]=='1'||w[j]=='2'||w[j]=='3'||w[j]=='4'||w[j]=='5'||w[j]=='6'||w[j]=='7'||w[j]=='8'||w[j]=='9'||w[j]=='0'){
                Push(&data, w[j]);
            } else if (w[j]=='_'){
                Pop(&data);
            }
        }
        OutStack(data);
    }
}
