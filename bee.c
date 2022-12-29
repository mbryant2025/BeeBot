#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int hasLetters(char *str, char *letters) {

    if (strlen(str) < 5) {
        return 0;
    }

    char key_letter = letters[0];

    int contains_key = 0;
    for (int i = 0; i < strlen(str) - 1; i++) {
        if (str[i] == key_letter) {
            contains_key = 1;
        }
        int letter_in = 0;    
        //check if the letter is in letters
        for (int j = 0; j < strlen(letters); j++) {
            if (str[i] == letters[j]) {
                letter_in = 1;
            }
        }
        if (letter_in == 0) {
            return 0;
        }
    }
    if (contains_key) {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {

    if (argc != 2 || strlen(argv[1]) != 7) {
        printf("Usage: ./bee <letters>\n");
        return 1;
    }

    char *letters = argv[1];

    char const* const fileName = "words.txt";

    FILE* file = fopen(fileName, "r"); 

    char line[256];

    char** validWords = malloc(10000 * sizeof(char*));

    while (fgets(line, sizeof(line), file)) {
        if (hasLetters(line, letters)) {
            //put line in validWords
            int i = 0;
            while (validWords[i] != NULL) {
                i++;
            }
            validWords[i] = malloc(strlen(line) * sizeof(char));
            strcpy(validWords[i], line);
        }
    }

    fclose(file);

    //sort validWords by length
    int i = 0;
    while (validWords[i] != NULL) {
        int j = i + 1;
        while (validWords[j] != NULL) {
            if (strlen(validWords[i]) > strlen(validWords[j])) {
                char* temp = validWords[i];
                validWords[i] = validWords[j];
                validWords[j] = temp;
            }
            j++;
        }
        i++;
    }

    //print validWords
    int k = 0;
    int totalScore = 0;
    while (validWords[k] != NULL) {
        printf("%s", validWords[k]);
        int l = strlen(validWords[k]) - 1;
        if (l == 4) {
            totalScore += 1;
        } else {
            totalScore += l;
        }
        k++;
    }
    printf("Total score: %d\n", totalScore);

    return 0;
}
