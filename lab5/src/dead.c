#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

static pthread_mutex_t mut1 = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t mut2 = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
  int data;
}
data_t;

static void func1(data_t* d) {
  printf("Start the first func\n");
  pthread_mutex_lock(&mut1);
  for (int i = d->data + 1; i != d->data; )
    i++;
  pthread_mutex_lock(&mut2);
  for (int i = d->data - 1; i != d->data; )
    i--;
  pthread_mutex_unlock(&mut2);
  pthread_mutex_unlock(&mut1);
  printf("First function done \n");
}

static void func2(data_t* d) {
  printf("Start the second func\n");
  pthread_mutex_lock(&mut2);
  for (int i = d->data + 1; i != d->data; )
    i++;
  pthread_mutex_lock(&mut1);
  for (int i = d->data - 1; i != d->data; )
    i--;
  pthread_mutex_unlock(&mut1);
  pthread_mutex_unlock(&mut2);
  printf("Second function done \n");
}

int main(int argc, char* argv[]) {
  pthread_t t1, t2;
  data_t d = {1};

  if (pthread_create(&t1, NULL, (void*)func1, (void*)&d) != 0) {
    printf("Error: cannot create first thread\n");
    return -1;
  }
  if (pthread_create(&t2, NULL, (void*)func2, (void*)&d) != 0) {
    printf("Error: cannot create second thread\n");
    return -1;
  }

  if (pthread_join(t1, 0) != 0) {
    printf("Error: cannot join first thread\n");
    return -1;
  }

  if (pthread_join(t2, 0) != 0) {
    printf("Error: cannot join second thread\n");
    return -1;
  }
}