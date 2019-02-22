#pragma once

#define OsCode 0
#define OsString 
#define OnWindows false
#define OnLinux false
#define OnMac false

#ifdef _WIN64
#define OsCode 1
#define OsString "Windows 64bit"
#include <Windows.h>
#elif _WIN32
#define OsCode 1
#define OsString  "Windows 32bit"
#include <Windows.h>
#elif __APPLE
#define OsCode 2
#define OsString "MacOS"
#elif __linux__
#define OsCode 3
#define OsString "Linux"
#else
#define OsCode 0
#define OsString "Unknown"
#endif