/* YOUR NAME HERE | VOTRE NOM ICI */

#include <stdio.h>
#include <stdlib.h>

#include "sched.h"


int main() {
	Process* queues[3] = { NULL, NULL, NULL };
	calculate_total_mem_GB(queues);
	for (int i = 0; i < 20; i++){
		add_to_queues(queues, create_process());
	}
	print_all_queues(queues);
	schedule(queues);
	print_all_queues(queues);
	return EXIT_SUCCESS;
}

Process *add_in_order(Process *head, Process *new) {
	Process* p_walker = head;

	if (head == NULL) {
		new->next = head;
		return new;
	} 
	if (new->priority < head->priority) {
		new->next = head;
		head->prev = new;
		return new;
	}

	while (p_walker->next != NULL) {
		if (new->priority < p_walker->next->priority) {
			new->next = p_walker->next;
			new->prev = p_walker;
			p_walker->next->prev = new;
			p_walker->next = new;
			return head;
		}
		p_walker = p_walker->next;
	}

	p_walker->next = new;
	new->prev = p_walker;
	return head;
}

void print_queue(Process *head) {
	Process* p_walker = head;
	print_column_headings();

	while(p_walker != NULL){
		print_one_process(p_walker);
		p_walker = p_walker->next;
	}
}

void add_to_queues(Process **queues, Process *new) {

	printf("add_to_queues: calculate_total_mem_GB: %f\n", calculate_total_mem_GB(queues));
	if (calculate_total_mem_GB(queues) < MEM_SIZE_GB){
		queues[new->type] = add_in_order(queues[new->type], new);
	} else {
		printf("MEMORY FULL CANNOT ADD PROCESS!!!\n");
	}
}

void print_all_queues(Process **queues) {
	const char *type_names[3] = { "Background", "Interactive", "Real-Time" };
	for (int i = 0; i < 3; i++){
		printf("Processes under %s:\n", type_names[i]);
		print_queue(queues[i]);
	}
}

Process *remove_process(Process **head) {
	Process* temp;
	for (int i = REALTIME; i >= BACKGROUND; i--){
		if (head[i] != NULL) {
			temp = head[i];
			head[i] = temp->next;
			if (head[i]){
				head[i]->prev = NULL;
			}
			return temp;
		}
	}
	return NULL;
}

void schedule(Process **queues) {
	Process* temp;
	while ((temp = remove_process(queues)) != NULL) {
		printf("Removing process:\n");
		print_one_process(temp);
		free(temp);
	}
}

float calculate_total_mem_GB(Process **queues) {
	Process* p_walker;
	float Total_mem = 0;
	for (int i = REALTIME; i >= BACKGROUND; i--){
		p_walker = queues[i];
		while(p_walker != NULL){
			Total_mem += p_walker->size_kb;
			p_walker = p_walker->next;
		}
	}
	return Total_mem/1048576;	
}
