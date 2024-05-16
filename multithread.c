#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

// Global variable to change it in threads 
int g = 0; 

// The function to be executed by all threads 
void *myThreadFun(void *vargp) 
{ 
    // Store the value argument passed to this thread 
    int *myid = (int *)vargp; 

    // Let us create a static variable to observe its changes 
    static int s = 0; 

    // Change static and global variables 
    ++s; ++g; 

    // Print the argument, static and global variables 
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g); 
} 

int main() 
{ 
    int num_threads;
    printf("Enter the number of threads to create: ");
    scanf("%d", &num_threads);

    pthread_t tid[num_threads]; 

    // Create threads based on user input
    for (int i = 0; i < num_threads; i++) 
        pthread_create(&tid[i], NULL, myThreadFun, (void *)&tid[i]); 

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++)
        pthread_join(tid[i], NULL);

    return 0; 
} 
