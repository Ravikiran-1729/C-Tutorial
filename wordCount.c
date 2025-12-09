#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#define MAX_WORDS 1000 
#define MAX_LENGTH 50 
 
struct wordCount 
{ 
    char word[MAX_LENGTH]; 
    int count; 
}; 
 
void toLowerCase(char *str){ 
    for(int i = 0; str[i]; i++){ 
        str[i] = tolower((unsigned char)str[i]); 
    } 
} 
void printResult(int wordcount, struct wordCount *words){ 
    for(int i = 0; i<wordcount; i++){ 
        printf("%s : %d\n", words[i].word, words[i].count); 
    } 
} 
 
void countWordOccurrences(char text[]){ 
    char *token = strtok(text, " ,.-!?;\n\t"); 
 
    struct wordCount words[MAX_WORDS]; 
 
    int wordcount = 0; 
 
    while (token != NULL)    
    { 
        toLowerCase(token); 
         
        int found = 0; 
        for(int i = 0; i<wordcount; i++){ 
            if(strcmp(words[i].word, token) == 0){ 
                words[i].count++; 
                found = 1; 
                break; 
            } 
        } 
        if(!found && wordcount<MAX_WORDS){ 
            strcpy(words[wordcount].word, token); 
            words[wordcount].count = 1; 
            wordcount++; 
        } 
        token = strtok(NULL, " ,.-!?;\n\t"); 
    } 
    printResult(wordcount, words); 
     
} 
 
int main(){ 
    char text[] = "This is a sample text. It contains sample words, some of which are repeated."; 
 
    countWordOccurrences(text); 
}