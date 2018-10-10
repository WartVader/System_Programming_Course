#include <stdio.h>
#include <Windows.h>
#include "../Server/common.h"

int main()
{
	printf("Connect to server\n");
	HANDLE pipe = CreateFileA(pipename, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	printf("Connected\n");

	message m;

	ReadFile(pipe, &m, sizeof(m), NULL, NULL);

	printf("Server %d (%d:%d)\n", m.id, m.starttime.wHour, m.starttime.wMinute);
}

