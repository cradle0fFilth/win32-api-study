#include<stdio.h>
#include<Windows.h>

DWORD WINAPI ThreadProc(LPVOID lpParameter) { //�̺߳�����ʽ
	int* p = (int*)lpParameter;
	for (int i = 0; i < *p; i++) {
		Sleep(500);
		printf("0000000000000%d \n", i);
	}
	return 0;
}
void WINAPI TestThread() { //�̺߳�����ʽ
	for (int i = 0; i < 100; i++) {
		Sleep(500);
		printf("0000000000000%d \n", i);
	}
}

int main(int argc,char* argv[]) {
	int n = 10;
	HANDLE hThread=CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc, &n, 0, NULL);
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