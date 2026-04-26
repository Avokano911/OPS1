


//  The numbers should be n^2 (if n = 3 , I have numbers 1 to 9)
//int size = n * n;
int C_val[500];

void* validate_uniquness(void* arg){

    int size = n * n;

    // initialize with all 0

    //int C_val[size + 1];

    for (int i = 0; i < size + 1; i++){
        
        C_val[i] == 0;

    }
    
    int status = 1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){

            int curr = matrix[i][j];

            if ( curr < 1 || curr > size + 1){

                status = 0; // false
                C_val[curr] = curr;

            } else if ( C_val[curr] == 1){

                // already have seen
                status = 0;

            } else {

                C_val[curr] = 1; 

            }
        }
    }

    sleep(1);
    
    pthread_mutex_lock(&lock);
    if (status == 1) {

        score = score + 1;


    } else {

        if (score > 0) {

            //score = score - 1;
        }

    }
    pthread_mutex_unlock(&lock);

    return NULL;
    
}