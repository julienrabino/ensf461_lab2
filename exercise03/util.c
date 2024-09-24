#include "util.h"
#include <math.h>
int* read_next_line(FILE* fin) {
    // TODO: This function reads the next line from the input file
    // The line is a comma-separated list of integers
    // Return the list of integers as an array where the first element
    // is the number of integers in the rest of the array
    // Return NULL if there are no more lines to read
    
    char line[200];

    if (fgets(line,sizeof(line), fin)){
        char* token = strtok(line, ",");
        int count = 0;
        int * intArray = (int*)malloc(sizeof(int));
        if (intArray == NULL){
            fprintf(stderr, "Error allocating memory.\n");
            exit(1);
        }
        intArray[0] = 0;
        while (token!= NULL){
            count++;
            int num = atoi(token);
            int size = count+1;
            int* newArray = (int*)realloc(intArray, size*sizeof(int));


            if (newArray == NULL) {
                fprintf(stderr, "Error reallocating memory.\n");
                free(intArray); 
                exit(1);
        }
                intArray = newArray;
                intArray[count] = num;
                token = strtok(NULL, ",");

        }
        intArray[0]= count;
        return intArray;
    }
    return NULL;
}


float compute_average(int* line) {
    int sum = 0;
    for (int i = 1; i<=line[0]; i++){
        sum += line[i];
    }

    return ((float)sum/line[0]);
    // TODO: Compute the average of the integers in the vector
    // Recall that the first element of the vector is the number of integers

}


float compute_stdev(int* line) {
    // TODO: Compute the standard deviation of the integers in the vector
    // Recall that the first element of the vector is the number of integers
    float avg = compute_average(line);
    float sum = 0;
    for (int i = 1; i<line[0]+1; i++){
        float difference = (line[i]-avg)*(line[i]-avg);
        sum += difference;
    }

    float variance = sum/line[0];
    float std = sqrt(variance);
    return std;
}