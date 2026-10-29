#include <stdio.h>
#include <stdlib.h>
#include "frequency.h"
#include "Min_Heap.h"
#include "node.h"

int main(int argc, char* argv[]){

	if(argc != 2){
		
		printf("Please enter the name of youre file\n");
		return 1;
	}

	int ASCII[256];
	int* ptr = ASCII;
	struct node** n = malloc(256 * sizeof(struct node*));

	if(n == NULL) return -3;

	ptr = get_frequency(argv[1], ptr);

	for(int i = 0; i < 256; i++){ 
	
		if(ptr[i] > 0){ 
			printf("%c : %d\n", i, *(ptr + i));
			n[i] = create_node(i, ptr[i], NULL, NULL);
			if(n[i] == NULL){
				printf("There was a problem while creating the nodes.\n");
				return -2;
			}
		}
	}

	struct Min_Heap* h = create_heap(256);
	if(h == NULL){
		printf("There was a problem when creating the heap\n");
		return -1;
	}

	for(int i = 0; i < 256; i++){
		add_node(h, n[i]);
	}

	struct node* n1;

	while(heap_size(h) > 0){
		n1 = pop_node(h);
		if(n1 != NULL){
			printf("%c: %d\n", n1->data, n1->frequency);
		}
	}

	delete_heap(h);

	return 0;
}
