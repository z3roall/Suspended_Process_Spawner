#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <TlHelp32.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <fstream>
#include <direct.h>
#include <tchar.h>
#include <wlanapi.h>
#include <time.h>
#include <streambuf>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7);
	PROCESS_INFORMATION PI;
	STARTUPINFOA SI;
	
	ZeroMemory(&PI, sizeof(PI)); //NULL memory here
	ZeroMemory(&SI, sizeof(SI)); //NULL memory here
	cout << "[ ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA);
	cout << "OK";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7);
	cout << " ] Null process variables\n";
	
	//Created suspended explorer.exe process
	if (CreateProcessA("C:\\Windows\\explorer.exe", NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &SI, &PI)) 
	{
		cout << "[ ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xA);
		cout << "OK";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7);
		cout << " ] Started new instance of explorer.exe in suspended state: " << PI.dwProcessId << "\n";
	}
	else
	{
		cout << "[";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xC);
		cout << "FAIL";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x7);
		cout << "] Could not start new instance of explorer.exe in suspended state\n";
		return 1;
	}
	
	system("pause");
	return 0;
}
