//Lab 11 Part B 
//Steven Gobran 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// shared data between threads
int *nums;
int count;

double avg_result;
int min_result;
int max_result;

// calc average
void *calc_avg(void *arg) {
    double sum = 0;
    for (int i = 0; i < count; i++)
        sum += nums[i];
    avg_result = sum / count;
    return NULL;
}

// find minimum
void *calc_min(void *arg) {
    int min = nums[0];
    for (int i = 1; i < count; i++)
        if (nums[i] < min)
            min = nums[i];
    min_result = min;
    return NULL;
}

// find maximum
void *calc_max(void *arg) {
    int max = nums[0];
    for (int i = 1; i < count; i++)
        if (nums[i] > max)
            max = nums[i];
    max_result = max;
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s num1 num2 ...\n", argv[0]);
        return 1;
    }

    // parse command line numbers
    count = argc - 1;
    nums = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
        nums[i] = atoi(argv[i + 1]);

    // create three threads
    pthread_t t_avg, t_min, t_max;
    pthread_create(&t_avg, NULL, calc_avg, NULL);
    pthread_create(&t_min, NULL, calc_min, NULL);
    pthread_create(&t_max, NULL, calc_max, NULL);

    // wait for all threads to finish
    pthread_join(t_avg, NULL);
    pthread_join(t_min, NULL);
    pthread_join(t_max, NULL);

    printf("The average value is %.2f\n", avg_result);
    printf("The minimum value is %d\n", min_result);
    printf("The maximum value is %d\n", max_result);

    free(nums);
    return 0;
}