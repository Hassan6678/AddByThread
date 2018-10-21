#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<sys/wait.h>

void * Add(void *arg)
{
	long start = (long)arg;
	long end = start + 100;
	long sum = 0;
	for (int i = start; i <= end; i++)
		sum += i;
	return ((void*)sum);
}

long size = 100;

int main ()
{
	long status_t[10],Total = 0;
	for(int i = 0; i< 10; i++){	
		pthread_t thread_t[i];

		pthread_create(&thread_t[i],NULL,Add,(void*)(i*size));

		pthread_join(thread_t[i],(void**) & status_t[i]);
	}
	for(int i = 0; i< 10; i++){
		printf("\nValue returned By Thread %d", (i+1));
		printf(" = %ld\n", status_t[i]);
		Total += status_t[i];
	}
	printf("\nTotal sum = %ld\n",Total);

	return 0;
}
