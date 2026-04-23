#include <stdio.h>
#include <stdlib.h>
#include "validate_uniquness.c"
#include "validate_diagonals.c"
#include "validate_rows.c"
#include "validate_cols.c"

// pthread variables
void* validate_rows(void* arg);
void* validate_cols(void* arg);
void* validate_diagonals(void* arg); // check two paralell lines
void* validate_uniquness(void* arg);

// global variables
int **matrix;
int n;
int score = 0;
int magic_val = 0;
pthread_mutex_t lock;
pthread_t thread1;

//
extern int diagonal_result[];
extern int col_result[];
extern int row_result[];
extern int C_val[];


int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("Invaild file name !", argv[0]);
        return 1;
    }

    // Reading file 
    FILE *file = fopen(argv[1],"r");
    if (file == NULL) {
        perror("File open error");
        return 1;
    }

    // reading n 

    fscanf(file, "%d", &n);
    printf("The size is %d\n", &n);

    //  allocating memory and reading it into
    matrix = (int **)malloc(n * sizeof(int *));
    magic_val = n * (n * n + 1) / 2;
    // loopt n * n
    for(int i=0; i < n; i++){
        matrix[i] = (int *)malloc(n * sizeof(int));
        for(int j=0; j < n; j++){
        fscanf(file, "%d", &matrix[i][j]);
        }
    }

    printf("Matrix diagram:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    // initialize mutex
    pthread_mutex_init(&lock, NULL);
    

    // creatinng thread to run
    pthread_t thread1, thread2, thread3, thread4;

    pthread_create(&thread1, NULL, validate_cols, NULL);
    pthread_create(&thread2, NULL, validate_rows, NULL);
    pthread_create(&thread3, NULL, validate_diagonals, NULL);
    pthread_create(&thread4, NULL, validate_uniquness, NULL);

    // Wait for thread to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    //print each thread completion
    printf("Thread ID-[%lu] completed Rows\n", (unsigned long)thread1);
    printf("Thread ID-[%lu] completed cols\n", (unsigned long)thread2);
    printf("Thread ID-[%lu] completed diagonals\n", (unsigned long)thread3);
    printf("Thread ID-[%lu] completed uniquness\n", (unsigned long)thread4);


    printf("\n----- Magic Square Report ----\n");

    // Rows check
    //row_result[]
    int result = 1;
    for (int i=0; i < n; i++){

        if (row_result[i] == 0){

            printf(" Rows:   Row %d Invalid\n", i + 1);
            result = 0;
        }
    }

    if (result == 1){

        printf(" Rows:   All Valid\n");
    }

    // Cols check
    //cols_result[]
    result = 1;
    for(int i = 0; i < n; i++){

        if (cols_result[i] == 0){

            printf(" Cols:    Col %d Invalid\n", i + 1);
            result = 0;
        }
    }

    if ( result == 1) {

        printf(" Cols:   All Valid\n");
        result = 0;

    }

    // validate diagonals check
    result = 1;

    // Main (leftup to rightdown)
    //diagonal_result[0];

    if ( diagonal_result[0] == 0){

        printf(" Diags: Main Diag Invalid");
        result = 0;
    }

    if ( diagonal_result[1] == 0){

        printf( " Diags: Second Diag Invalid");
        result = 0;
    }

    if ( result == 1) {

        printf(" Diags: All Valid\n");

    }

    // uniqueness check

    result = 1;

    for (int i=0; i < n; i++){
        
        if (C_val[i] == 0){

            printf(" Unique: Faild ( Duplicates found )\n");
            result = 0;
        } 
    }

    if (result == 1){

        printf(" Unique:  Passed \n");

    }

    // Final Score 

    int Final_Maximum_S = (n * 2) + 2 + 1; 

    printf( "Final Score:   %d / %d ", score, Final_Maximum_S);

    // RESULT

    if ( score == Final_Maximum_S ){

        printf(" RESULT:  VALID MAGIC SQUARE ");

    } else {

        printf(" RESULT:  INVALID MAGIC SQUARE ");

    }


    
}