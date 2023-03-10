#include <Windows.h>
#include <stdio.h>

//这个程序使用win32 api创建新进程 并且此进程打开edge浏览器
bool CreateChildProcess(PTCHAR szChildProcssName, PTCHAR szCommandLine) {
	
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&pi, sizeof(pi)); //初始化结构体 分配内存
	ZeroMemory(&si, sizeof(si));

	if(!CreateProcess(
		szChildProcssName,     //对象名称
		szCommandLine,		   //命令行
		NULL,                  //不继承进程句柄
		NULL,                  //不继承线程句柄
		FALSE,                 //不继承句柄
		CREATE_SUSPENDED,    //没有创建标志
		NULL,                  //使用父进程环境变量
		NULL,                  //使用父进程目录作为当前目录，可以自己设置目录
		&si,                   //STARTUPINFO结构体详细信息
		&pi))                  //PROCESS_INFORMATION结构体进程信息
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

	CloseHandle(pi.hProcess); //结束句柄中内核对象的映射
	CloseHandle(pi.hThread);
	return true;
}

int main(int argc, char* argv[]) {
	

	//CreateEvent的例子
	SECURITY_ATTRIBUTES sa;
	ZeroMemory(&sa, sizeof(sa));
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE;
	CreateEvent(&sa, FALSE, FALSE, TEXT("MyEvent"));

	HANDLE hProcess;
	//printf("argv[1]: %s", argv[1]);
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 28552);

	printf("进程句柄：%d\n", hProcess);

	TCHAR szApplicationName[] = TEXT("C://Program Files (x86)//Microsoft//Edge Dev//Application//msedge.exe");
	TCHAR szCmdLine[] = TEXT("https://www.bilibili.com/");
	CreateChildProcess(szApplicationName, szCmdLine);

	//if (!TerminateProcess(hProcess, 1)) {
	//	printf("终止进程失败：%d \n", GetLastError());
	//}
	//else {
	//	printf("终止进程成功!");
	//}

	getchar();
	return 0;
}