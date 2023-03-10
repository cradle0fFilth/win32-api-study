
#include "pch.h"

extern "C" _declspec(dllexport)int _stdcall Plus(int x, int y);

extern "C" _declspec(dllexport)int _stdcall  Sub(int x, int y);

int  _stdcall Plus(int x, int y) {
	return x + y;
}
int _stdcall Sub(int x, int y) {
	return x - y;
}
