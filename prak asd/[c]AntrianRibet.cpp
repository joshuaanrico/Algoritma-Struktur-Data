#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct Node* address;
typedef struct Node {
    infotype x;
    address next;
}List;

typedef struct {
    address head;
    address tail;
}Queue;

void createempty(Queue *Q) {
    Q->head= NULL;
    Q->tail= NULL;
}

address alokasi (infotype x) {
    address P = address(malloc(sizeof(List)));
    
    if(P!=NULL) {
        P->x = x;
        P->next = NULL;
    }
    
    return P;
}

void dealokasi(address P) {
    P->next = NULL;
    free(P);
}

void Add(Queue *Q, infotype x) {
    address P = alokasi(x);
    if(P!=NULL) {
        if(Q->head==NULL && Q->tail==NULL) Q->head = P;
        else Q->tail->next=P;
        Q->tail = P;
    }
}

void Del(Queue *Q, infotype *x) {
    if(Q->head != NULL && Q->tail != NULL){
        *x = Q->head->x;
        if(Q->head == Q->tail){
            dealokasi(Q->head);
            createempty(Q);
            return;
        }
        address P = Q->head;
        Q->head = Q->head->next;
        dealokasi(P);
    }
}

void print(Queue Q) {
    address P = Q.head;
    cout << '[';
    if(P!=NULL) {
        while(P->next != NULL) {
            cout << P->x << ",";
            P = P->next;
        }
        cout << P->x;
    }
    cout <<"]"<<endl;
}

int main () {
    int A, B, C, D, ambil, j;
    Queue Q[3];
    createempty(&Q[0]);
    createempty(&Q[1]);
    createempty(&Q[2]);
    
    cin >> A;
    
    for(int i=0; i<A; i++) {
        cin >> B;
        for(j=0; j<3; j++) {
            if(Q[j].tail==NULL) {
                Add(&Q[j], B);
                j=100;
            } else if(B>= Q[j].tail->x) {
                Add(&Q[j], B);
                j=100;
            }
        }
        if(j==3) {
            D = 0;
            C = Q[0].head->x;
            for(int i=0; i<3; i++) {
                if(C>Q[i].head->x) {
                    D = i;
                    C = Q[i].head->x;
                }
            }
            Del(&Q[D], &ambil);
        }
    }
    int sum = 0;
    while(sum < 3) {
        cout << "Antrian "<< sum+1 <<":";
        print(Q[sum]);
        sum++;
    }
}
