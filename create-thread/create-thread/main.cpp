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
	for (int i = 0; i < 12; i++) {
		Sleep(500);
		printf("--------------%d \n", i);
	}
}

int main(int argc,char* argv[]) {
	int n = 10;
	HANDLE hThread[2];
	
	DWORD r1;
	DWORD dwResult1;
	DWORD dwResult2;

    hThread[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc, &n, 0, NULL);
	hThread[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)TestThread, 0, 0, NULL);

	
	//WaitForMultipleObjects(2,hThread,1, INFINITE);      //��ʱ���ȴ������̶߳�...�ٽ��� ���һ��������ʾ�ȶ��
	//GetExitCodeThread(hThread[0], &dwResult1);    //��ȡ����ֵ
	//GetExitCodeThread(hThread[0], &dwResult1);
	Sleep(1000);
	SuspendThread(hThread[0]);

	CONTEXT context;
	context.ContextFlags = CONTEXT_INTEGER;
	GetThreadContext(hThread[0], &context);         //��ȡ�߳������Ľṹ�� ��ȡ������
	printf("%x %x  \n", context.Rax, context.Rcx);

	printf("�߳�ִ����� \n");
	
	//getchar();
	//CloseHandle(hThread);

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