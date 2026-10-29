#ifndef NODE_H
#define NODE_H



struct node{

	unsigned char data;
	int frequency;
	struct node* left_child;
	struct node* right_child;

};


struct node* create_node(unsigned char byte, int freq, struct node* left, struct node* right);

void delete_node(struct node* n);


#endif
