#include <stdio.h>
#include <stdlib.h>

#include "Assignment.c"

void* validate_cols(void* arg);

void* validate_cols(void* arg){

    for (int j=0; j < n; j++){

        int sum_cols = 0;

        for (int i=0; i < n; i++){

             sum_cols = sum_cols + matrix[i][j];

        }

        if( magic_val == sum_cols ){

            pthread_mutex_lock(&lock);

            score = score + 1;

            pthread_mutex_unlock(&lock);

        } else {

            pthread_mutex_lock(&lock);

            if ( score > 0 ) {

                score = score - 1;
            }

            pthread_mutex_unlock(&lock);

        }
    }

    return NULL;
}
