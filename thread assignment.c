#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[1000];

void* func1(void* arg)
{
	int s = (int)arg;
	int e = s + 100;

	int i, sum = 0;	
	for (i = s; i < e; i++)
	{
		sum += arr[i];
	}
	return (void*)sum;
}
int main()
{
	int i;
	void* sum[10];
	for (i = 0; i < 1000; i++)
	{
		arr[i] = i;
	}

	pthread_t thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8, thread9, thread10;

	pthread_create(&thread1, NULL, func1, (void*)0);
	pthread_create(&thread2, NULL, func1, (void*)100);
	pthread_create(&thread3, NULL, func1, (void*)200);
	pthread_create(&thread4, NULL, func1, (void*)300);
	pthread_create(&thread5, NULL, func1, (void*)400);
	pthread_create(&thread6, NULL, func1, (void*)500);
	pthread_create(&thread7, NULL, func1, (void*)600);
	pthread_create(&thread8, NULL, func1, (void*)700);
	pthread_create(&thread9, NULL, func1, (void*)800);
	pthread_create(&thread10, NULL, func1, (void*)900);

	pthread_join(thread1, &sum[0]);
	pthread_join(thread2, &sum[1]); 
	pthread_join(thread3, &sum[2]);
	pthread_join(thread4, &sum[3]);
	pthread_join(thread5, &sum[4]);
	pthread_join(thread6, &sum[5]);
	pthread_join(thread7, &sum[6]);
	pthread_join(thread8, &sum[7]);
	pthread_join(thread9, &sum[8]);
	pthread_join(thread10, &sum[9]);
	int summ[10];
	int totalsum = 0;
	for (i = 0; i< 10; i++)
	{
		summ[i] = (int)sum[i];
		totalsum += summ[i];
	}
	printf("the sum is: %d", totalsum);
	return 0;
}
