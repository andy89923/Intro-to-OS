#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#define eps 1e-9

pthread_mutex_t mutex;
int ans[3] = {};

typedef struct {

	int x, y;
	int i;
    char* c;

} WorkerArgs;

void* thread_func(void* tmp) {

	WorkerArgs* args = (WorkerArgs*) tmp;

	int x = args -> x;
	int y = args -> y;
	char* c = args -> c;

	// printf("%d -> %d ~ %d\n", args -> i, x, y);
	for (int i = x; i < y; i++) {
		pthread_mutex_lock(&mutex);
		ans[c[i] - '0'] += 1;
		pthread_mutex_unlock(&mutex);
	}

	pthread_exit(NULL);
}


int main(int argc, char const *argv[]) {
	
	int num_thread;
	int num_long;

	scanf("%d %d", &num_thread, &num_long);
	char* c = (char*) calloc(num_long + 10, sizeof(char));
	scanf("%s", c);

	pthread_t* thread_handles = (pthread_t*) malloc(num_thread * sizeof(pthread_t));
	WorkerArgs* args = (WorkerArgs*) calloc(num_thread, sizeof(WorkerArgs));

	int width = num_long / num_thread, prex = 0;
	for (int i = 0; i < num_thread; i++) {
		args[i].x = prex;
		args[i].y = prex + width;
		args[i].i = i;
		args[i].c = c;

		prex = args[i].y;

		if (i == num_thread - 1) args[i].y = num_long;
	}

	pthread_mutex_init(&mutex, NULL);

	long thread;
	for (thread = 0; thread < num_thread; thread++) {
		pthread_create(&thread_handles[thread], (pthread_attr_t*) NULL, thread_func, (void*) &args[thread]);
	}
	for (thread = 0; thread < num_thread; thread++) {
		pthread_join(thread_handles[thread], NULL);
	}

	for (int i = 0; i < 3; i++) {
		printf("%d: %d\n", i, ans[i]);
	}

	pthread_mutex_destroy(&mutex);
	free(thread_handles);
	free(c);
	free(args);
	return 0;
}