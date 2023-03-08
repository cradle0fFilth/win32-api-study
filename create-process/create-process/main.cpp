#include <Windows.h>
#include <stdio.h>
bool CreateChildProcess(PTCHAR szChildProcssName, PTCHAR szCommandLine) {
	
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&pi, sizeof(pi));
	ZeroMemory(&si, sizeof(si));

	if(!CreateProcess(
		szChildProcssName,
		szCommandLine,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi))
	   {
		printf("CreateChildProcess Error:%d\n",GetLastError());
		return false;
	   }

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return true;
}

int main(int argc, char* argv[]) {
	
	TCHAR szApplicationName[]=TEXT("C://Program Files (x86)//Microsoft//Edge Dev//Application//msedge.exe");
	TCHAR szCmdLine[]=TEXT("https://www.bilibili.com/");
	CreateChildProcess(szApplicationName, szCmdLine);
	getchar();
	return 0;
}