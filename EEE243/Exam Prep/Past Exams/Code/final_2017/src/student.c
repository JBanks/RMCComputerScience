/*
 *
 *	This file is where you implement the functions to solve the problems posed to
 *	you in the exam booklet.
 *
 *	Ce fichier est l'endroit ou vous implementez les fonctions pour resoudre les
 *	probleme qui vous sont poses dans l'examen
 *
 * Author/Auteur: YOUR NAME / VOTRE NOM
 * Col Num/No Col: YOUR COLLEGE NUMBER / VOTRE NUMERO DE COLLEGE
 *
 * Version: 30 Nov 2017
 *
 */
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "student.h"

/*
 * Function to implement for question 1.
 *
 * Fonction a implementer pour la question 1.
 *
 */
enum StdCol convert_col(unsigned char color[3]) {
	
	enum StdCol color_8;

	int red = (color[0] > COLOR_THRES);
	int green = (color[1] > COLOR_THRES);
	int blue = (color[2] > COLOR_THRES);

	if (red) {
		if (green) {
			if (blue) {
				color_8 = WHITE;
			} else {
				color_8 = YELLOW;
			}
		} else {
			if (blue) {
				color_8 = MAGENTA;
			} else {
				color_8 = RED;
			}
		}
	} else {
		if (green) {
			if (blue) {
				color_8 = CYAN;
			} else {
				color_8 = GREEN;
			}
		} else {
			if (blue) {
				color_8 = BLUE;
			} else {
				color_8 = BLACK;
			}
		}
	}

	return color_8;
}

/*
 * Function to implement for question 2.
 *
 * Fonction a implementer pour la question 2.
 *
 */
struct Action *add_node(struct Action *new, struct Action *current) {
	struct Action *temp = NULL;
	if (current != NULL) {
		temp = current->next;
		current->next = new;
		new->prev = current;
	}
	if (temp != NULL) {
		delete_following_action(temp);
	}
	return new;
}

/*
 * Function to implement for question 2.
 *
 * Fonction a implementer pour la question 2.
 *
 */
void delete_following_action(struct Action *entry_point) {
	if (entry_point->next != NULL){
		delete_following_action(entry_point->next);
	}
	free(entry_point);
}

/*
 * Function to implement for question 2.
 *
 * Fonction a implementer pour la question 2.
 *
 */
struct Action *undo(struct Action *current) {
	current = current->prev;
	return current;
}

/*
 * Function to implement for question 2.
 *
 * Fonction a implementer pour la question 2.
 *
 */
struct Action *redo(struct Action *current) {
	current = current->next;
	return current;
}

/*
 * Function to implement for question 3.
 *
 * Fonction a implementer pour la question 3.
 *
 */
unsigned int *generate_histogram(unsigned char image[IMG_SIZE][IMG_SIZE],
		unsigned char range) {
	unsigned int* intensity = (int*)calloc(256, sizeof(int));
	for (int i = 0; i < IMG_SIZE; i++){
		for (int j = 0; j < IMG_SIZE; j++){
			intensity[image[i][j]]++;
		}
	}

	return intensity;
}

/*
 * Function to implement for question 4.
 *
 * Fonction a implementer pour la question 4.
 *
 */
void find_replace_str(char *str, char *replace, char *input, char *output) {
	//I have not tested this function yet, I wrote out a skeleton to get my ideas down.
	int search_length = strlen(str);
	char c;
	FILE* in = fopen(input, "r");
	FILE* out = fopen(output, "w");
	int matched_letters = 0;
	int i = 0;
	while((c=fgetc(in)) != EOF) {
		if (c = str[0]){
			i = 0;
			while ((c=fgetc(in)) == str[i] && i < search_length){
				i++;
			}
			if (i == search_length){
				fputs(replace, out);
			} else {
				for (int j = 0; j <= i; j++){
					fputc(str[j], out);
				}
			}
		} else {
			fputc(c, out);
		}
	}
	fclose(in);
	fclose(out);
}
