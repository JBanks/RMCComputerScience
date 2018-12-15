#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void print_array(char * array_name, int* array){
	printf("%s:\n", array_name);
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%d, ", array[i]);
	}
	puts("\n");
}

int* add_arrays(int array_size, int* first_array, int* second_array, int* result_array) {
	int * smallest = result_array;
	for (int i=0; i< array_size; i++){
		result_array[i] = first_array[i] + second_array[i];
		if (result_array[i] < *smallest){
			smallest = &result_array[i];
		}
	}
	return smallest;
}

int main(void){
/*
	int num = 5;
	int * p_int;

	printf("num: %d\n"
		"&num: %p\n"
		"p_int: %p\n"
		"&p_int: %p\n\n", num, &num, p_int, &p_int);

	p_int = &num;

	printf("num: %d\n"
		"&num: %p\n"
		"p_int: %p\n"
		"&p_int: %p\n"
		"*p_int: %d\n\n", num, &num, p_int, &p_int, *p_int);

	int ** pp_int = &p_int;

	printf("pp_int: %p\n"
		"&pp_int: %p\n"
		"*pp_int: %p\n"
		"**pp_int: %d\n\n", pp_int, &pp_int, *pp_int, **pp_int);
*/
	int first_array[ARRAY_SIZE] = {6, 1, 3, 8, 6, 7, 5, 3, 0, 9};
	int second_array[ARRAY_SIZE] = {0};
	int result_array[ARRAY_SIZE] = {0};

	for (int i=0; i<ARRAY_SIZE; i++){
		second_array[i] = 20-i;
	}

	print_array("First", first_array);
	print_array("Second", second_array);
	print_array("Result", result_array);
	int * smallest;
	smallest = add_arrays(ARRAY_SIZE, first_array, second_array, result_array);

	print_array("First", first_array);
	print_array("Second", second_array);
	print_array("Result", result_array);

	printf("result_array address: %p\n" 
		"smallest result value: %d\n"
		"smallest value address: %p\n"
		"size of int: %ld bytes\n", &result_array, *smallest, smallest, sizeof(int));

	return EXIT_SUCCESS;
}