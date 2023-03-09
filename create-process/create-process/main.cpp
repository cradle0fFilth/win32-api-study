#include <Windows.h>
#include <stdio.h>

//�������ʹ��win32 api�����½��� ���Ҵ˽��̴�edge�����
bool CreateChildProcess(PTCHAR szChildProcssName, PTCHAR szCommandLine) {
	
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&pi, sizeof(pi)); //��ʼ���ṹ�� �����ڴ�
	ZeroMemory(&si, sizeof(si));

	if(!CreateProcess(
		szChildProcssName,     //��������
		szCommandLine,		   //������
		NULL,                  //���̳н��̾��
		NULL,                  //���̳��߳̾��
		FALSE,                 //���̳о��
		CREATE_SUSPENDED,    //û�д�����־
		NULL,                  //ʹ�ø����̻�������
		NULL,                  //ʹ�ø�����Ŀ¼��Ϊ��ǰĿ¼�������Լ�����Ŀ¼
		&si,                   //STARTUPINFO�ṹ����ϸ��Ϣ
		&pi))                  //PROCESS_INFORMATION�ṹ�������Ϣ
	   {
		printf("CreateChildProcess Error:%d\n",GetLastError());
		return false;
	   }

	for (int i = 0; i < 5; i++) {
		Sleep(1000);
		printf("--------------------\n");
	}
	ResumeThread(pi.hThread);
	//printf("%x %x %x %x", pi.dwProcessId, pi.dwThreadId, pi.hProcess, pi.hThread);

	CloseHandle(pi.hProcess); //����������ں˶����ӳ��
	CloseHandle(pi.hThread);
	return true;
}

int main(int argc, char* argv[]) {
	

	//CreateEvent������
	SECURITY_ATTRIBUTES sa;
	ZeroMemory(&sa, sizeof(sa));
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE;
	CreateEvent(&sa, FALSE, FALSE, TEXT("MyEvent"));

	HANDLE hProcess;
	//printf("argv[1]: %s", argv[1]);
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 28552);

	printf("���̾����%d\n", hProcess);

	TCHAR szApplicationName[] = TEXT("C://Program Files (x86)//Microsoft//Edge Dev//Application//msedge.exe");
	TCHAR szCmdLine[] = TEXT("https://www.bilibili.com/");
	CreateChildProcess(szApplicationName, szCmdLine);

	//if (!TerminateProcess(hProcess, 1)) {
	//	printf("��ֹ����ʧ�ܣ�%d \n", GetLastError());
	//}
	//else {
	//	printf("��ֹ���̳ɹ�!");
	//}

	getchar();
	return 0;
}