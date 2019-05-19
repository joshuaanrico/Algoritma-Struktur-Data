#include <iostream>
using namespace std;

#define NULL 0
#define MaxEl 10

typedef int infotype;
typedef int address;
typedef struct {
	infotype Data[MaxEl+1];
	address TOP;
}stack;

#define TOP(S) (S).TOP
#define InfoTOP(S) (S).Data[(S).TOP]

void CreateEmpty(stack *S) {
	TOP(*S) = NULL;
}
bool IsEmpty(stack S){
	return (TOP(S) == NULL);
}

bool IsFull(stack S) {
	return (TOP(S) == MaxEl);
}

void Push(stack *S, infotype X){
	if(!IsFull(*S)){
		TOP(*S)++;
		InfoTOP(*S)=X;
	}else{
		cout << "Stack is Full !";
	}
}

void Pop(stack *S, infotype *X){
	if(!IsEmpty(*S)){
		*X = InfoTOP(*S);
		TOP(*S)--;
	}else{
		cout << "Stack Kosong !";
	}
}

int main () {
	cout<<"aksoasko";
}


