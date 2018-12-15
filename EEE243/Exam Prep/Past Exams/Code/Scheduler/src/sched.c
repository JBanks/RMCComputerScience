/* DO NOT MODIFY THIS FILE | NE MODIFIEZ PAS CE FICHIER */

#include "sched.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_PROG 5
#define PROG_LEN 20

void last_4_of_ptr(void *p, char *buff);

const char programs[][PROG_LEN] = { "chrome.exe", "word.exe", "pwrpt.exe",
		"cmd.exe", "firefox.exe" };

Process *create_process() {
	static bool initialized = false;

	if (!initialized) {
		initialized = true;
		srand(time(0));
	}

	Process *process = (Process *) malloc(sizeof(Process));

	last_4_of_ptr(process, process->PID);

	strncpy(process->program, programs[rand() % NUM_PROG], 20);
	process->type = rand() % 3;
	process->priority = rand() % 100;
	process->size_kb = roundf(rand() % 5000000);
	process->next = NULL;
	process->prev = NULL;

	return process;
}

void last_4_of_ptr(void *p, char *buff) {
	char local_buffer[20];
	sprintf(local_buffer, "%p", p);
	strncpy(buff, local_buffer + strlen(local_buffer) - 4, 4);
	buff[4] = '\0';
}

void print_column_headings() {
	printf("%-5s   %-15s   %-15s   %-10s   %-10s   %-4s   %-4s\n", "PID",
			"Program", "Type", "Priority", "Size (kB)", "Prev", "Next");
	printf("-----   ---------------"
			"   ---------------   ----------   ----------   ----   ----\n");
}

void print_one_process(Process *node) {
	const char *type_names[3] = { "Background", "Interactive", "Real-Time" };
	const char *format = "%-5s   %-15s   %-15s   %10d   %10.0f   %-4s   %-4s\n";
	char next[5], prev[5];
	last_4_of_ptr(node->next, next);
	last_4_of_ptr(node->prev, prev);
	printf(format, node->PID, node->program, type_names[node->type],
			node->priority, node->size_kb, node->prev, node->next);
}
