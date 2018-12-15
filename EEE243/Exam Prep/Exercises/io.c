#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 20

/*
int get_word(char * word){
	int word_position = 0;
	char c;
	const FILE* in = fopen("lorem.txt", "r");
	if ((c = fgetc(in)) == EOF){
		return -1;
	} else if (c == ' ') {
		return 1;
	} else {
		word++ = capitalize(c);
	}
}

int get_line(char * line){
	static char word[LINE_LENGTH];
	int length;
	while ((result = get_word(word)) != -1){
		if (strlen(line) + strlen(word) > LINE_LENGTH - 1){
			return 1;
		} else {
			length = strlen(line);
			if (length > 0){
					line[length+1] = '\0';
					line[length] = c;
			} else {
				line[length] = '\0';
			}
			strcat(line, word);
		}
	}
	return 0;
}*/

char capitalize(char c){
	if (c >= 'a' && c <= 'z'){
		c += 'A'-'a';
	}
	return c;
}

int main(void) {
	FILE* in = fopen("lorem.txt", "r");
	//FILE* out = fopen("out.txt", "w");

	char line[LINE_LENGTH];
	char word[LINE_LENGTH];
	char* space = " ";
	int word_position = 0;
	char c;
	int length;
	line[0] = 0;

	while ((c=fgetc(in)) != EOF){
		if (c == ' '){
			word[word_position] = '\0'; //place null terminator

			if (strlen(word) + strlen(line) + 1 > LINE_LENGTH){ //check string length and +1 for space
			//START A NEW LINE
				printf("'%-20s'\n", line); //print out line
				strcpy(line, word); //replace line with new word

			} else {
			//APPEND STRING
				if (strlen(line)) {
					strcat(line, space); //add a space to the line.
				}
				strcat(line, word); //append the new word to the string
			}
			word_position = 0; //start a new word

		} else {

			word[word_position++] = capitalize(c);

		}
	}
	return EXIT_SUCCESS;
}
