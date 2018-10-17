#include <cstdio>
#include <Windows.h>

unsigned long __stdcall proc(void *);
//DWORD WINAPI proc(LPVOID);

int main()
{
	printf("Start thread\n");
	HANDLE hThread = CreateThread(NULL, 0, proc, NULL, 0, NULL);
	printf("Thread started\n");

	printf("Wait\n");
	Sleep(3 * 1000);
	printf("End of waiting\n");

}

DWORD WINAPI proc(LPVOID)
{
	printf("Proc\n");
	return 0;
}

