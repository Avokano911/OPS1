#include <stdio.h>
#include <stdlib.h>

// pthread variables
void* volidate_rows(void* arg);
void* volidate_cols(void* arg);
void* validate_diagonals(void* arg); // check two paralell lines
void* validate_uniquness(void* arg);

// global variables
int **matrix;
int n;
int score = 0;
pthread_mutex_t lock;
pthread_t thread1;


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

    pthread_mutex_init(&lock, NULL);
    

}