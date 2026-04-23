// validate_diagonals function
#include <stdio.h>
#include <stdlib.h>
#include "Assignment.c"


int leftup_to_rightdown = 0;
int rightup_to_leftdown = 0;

int diagonal_result[2];
int counts = 0;

void* validate_diagonals(void* arg);

void* validate_diagonals(void* arg){

    for (int i=0; i < n; i++){
        
        leftup_to_rightdown = leftup_to_rightdown + matrix[i][i];
        rightup_to_leftdown = rightup_to_leftdown + matrix[i][n - 1 - i];

    }

    sleep(1);

    if (leftup_to_rightdown == magic_val) {

        pthread_mutex_lock(&lock);

        score = score + 1;

        pthread_mutex_unlock(&lock);

        diagonal_result[counts] = 1;
        counts++;

    } else {

            pthread_mutex_lock(&lock);

            if (score > 0) {

                score = score - 1;

            }

            pthread_mutex_unlock(&lock);

            diagonal_result[counts] = 0;
            counts++;

        }


    if (rightup_to_leftdown == magic_val) {

        pthread_mutex_lock(&lock);

        score = score + 1;

        pthread_mutex_unlock(&lock);

        diagonal_result[counts] = 1;
        counts++;
        

    } else {

            pthread_mutex_lock(&lock);

            if (score > 0) {

                score = score - 1;

            }

            pthread_mutex_unlock(&lock);

            diagonal_result[counts] = 0;
            counts++;

        }

        return NULL;
}
