/* ***************************
* Kanon Fujishima            *
* ID : 21873542              *
* ****************************/

int row_result[500];

void* validate_rows(void* arg){

    
    int counts = 0;
    
    // calculate each of the loop
    for (int i = 0; i < n; i++){

        int row_sum = 0;
        
        for (int j = 0; j < n; j++){

            row_sum = row_sum + matrix[i][j];
        }

        sleep(1);

        // compare with the magic val
        if(magic_val == row_sum){

            
            pthread_mutex_lock(&lock);

            score = score + 1;

            
            pthread_mutex_unlock(&lock);

            row_result[counts] = 1;
    

        } else {

            pthread_mutex_lock(&lock);


               row_result[counts] = 0;
        

            pthread_mutex_unlock(&lock);

            

        }
        counts++;

        
        

        
    } 
    return NULL;
    
}