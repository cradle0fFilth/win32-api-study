#include<stdio.h>
#include<Windows.h>

DWORD WINAPI ThreadProc(LPVOID lpParameter) { //线程函数格式
	for (int i = 0; i < 100; i++) {
		Sleep(500);
		printf("0000000000000%d \n", i);
	}
	return 0;
}

int main(int argc,char* argv[]) {

	HANDLE hThread=CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
	CloseHandle(hThread);

	for (int i = 0; i < 100; i++) {
		Sleep(500);	for (int i = 0; i < 100; i++) {
			Sleep(500);
			printf("-----------%d \n", i);
		}
		return 0;
		printf("-----------%d \n", i);
	}
	return 0;

}