#include<stdio.h>
#include<Windows.h>
//���庯��ָ��
typedef int(_stdcall* lpPlus)(int, int);
typedef int(_stdcall* lpSub)(int, int);
 
//��������ָ�����
lpPlus myPlus;
lpSub mySub;

//Dll������ص���ǰ���̿ռ�
int main() {

	HINSTANCE hModule = LoadLibrary(L"Dll.dll");

	if (hModule == NULL) {
		printf("����dll����\n");
	}
	else {
		printf("�ɹ�����dll\n");
	}

	myPlus = (lpPlus)GetProcAddress(hModule, "Plus");  //�õ�ģ��ĺ�����ַ
	mySub = (lpSub)GetProcAddress(hModule, "Sub");

	if (myPlus == NULL) {
		printf("���غ���ʧ�� \n");
	}
	else {
		printf("���غ����ɹ� \n");
	}

	int x = myPlus(1, 2);
	int y = mySub(5, 2);
	printf("x = %d \ny = %d \n", x, y);
	FreeLibrary(hModule);

	return 0;
}