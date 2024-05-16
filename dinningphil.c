#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define MAX_EATING_CYCLES 2

pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];

typedef struct {
    int id;
    int eating_cycles;
} PhilosopherData;

void *philosopher(void *arg) {
    PhilosopherData *data = (PhilosopherData *)arg;
    int id = data->id;
    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;
    int eating_cycles = 0;

    while (eating_cycles < MAX_EATING_CYCLES) {
        // Try to pick up chopsticks
        pthread_mutex_lock(&chopsticks[left]);
        printf("Philosopher %d picked up chopstick %d\n", id, left);
        pthread_mutex_lock(&chopsticks[right]);
        printf("Philosopher %d picked up chopstick %d\n", id, right);

        // Eating
        printf("Philosopher %d is eating\n", id);
        sleep(1);
        eating_cycles++;

        // Put down chopsticks
        pthread_mutex_unlock(&chopsticks[left]);
        printf("Philosopher %d put down chopstick %d\n", id, left);
        pthread_mutex_unlock(&chopsticks[right]);
        printf("Philosopher %d put down chopstick %d\n", id, right);

        // Thinking
        printf("Philosopher %d is thinking\n", id);
        sleep(1);
    }

    printf("Philosopher %d finished eating %d times.\n", id, MAX_EATING_CYCLES);
    pthread_exit(NULL);
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    PhilosopherData data[NUM_PHILOSOPHERS];

    // Initialize mutexes for each chopstick
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&chopsticks[i], NULL);
    }

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        data[i].id = i;
        data[i].eating_cycles = 0;
        pthread_create(&philosophers[i], NULL, philosopher, &data[i]);
    }

    // Wait for philosopher threads to finish
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&chopsticks[i]);
    }

    return 0;
}
