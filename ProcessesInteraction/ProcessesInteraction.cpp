#include <iostream>
#include "namedpipeapi.h"
#include "processthreadsapi.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	int value1, value2;
	cout << "Enter values:" << endl;
	cout << "Value1 = ";
	cin >> value1;
	cout << "Value2 = ";
	cin >> value2;

	STARTUPINFO sa;
	HANDLE hRead, hWrite;
	SECURITY_ATTRIBUTES secAttr{ sizeof(sa), NULL, true };
	CreatePipe(&hRead, &hWrite, &secAttr, 0);

	if (!CreatePipe(&hRead, &hWrite, &secAttr, 0))
	{
		cout << "Error: The channel was not created";
		return;
	}

	STARTUPINFO sa;
	sa.cb = sizeof(STARTUPINFO);
	sa.dwFlags = STARTF_USESTDHANDLES;
	sa.hStdInput = hRead; 
	sa.hStdError = GetStdHandle(STD_OUTPUT_HANDLE);
	sa.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!CreateProcess(NULL, "childProcess.exe", NULL, NULL, true, CREATE_NEW_CONSOLE, NULL, NULL, &sa, &sa))
	{
		cout << "Error: The Child process was not created" << endl;
		return 0;
	}

	WriteFile(write, buf, sizeof(buf), &bytes, NULL);

};

