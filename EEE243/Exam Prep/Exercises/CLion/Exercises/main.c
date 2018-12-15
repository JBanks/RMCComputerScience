#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 20

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
    int word_position = 0;
    char c;
    size_t length;
    line[0] = 0;

    while ((c = (char)fgetc(in)) != EOF){
        if (c == ' '){
            word[word_position] = '\0'; //place null terminator

            if (strlen(word) + strlen(line) + 1 > LINE_LENGTH){ //check string length and +1 for space
                //START A NEW LINE
                printf("'%-20s'\n", line); //print out line
                strcpy(line, word); //replace line with new word

            } else {
                //APPEND STRING
                length = strlen(line);
                if (length > 0){
                    line[length+1] = '\0'; //place a new null terminator with space for char
                    line[length] = c;
                }
                strcat(line, word); //append the new word to the string
            }
            word_position = 0; //start a new word

        } else {

            word[word_position++] = capitalize(c);

        }
    }
}