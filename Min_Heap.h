#ifndef MIN_HEAP_H
#define MIN_HEAP_H

struct Min_Heap{

	struct node** n;
	int capacity;
	int size;
};

struct Min_Heap* create_heap(int cap);

void buubble_up(struct Min_Heap* h);

void bubble_down(struct Min_Heap* h, int index);

void add_node(struct Min_Heap* h, struct node* n);

struct node* pop_node(struct Min_Heap* h);

int heap_size(struct Min_Heap* h);

void delete_heap(struct Min_Heap* h);

#endif
