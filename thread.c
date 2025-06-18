#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()

void *helloWorld(void *vargp) {
    sleep(1);
    printf("Hello World \n");
    return NULL;
}

int main() {
    pthread_t thread_id;
	
    printf("Before Threading\n");
	
    // Creating a thread
    pthread_create(&thread_id, NULL, helloWorld, NULL);
	
    // Waiting for the thread to finish
    pthread_join(thread_id, NULL);
	
    printf("After Thread\n");
    exit(0);
}

//output
Before Threading
Hello World 
After Thread


#include <stdio.h>
#include <pthread.h>

// Function to be executed by the thread
void* print_message(void* arg) {
    char* message = (char*)arg;
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create first thread
    pthread_create(&thread1, NULL, print_message, "Hello from Thread 1!");

    // Create second thread
    pthread_create(&thread2, NULL, print_message, "Hello from Thread 2!");

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

//output
Hello from Thread 1!
Hello from Thread 2!



#include <stdio.h>
#include <pthread.h>

void* print_message(void* arg) {
    char* message = (char*)arg;
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t threads[3];
    char* messages[] = {
        "Thread 1 says hi!",
        "Thread 2 says hello!",
        "Thread 3 says hey!"
    };

    // Create threads
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, print_message, messages[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads done.\n");
    return 0;
}


//output
Thread 1 says hi!
Thread 2 says hello!
Thread 3 says hey!
All threads done.



#include <stdio.h>
#include <pthread.h>

#define SIZE 6

int arr[SIZE] = {1, 2, 3, 4, 5, 6};
int sum1 = 0, sum2 = 0;  // Initialize sum variables

// Function for the first half of the array
void* compute_sum1(void* arg) {
    for (int i = 0; i < SIZE / 2; i++) {
        sum1 += arr[i];
    }
    return NULL;
}

// Function for the second half of the array
void* compute_sum2(void* arg) {
    for (int i = SIZE / 2; i < SIZE; i++) {
        sum2 += arr[i];
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create threads for the two halves of the array
    pthread_create(&thread1, NULL, compute_sum1, NULL);
    pthread_create(&thread2, NULL, compute_sum2, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Output the total sum
    printf("Total sum = %d\n", sum1 + sum2);

    return 0;
}


//output
Total sum = 21