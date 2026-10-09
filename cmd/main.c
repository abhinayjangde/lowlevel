#include <stdio.h>
#include <pthread.h>

void *task1(void *arg)
{
    for (int i = 1; i <= 5; i++)
    {
        printf("Task 1 (%s): %d\n", arg, i);
    }
    return NULL;
}

void *task2(void *arg)
{
    for (int i = 1; i <= 5; i++)
    {
        printf("Task 2: %d\n", i);
    }
    return NULL;
}
int main(int argc, char *argv[])
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, task1, "hello 1");
    pthread_create(&t2, NULL, task2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("All tasks completed!\n");
    return 0;
}