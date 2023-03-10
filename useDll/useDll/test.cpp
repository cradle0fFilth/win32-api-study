#include<stdio.h>
#include<Windows.h>
//定义函数指针
typedef int(_stdcall* lpPlus)(int, int);
typedef int(_stdcall* lpSub)(int, int);
 
//声明函数指针变量
lpPlus myPlus;
lpSub mySub;

//Dll必须加载到当前进程空间
int main() {

	HINSTANCE hModule = LoadLibrary(L"Dll.dll");

	if (hModule == NULL) {
		printf("加载dll错误\n");
	}
	else {
		printf("成功加载dll\n");
	}

	myPlus = (lpPlus)GetProcAddress(hModule, "Plus");  //得到模块的函数地址
	mySub = (lpSub)GetProcAddress(hModule, "Sub");

	if (myPlus == NULL) {
		printf("加载函数失败 \n");
	}
	else {
		printf("加载函数成功 \n");
	}

	int x = myPlus(1, 2);
	int y = mySub(5, 2);
	printf("x = %d \ny = %d \n", x, y);
	FreeLibrary(hModule);

	return 0;
}