#include "node.h"
#include <stdio.h>
#include <stdlib.h>




struct node* create_node(unsigned char byte, int freq, struct node* left, struct node* right){


	
	struct node* n = malloc(sizeof(struct node));

	if(n == NULL){
		printf("There was a problem when creating a node\n");
		return NULL;
	}

	n->data = byte;
	n->frequency = freq;
	n->left_child = left;
	n->right_child = right;

	printf("The node has been created successfuly\n");
	
	return n;
}


void delete_node(struct node* n){

	free(n);
	printf("The node has been deleted successfuly");
}
