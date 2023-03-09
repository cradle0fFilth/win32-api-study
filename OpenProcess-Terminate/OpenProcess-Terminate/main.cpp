#include<Windows.h>
#include<Stdio.h>
#include<String>

int main(int argc,char* argv[]) {
	HANDLE hProcess;
	//printf("argv[1]: %s", argv[1]);
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 26312);

	printf("进程句柄：%d\n", hProcess);

	if (!TerminateProcess(hProcess, 1)) {
		printf("终止进程失败：%d \n", GetLastError());
	}
	else {
		printf("终止进程成功!");
	}

	return 0;
}