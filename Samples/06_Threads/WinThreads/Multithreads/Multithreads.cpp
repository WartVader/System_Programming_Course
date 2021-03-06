#include <cstdio>
#include <Windows.h>

const int MAX_THREADS = 20;
DWORD WINAPI proc(LPVOID);

int main()
{
	HANDLE threads[MAX_THREADS];
	int args[MAX_THREADS];

	printf("Start thread creation\n");

	for (int i = 0; i < MAX_THREADS; i++)
	{
		args[i] = i;
		threads[i] = CreateThread(NULL, 0, proc, &args[i], 0, NULL);
		//threads[i] = CreateThread(NULL, 0, proc, &i, 0, NULL);
	}
	printf("End thread creation\n");

	printf("Wait threads\n");
	WaitForMultipleObjects(MAX_THREADS, threads, TRUE, INFINITE);
	printf("All threads end\n");

	return 0;
}


DWORD WINAPI proc(LPVOID o)
{
	int threadNum = *((int*)o);

	printf("%d\n", threadNum);

	return NULL;
}