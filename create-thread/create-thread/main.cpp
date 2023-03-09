#include<stdio.h>
#include<Windows.h>

DWORD WINAPI ThreadProc(LPVOID lpParameter) { //线程函数格式
	int* p = (int*)lpParameter;
	for (int i = 0; i < *p; i++) {
		Sleep(500);
		printf("0000000000000%d \n", i);
	}
	return 0;
}
void WINAPI TestThread() { //线程函数格式
	for (int i = 0; i < 12; i++) {
		Sleep(500);
		printf("--------------%d \n", i);
	}
}

int main(int argc,char* argv[]) {
	int n = 10;
	HANDLE hThread[2];
    hThread[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc, &n, 0, NULL);
	hThread[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)TestThread, 0, 0, NULL);

	
	WaitForMultipleObjects(2,hThread,1, INFINITE);
	printf("线程执行完毕 \n");
	
	getchar();
	CloseHandle(hThread);

	//for (int i = 0; i < 100; i++) {
	//	Sleep(500);	for (int i = 0; i < 100; i++) {
	//		Sleep(500);
	//		printf("-----------%d \n", i);
	//	}
	//	return 0;
	//	printf("-----------%d \n", i);
	//}
	return 0;

}