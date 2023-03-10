#include "MyDll.h"
#include "pch.h"

int _stdcall Plus(int x, int y) {
	return x + y;
}
int _stdcall  Sub(int x, int y) {
	return x - y;
}
