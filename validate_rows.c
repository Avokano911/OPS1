// validate_rows function
#include "Assignment.c"

int row_result[n];
int counts = 0;

void* validate_rows(void* arg);

void* validate_rows(void* arg){

    // calculate each of the loop
    for (int i = 0; i < n; i++){

        int row_sum = 0;
        
        for (int j = 0; j < n; j++){

            row_sum = row_sum + matrix[i][j];
        }

        sleep(1);

        // compare with the magic val
        if(magic_val == row_sum){

            // mutex update the score 

            // lock it first to prevent multiple jobs running
            pthread_mutex_lock(&lock);

            score = score + 1;

            // unlock it 
            pthread_mutex_unlock(&lock);

            row_result[counts] = 1;
            counts++;

        } else {

            pthread_mutex_lock(&lock);

            if (score > 0) {

                score = score - 1;

            }

            pthread_mutex_unlock(&lock);

            row_result[counts] = 0;
            counts++;

        }

        
        

        
    } 
    return NULL;
    
}