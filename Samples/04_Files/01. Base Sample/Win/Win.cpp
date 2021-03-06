#include <stdio.h>
#include <Windows.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Not enough arguments");
		return 1;
	}

	HANDLE file_in = CreateFileA(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (file_in == INVALID_HANDLE_VALUE)
	{
		DWORD error = GetLastError();

		printf("Can't open file %s (error: %u)", argv[1], error);
		return error;
	}

	HANDLE file_out = CreateFileA(argv[2], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
	if (file_out == INVALID_HANDLE_VALUE)
	{
		DWORD error = GetLastError();

		printf("Can't create file %s (error: %u)", argv[2], error);
		return error;
	}


	const DWORD buffer_size = 100000;
	DWORD readed = 0;
	BOOL read_result;

	byte buffer[buffer_size];

	DWORD counters[256];
	ZeroMemory(&counters, sizeof(counters));

	while ((read_result = ReadFile(file_in, buffer, buffer_size, &readed, NULL)) &&
		(readed > 0))
	{
		for (unsigned int i = 0; i < readed; i++)
			counters[buffer[i]] ++;
	}

	if (!read_result)
	{
		DWORD error = GetLastError();
				
		printf("Read file %s error (error: %u)", argv[1], error);
		return error;
	}


	if (!WriteFile(file_out, counters, sizeof(counters), NULL, NULL))
	{
		DWORD error = GetLastError();

		printf("Can't write result to file %s (error: %u)", argv[2], error);
		return error;

	}

	CloseHandle(file_in);
	CloseHandle(file_out);

}