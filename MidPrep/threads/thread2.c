#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define NUM_THREADS 5

void *threadWorker(void *threadID) {
  long tid = (long)threadID;
  pid_t pid = getpid();

  printf("Thread %ld: Thread ID = %lu, Process ID = %d\n", tid, pthread_self(),
         pid);

  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;

  for (t = 0; t < NUM_THREADS; t++) {
    printf("Creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, threadWorker, (void *)t);

    if (rc) {
      printf("Error: Return code from pthread_create() is %d\n", rc);
      exit(1);
    }
  }

  for (t = 0; t < NUM_THREADS; t++) {
    pthread_join(threads[t], NULL);
  }

  printf("All threads have completed.\n");

  pthread_exit(NULL);
}
