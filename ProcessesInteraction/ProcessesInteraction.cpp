#include <iostream>
#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
	HANDLE hRead, hWrite;

	SECURITY_ATTRIBUTES secAttr;
	ZeroMemory(&secAttr, sizeof(secAttr));
	secAttr.nLength = sizeof(secAttr);
	secAttr.bInheritHandle = true;
	secAttr.lpSecurityDescriptor = NULL;

	if (!CreatePipe(&hRead, &hWrite, &secAttr, 0))
	{
		cout << "Error: The channel was not created";
		CloseHandle(hRead);
		CloseHandle(hWrite);
		return 0;
	}

	PROCESS_INFORMATION pi;
	STARTUPINFO sa;
	ZeroMemory(&sa, sizeof(sa));
	ZeroMemory(&pi, sizeof(pi));

	sa.cb = sizeof(STARTUPINFO);
	sa.dwFlags = STARTF_USESTDHANDLES;
	sa.hStdInput = hRead;
	sa.hStdError = GetStdHandle(STD_OUTPUT_HANDLE);
	sa.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!CreateProcess(L"ChildProcess.exe", NULL, NULL, NULL, true, CREATE_NEW_CONSOLE, NULL, NULL, &sa, &pi))
	{
		cout << "Error: The Child process was not created" << endl;
		CloseHandle(hRead);
		CloseHandle(hWrite);
		return 0;
	}

	int value1, value2;
	cout << "Enter values:" << endl;
	cout << "Value1 = ";
	cin >> value1;
	cout << "Value2 = ";
	cin >> value2;

	WriteFile(hWrite, &value1, sizeof(value1), NULL, NULL);
	WriteFile(hWrite, &value2, sizeof(value2), NULL, NULL);

	
	system("pause");
	TerminateProcess(pi.hProcess, 0);
	CloseHandle(hRead);
	CloseHandle(hWrite);
};
