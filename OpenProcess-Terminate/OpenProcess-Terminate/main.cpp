#include<Windows.h>
#include<Stdio.h>
#include<String>

int main(int argc,char* argv[]) {
	HANDLE hProcess;
	//printf("argv[1]: %s", argv[1]);
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 26312);

	printf("���̾����%d\n", hProcess);

	if (!TerminateProcess(hProcess, 1)) {
		printf("��ֹ����ʧ�ܣ�%d \n", GetLastError());
	}
	else {
		printf("��ֹ���̳ɹ�!");
	}

	return 0;
}