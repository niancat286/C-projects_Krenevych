#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "file_work.h"

int input_array(double* data, size_t size){
    size_t i = 0;
    for(; i < size; i++){
        printf("Enter element %zu: ", i + 1);
        if(scanf("%lf", &data[i]) != 1){
            break; // Error reading input
        }
    }
    return i; // Success
}

void write_to_file(const char* filename, const double* data, size_t size){

    FILE* file = fopen(filename, "w");
    if(file == NULL){
        perror("Error opening file for writing");
        return;
    }

    for(size_t i = 0; i < size; i++){
        fprintf(file, "%lf\n", data[i]);
    }
    fclose(file);

}

int read_from_file(const char* filename, double* buffer, size_t size){
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        perror("Error opening file for reading");
        return -1; // Error
    }

    size_t i = 0;
    for(; i < size; i++){
        if(fscanf(file, "%lf", &buffer[i]) != 1){
            break; // Error or end of file
        }
    }
    fclose(file);
    return i; // Number of elements read

}


void write_to_file_binary(const char* filename, const double* data, size_t size){

    FILE* file = fopen(filename, "wb");
    if(file == NULL){
        perror("Error opening file for binary writing");
        return;
    }

    int res = fwrite(data, sizeof(double), size, file);
    if(res != size){
        perror("Error writing to binary file");
    }
    fclose(file);

}

int read_from_file_binary(const char* filename, double* buffer, size_t size){
    FILE* file = fopen(filename, "rb");
    if(file == NULL){
        perror("Error opening file for binary reading");
        return -1; // Error
    }
    int count = 0;
    while(!feof(file) && !ferror(file) && count < size){
        // Just to clear any errors
        double temp;    
        int res = fread(&temp, sizeof(double), 1, file);
        if(res < 1){
           break;
        }
        buffer[count++] = temp;
    }

    fclose(file);
    return count; // Number of elements read

}

void rewrite_abs(const char* filename, const char* new_filename, double threshold){

    FILE* file = fopen(filename, "rb");
    if(file == NULL){
        perror("Error opening source file for binary reading");
        return;
    }

    FILE* new_file = fopen(new_filename, "wb");
    if(new_file == NULL){
        perror("Error opening destination file for binary writing");
        fclose(file);
        return;
    }

    FILE* new_file2 = fopen("temp_file.dat", "wb");
    if(new_file2 == NULL){
        perror("Error opening destination file for binary writing");
        fclose(file);
        return;
    }


    double value;
    while(fread(&value, sizeof(double), 1, file) == 1){
        if(fabs(value) < threshold){
            if(fwrite(&value, sizeof(double), 1, new_file) != 1){
                perror("Error writing to destination file");
                break;
            }
            printf("Value %lf written to %s\n", value, new_filename);
        }
        else{
            if(fwrite(&value, sizeof(double), 1, new_file2) != 1){
                perror("Error writing to destination file");
                break;
            }
            printf("Value %lf written to temp_file.dat\n", value);
        }

    }

    fclose(file);
    fclose(new_file);
    fclose(new_file2);
    remove(filename);
    rename("temp_file.dat", filename);
    
}