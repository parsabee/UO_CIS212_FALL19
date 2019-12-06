#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
	int data;
	Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void addNode (int data) {
	Node *cur_node = (Node *)malloc(sizeof(Node));
	cur_node->data = data;
	cur_node->next = NULL;

	if (tail == NULL)
		tail = cur_node;
	if (head != NULL)
		head->next = cur_node;
	head = cur_node;

}

void printLL () {
	Node *tmp = tail;
	while (tmp != NULL) 
	{
		printf("node : %d\n",tmp->data );
		tmp = tmp->next;
	}
}

int main () {

	int arr [5] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++) {
		addNode(arr[i]);
	}

	printLL ();
}
