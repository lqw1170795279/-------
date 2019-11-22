#pragma once
#include <Windows.h>
#pragma warning(disable:4996)
typedef bool(__stdcall *CreatePairFn)(char *Port1, char *Port2);
typedef bool(__stdcall *DeletePairFn)(char *Port1);
typedef bool(__stdcall *DeleteAllFn)(void);
typedef bool(__stdcall *SetStrictBaudrateName) (char *Port, bool StrictBaudrate);
typedef bool(__stdcall *SetStrictBaudrateHandle) (HANDLE hPort, bool StrictBaudrate);
typedef bool(__stdcall *SetStrictBaudrateFn)(char *Port, bool StrictBaudrate);
typedef bool(__stdcall *SetBreakFn)(char *Port, bool bBreak);
typedef bool(__stdcall *QueryBusFn)(void* InBuffer, long sizeInBuffer, void* OutBuffer, long sizeOutBuffer);
typedef bool(__stdcall *SetWiringFn)(char *Port, void *Buffer, long sizeBuffer);


bool Create_Port(char *Port1, char *Port2) {

	OSVERSIONINFO VersionInfo;
	HINSTANCE libInst;
	bool returnvalue = false;

	VersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&VersionInfo);

	if (VersionInfo.dwPlatformId != VER_PLATFORM_WIN32_NT)
		libInst = LoadLibrary("VSPDCTL64.DLL");
	else
		libInst = LoadLibrary("VSPDCTL.DLL");

	if (!libInst) return false; /* Couldn't load library */
	/* Substitute the typedefs above for functions other than CreatePairFn */
	CreatePairFn CreatePair = (CreatePairFn)GetProcAddress(libInst, "CreatePair");
	if (CreatePair == 0) return false; /* Couldn't find function */
	returnvalue = CreatePair(Port1, Port2); /* For example, Port1 = "COM5" and Port2 = "COM6" */
	FreeLibrary(libInst);
	return returnvalue;
}

bool Delete_Port(char* Port1) {
	OSVERSIONINFO VersionInfo;
	HINSTANCE libInst;
	bool returnvalue = false;

	VersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&VersionInfo);

	if (VersionInfo.dwPlatformId != VER_PLATFORM_WIN32_NT)
		libInst = LoadLibrary("VSPDCTL64.DLL");
	else
		libInst = LoadLibrary("VSPDCTL.DLL");

	if (!libInst) return false; /* Couldn't load library */
	/* Substitute the typedefs above for functions other than CreatePairFn */
	DeletePairFn DeletePair = (DeletePairFn)GetProcAddress(libInst, "DeletePair");
	if (DeletePair == 0) return false; /* Couldn't find function */
	returnvalue = DeletePair(Port1);
	FreeLibrary(libInst);
	return returnvalue;
}

bool Delete_AllPort(void) {
	OSVERSIONINFO VersionInfo;
	HINSTANCE libInst;
	bool returnvalue = false;

	VersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&VersionInfo);

	if (VersionInfo.dwPlatformId != VER_PLATFORM_WIN32_NT)
		libInst = LoadLibrary("VSPDCTL64.DLL");
	else
		libInst = LoadLibrary("VSPDCTL.DLL");

	if (!libInst) return false; /* Couldn't load library */
	/* Substitute the typedefs above for functions other than CreatePairFn */
	DeleteAllFn DeleteAll = (DeleteAllFn)GetProcAddress(libInst, "DeleteAll");
	if (DeleteAll == 0) return false; /* Couldn't find function */
	returnvalue = DeleteAll();
	FreeLibrary(libInst);
	return returnvalue;
}
