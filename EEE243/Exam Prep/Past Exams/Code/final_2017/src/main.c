/*
 * This is the file where you can test the functions you implemented. This
 * file will not be marked.
 *
 * Il s'agit du fichier ou vous pouvez tester les fonctions que vous avez
 * implementees. Ce fichier ne sera pas corrige.
 *
 * Author/Auteur: Capt A. Lapointe
 * Version: 30 Nov 2017
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "sphere.h"
#include "student.h"
#include "support.h"

// Base for tests
void test_q1(); //Q1
void test_q2(); //Q2
void test_q3(); //Q3
void test_q4(); //Q4

int main() {

	test_q1();
//	test_q2();
//	test_q3();
//	test_q4();

	return EXIT_SUCCESS;
}

//Q1
void test_q1() {
	unsigned char colors[11][3] = { { 0, 0, 0 }, { 255, 255, 255 },
			{ 255, 0, 0 }, { 0, 255, 0 }, { 0, 0, 255 }, { 255, 255, 0 }, { 255,
					0, 255 }, { 0, 255, 255 }, { 100, 0, 0 }, { 200, 100, 0 }, {
					200, 200, 200 } };

	enum StdCol col;

	for (int i = 0; i < 11; i++) {
		col = convert_col(colors[i]);
		display_color(colors[i], col);
	}
}

// Q2
void test_q2() {
	struct Action *history = NULL;
	struct Action *current = NULL;
	history = create_original(); //add_node(create_Action(), current);
	current = history;

	for (int i = 0; i < 5; i++) {
		current = add_node(create_Action(), current);
	}
	print_column_headings();
	print_list(history, current);

	// We undo an action
	current = undo(current);
	printf("\n\nUndo action\n");
	print_column_headings();
	print_list(history, current);

	// We redo an action
	current = redo(current);
	printf("\n\nRedo action\n");
	print_column_headings();
	print_list(history, current);

	// We do a new action
	printf("\n\nWe do a new action\n");
	current = add_node(create_Action(), current);
	print_column_headings();
	print_list(history, current);
	current = undo(current);

	// We undo an action
	printf("\n\nUndo action\n");
	print_column_headings();
	print_list(history, current);
	current = undo(current);

	// We undo an action
	printf("\n\nUndo action\n");
	print_column_headings();
	print_list(history, current);

	// We do a new action
	printf("\n\nWe do a new action\n");
	current = add_node(create_Action(), current);
	print_column_headings();
	print_list(history, current);
}

// Q3
void test_q3() {
	unsigned int *histogram = generate_histogram(img, 255);
	show_histogram(histogram, 255);
}

//Q4
void test_q4() {
	char *input = "../lorem.txt";
	char *output = "../modified.txt";
	char *final = "../final.txt";

	find_replace_str(",  ", ", ", input, output);
	find_replace_str(".  ", ". ", output, final);

}

