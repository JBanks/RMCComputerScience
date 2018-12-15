#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct CATALOG_NODE {
	char product[30];
	float price;
	struct CATALOG_NODE* next;
} Catalog;

Catalog* new_node() {
	Catalog* p_temp = (Catalog*) malloc(sizeof(Catalog));
	p_temp->next = NULL;
	return p_temp;
}

Catalog* add_to_beginning(Catalog* p_head, Catalog* p_temp) {
	p_temp->next = p_head;
	return p_temp;
}

Catalog* insert_in_order(Catalog* p_head, Catalog* p_new) {
	Catalog* p_walker = p_head;
	if (p_head == NULL){
		return add_to_beginning(p_head, p_new);
	}
	if (strcmp(p_walker->product, p_new->product) > 0) {
		return add_to_beginning(p_head, p_new);
	}
	while (p_walker->next != NULL && strcmp(p_walker->next->product, p_new->product) < 0) {
		p_walker = p_walker->next;
	}
	p_new->next = p_walker->next;
	p_walker->next = p_new;
	return p_head;
}

Catalog* delete_node(Catalog* p_walker, char * product) {
	Catalog* p_head = p_walker;
	Catalog* p_temp;
	if (p_head == NULL){
		return p_head;
	}
	if (!strcmp(p_head->product, product)){
		p_head = p_head->next;
		free(p_walker);
		return p_head;
	}
	while (p_walker->next != NULL){
		if (!strcmp(p_walker->next->product, product)) {
			p_temp = p_walker->next;
			p_walker->next = p_walker->next->next;
			free(p_temp);
			return p_head;
		}
		p_walker = p_walker->next;
	}
	return p_head;
}

void populate(Catalog* p_node, char * product, float price) {
	strcpy(p_node->product, product);
	p_node->price = price;
}

void print_product(Catalog* p_node){
	printf("Product: %-20s -> Price: $%8.2f\n", p_node->product, p_node->price);
}

void print_list(Catalog* p_walker) {
	if (p_walker != NULL) {
		do {
			print_product(p_walker);
		} while ((p_walker = p_walker->next) != NULL);
	}
}

Catalog* search_node(Catalog* p_walker, char* search_string) {
	while (p_walker != NULL) {
		if (!strcmp(p_walker->product, search_string)){
			break;
		}
		p_walker = p_walker->next;
	}
	return p_walker;
}

int main(void) {
	Catalog* p_head = NULL;
	Catalog* p_new = new_node();
	//Catalog* p_temp = NULL;

	Catalog* (*insert_element)(Catalog* p_head, Catalog* p_new) = &add_to_beginning;

	populate(p_new, "X-Wing Fighter", 10.01);
	p_head = insert_element(p_head, p_new);

	p_new = new_node();
	populate(p_new, "Millennium Falcon", 435.67);
	p_head = insert_element(p_head, p_new);

	p_new = new_node();
	populate(p_new, "Lightsaber", 99.95);
	p_head = insert_element(p_head, p_new);

	p_new = new_node();
	populate(p_new, "Death Star", 5895.32);
	p_head = insert_element(p_head, p_new);

	p_new = new_node();
	populate(p_new, "R2D2", 23.75);
	p_head = insert_element(p_head, p_new);

	p_new = new_node();
	populate(p_new, "Z-Object", 23.75);
	p_head = insert_element(p_head, p_new);

	p_head = delete_node(p_head, "Death Star");
	p_head = delete_node(p_head, "Death Star");

	print_list(p_head);

	/*p_temp = search_node(p_head, "R2D2");
	if (p_temp){
			print_product(p_temp);
	}
	else {printf("%s pas trouve!\n", "R2D2");}

	p_temp = search_node(p_head, "Millennium Falcon");
	if (p_temp){
			print_product(p_temp);
	}
	else {printf("%s pas trouve!\n", "Millennium Falcon");}

	p_temp = search_node(p_head, "Death Star");
	if (p_temp){
			print_product(p_temp);
	}
	else {printf("%s pas trouve!\n", "Death Star");}*/

	return EXIT_SUCCESS;
}


