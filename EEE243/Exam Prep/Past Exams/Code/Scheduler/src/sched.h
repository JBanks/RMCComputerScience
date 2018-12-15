/* DO NOT MODIFY THIS FILE | NE MODIFIEZ PAS CE FICHIER */

#ifndef SCHED_H_
#define SCHED_H_

#define MEM_SIZE_GB 16
#define MAX_PROG_SIZE_KB 1000000
#define NUM_QUEUES 3


typedef enum { BACKGROUND, INTERACTIVE, REALTIME } ProcType;

typedef struct PROC {
	char PID[5];
	char program[20];
	ProcType type;
	unsigned int priority;
	float size_kb;
	struct PROC *next;
	struct PROC *prev;
} Process;


Process *create_process();
void print_column_headings();
void print_one_process(Process *node);

Process *add_in_order(Process *head, Process *new);
void print_queue(Process *head);
void add_to_queues(Process **queues, Process *new);
void print_all_queues(Process **queues);
Process *remove_process(Process **head);
void schedule(Process **queues);
float calculate_total_mem_GB(Process **queues);

#endif /* SCHED_H_ */
