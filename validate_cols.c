#include <stdio.h>
#include <stdlib.h>

int col_result[100];

void* validate_cols(void* arg){


    int counts = 0;
    

    for (int j=0; j < n; j++){

        int sum_cols = 0;

        for (int i=0; i < n; i++){

             sum_cols += matrix[i][j];

        }

        sleep(1);

        if( magic_val == sum_cols ){

            pthread_mutex_lock(&lock);

            score = score + 1;
            
                
            pthread_mutex_unlock(&lock);

            col_result[counts] = 1;
            //counts++;

        } else {

            pthread_mutex_lock(&lock);

            //if ( score > 0 ) {

                //score = score - 1;
                col_result[counts] = 0;
            //


            pthread_mutex_unlock(&lock);

            //col_result[counts] = 1;
            //counts++;

        }
        counts++;
    }

    return NULL;
}
