#include "Min_Heap.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>



struct Min_Heap* create_heap(int cap){

	struct Min_Heap* h = malloc(sizeof(struct Min_Heap));
	if(h == NULL){
		printf("There was a problem while creating the Heap\n");
		return NULL;
	}

	h->capacity = cap;
	h->size = 0;

	h->n = malloc(cap * sizeof(struct node*));
	if(h->n == NULL){
		printf("There was a problem while creating the Heap\n");
		return NULL;
	}
	
	printf("The Heap was created successfuly");

	return h;
}
void bubble_up(struct Min_Heap* h){

	int index = h->size;
	int parent = (index - 1) / 2;
	while(index != 0 && h->n[index]->frequency < h->n[parent]->frequency){
		
		struct node* temp = h->n[index];
		h->n[index] = h->n[parent];
		h->n[parent] = temp;

		index = parent;
		parent = (index - 1) / 2;
	}
}
void bubble_down(struct Min_Heap* h, int index){

	int smallest = index;
	int left = 2 * index + 1;
        int right = 2* index + 2;

	if(left < h->size && h->n[left]->frequency < h->n[smallest]->frequency) smallest = left;

	if(right < h->size && h->n[right]->frequency < h->n[smallest]->frequency) smallest = right;	

	if(smallest != index){
	
		struct node* temp = h->n[index];
		h->n[index] = h->n[smallest];
		h->n[smallest] = temp;

		bubble_down(h, smallest);
	}

}
void add_node(struct Min_Heap* h, struct node* node){

	h->n[h->size] = node;
	bubble_up(h);
	h->size += 1;

	printf("The node was added successfuly to the Heap\n");
}
struct node* pop_node(struct Min_Heap* h){
	
	if(h->size > 0){
		struct node* n = h->n[0];
		h->n[0] = h->n[h->size - 1];
		h->size -= 1;
		bubble_down(h, 0);
		return n;
	}else return NULL;	
}
int heap_size(struct Min_Heap* h){
	return (h->size);
}
void delete_heap(struct Min_Heap* h){

	for(int i = 0; i < h->size; i++) free(h->n[i]);
	free(h->n);
	free(h);

	printf("The heap was deleted successfuly\n");
}
