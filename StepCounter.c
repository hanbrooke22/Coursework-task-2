#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }

int main() {


int count = 0; 
char array[100];
char fewest = "", largest = "", end = "", start = ""; 
float mean = 0; 

while(1){

   printf("A: Input file name");
   printf("B: Total number of records");
   printf("C: Fewest steps");
   printf("D: Largest number of steps");
   printf("E: Mean step count");
   printf("F: Longest period of step count above 500");
   printf("Q: Quit");

char choice; 

choice = getchar();

while (getchar() != '\n');{

switch (choice)
        {
        
        case 'A':
        case 'a':
        
        char filename; 
            printf("Input filename: ");
            scanf("%s", filename);

            FILE *file = fopen(filename, "r");
            if (!file){
            printf("Error: File could not be opened\n");
        }
        
            break;

        case 'B':
        case 'b':

            while (fgets(array, 100, file)){
                count++; 
            }

            printf("Total records: %d\n", count); 
            break;

        case 'C':
        case 'c':
            
            printf("Fewest steps: %s\n", fewest);
            break;

        case 'D':
        case 'd':

            printf("Largest steps: %s\n", largest);
            break;

        case 'E':
        case 'e':

            printf("Mean step count: %.0f", mean);
            break;

        case 'F':
        case 'f':

            printf("Longest period start: %s\n", start); 
            printf("Longest period end: %s\n", end); 
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
    }
}




