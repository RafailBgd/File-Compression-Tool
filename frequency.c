#include "frequency.h"
#include <stdio.h>



int* get_frequency(char* name, int* array){

	for(int i = 0; i < 256; i++) *(array+i) = 0;

	FILE* fptr = fopen(name, "rb");

	if(fptr == NULL){
		printf("There was a problem while opening the file...\n");
		return NULL;
	}

	int count = 0;
	while(count != -1){
	
		count = fgetc(fptr);
		if(count != -1) *(array + count) += 1;
	}

	fclose(fptr);

	return array;


}
