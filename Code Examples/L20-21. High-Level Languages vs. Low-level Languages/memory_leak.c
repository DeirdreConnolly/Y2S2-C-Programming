

#include <stdio.h>
#include <stdlib.h>

//------------------------------
// myNode definition
//------------------------------
struct Node {
	int myInfo;
	struct Node* myNext;
};

typedef struct Node myNode;

//--------------------------------------//
//	main								//	
//--------------------------------------//
int main() {
	myNode* head = (myNode*)malloc(1 * sizeof(myNode));
	head->myInfo = 5;
	head->myNext = NULL;

	myNode* aux = (myNode*)malloc(1 * sizeof(myNode));
	aux->myInfo = 4;
	aux->myNext = head;
	head = aux;
	aux = NULL;

	aux = (myNode*)malloc(1 * sizeof(myNode));
	aux->myInfo = 3;
	aux->myNext = head;
	head = aux;
	aux = NULL;

	printf("%d\n", head->myInfo);

	head = (myNode*)malloc(1 * sizeof(myNode));
	head->myInfo = 7;
	head->myNext = NULL;

	printf("%d\n", head->myInfo);

	return 0;

}

