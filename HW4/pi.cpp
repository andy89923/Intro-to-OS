#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <climits>
#define eps 1e-9

pthread_mutex_t mutex;
long long ans = 0;

const double rand_min = -1.0;
const double rand_max =  1.0;
const double rang = 2.0;

void* thread_func(void* tim) {

	long long t = *((long long*) tim);
	
	unsigned int mystatex = time(NULL) ^ rand();
	unsigned int mystatey = time(NULL) ^ rand();

	double x, y;
	long long tmp_ans = 0;

	for (long long i = 0; i < t; ++i) {
		x = rang * rand_r(&mystatex) / (INT_MAX + 1.0) + rand_min;
		y = rang * rand_r(&mystatey) / (INT_MAX + 1.0) + rand_min;

		if (x * x + y * y - rand_max <= eps) tmp_ans += 1;
	}

	pthread_mutex_lock(&mutex);
	ans += tmp_ans;
	pthread_mutex_unlock(&mutex);


	pthread_exit(NULL);
}


int main(int argc, char const *argv[]) {
	int num_thread;
	long long num_toss;

	scanf("%d%lld", &num_thread, &num_toss);

	pthread_t* thread_handles = (pthread_t*) malloc(num_thread * sizeof(pthread_t));
	long long* tims = (long long*) malloc(num_thread * sizeof(long long));
	pthread_mutex_init(&mutex, NULL);

	srand(time(NULL));

	long thread;
	for (thread = 0; thread < num_thread; thread++) {
		tims[thread] = num_toss / num_thread;

		if (thread == num_thread - 1)
			tims[thread] += num_toss % num_thread;

		pthread_create(&thread_handles[thread], (pthread_attr_t*) NULL, thread_func, (void*) &tims[thread]);
	}

	for (thread = 0; thread < num_thread; thread++) {
		pthread_join(thread_handles[thread], NULL);
	}

	printf("Get: %lld\n", ans);
	double pi_estimate = ans * 4.0 / (double) num_toss;
	printf("Pi: %.5lf\n", pi_estimate);

	pthread_mutex_destroy(&mutex);
	free(thread_handles);
	return 0;
}