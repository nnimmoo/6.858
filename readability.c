#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

// Function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void) {
    // Prompt the user for text input
    string text = get_string("Text: ");
    
    // Print the input text
    printf("%s\n", text);

    // Call the functions to count letters, words, and sentences
    int num_letters = count_letters(text);
    int num_words = count_words(text);
    int num_sentences = count_sentences(text);

    printf("%i letters\n", num_letters);
    printf("%i words\n", num_words);
    printf("%i sentences\n", num_sentences);

  
    // Calculate the Coleman-Liau index
    float L = (float) num_letters / num_words * 100;
    float S = (float) num_sentences / num_words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Round the index to the nearest integer
    int grade = (int)(index + 0.5);

    // Output the reading level
    if (grade >= 16) {
        printf("Grade 16+\n");
    } else if (grade < 1) {
        printf("Before Grade 1\n");
    } else {
        printf("Grade %i\n", grade);
}


    return 0;
}


int count_letters(string text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            count++;
        }
    }
    return count;
}
int count_words(string text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] != ' ' && (text[i + 1] == ' ' || text[i + 1] == '\0')) {
            count++;
        }
    }
    return count;
}

int count_sentences(string text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            count++;
        }
    }
    return count;
}



