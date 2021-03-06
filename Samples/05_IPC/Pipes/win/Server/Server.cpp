#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>

HANDLE CreateClientProcess(HANDLE h)
{
	char cmdLine[100];
	ZeroMemory(cmdLine, sizeof(cmdLine));

	sprintf(cmdLine, "client.exe %d", h);

	STARTUPINFOA stInfo;
	ZeroMemory(&stInfo, sizeof(stInfo));
	stInfo.cb = sizeof(stInfo);

	PROCESS_INFORMATION pi;

	CreateProcessA(NULL, cmdLine, NULL, NULL, TRUE, 0, NULL, NULL, &stInfo, &pi);

	return pi.hProcess;
}

int main()
{
	HANDLE hRead, hWrite;

	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(sa);
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;

	if (!CreatePipe(&hRead, &hWrite, &sa, 0))
		return 1;

	SetHandleInformation(hWrite, HANDLE_FLAG_INHERIT, 0);

	HANDLE ch = CreateClientProcess(hRead);

	char buffer[100];
	ZeroMemory(buffer, sizeof(buffer));
	sprintf(buffer, "%d: Hello, world!", GetCurrentProcessId());

	DWORD written;

	WriteFile(hWrite, buffer, (DWORD) strlen(buffer), &written, NULL);

	WaitForSingleObject(ch, 1000 * 10);

	CloseHandle(hRead);
	CloseHandle(hWrite);

	return 0;
}

