//
// Created by stark on 21-Oct-17.
//

#include "Utilities.h"

/*
 * Copied from https://github.com/sector3studios/r3e-api/blob/master/sample-c/src/utils.c
 */
bool Utilities::isProcessRunning(std::string name) {
    BOOL result = false;
    HANDLE snapshot = nullptr;
    PROCESSENTRY32 entry;

    ZeroMemory(&entry, sizeof(entry));
    entry.dwSize = sizeof(PROCESSENTRY32);

    snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot != INVALID_HANDLE_VALUE)
    {
        if (Process32First(snapshot, &entry))
        {
            do
            {
                if (_tcscmp(entry.szExeFile, name.c_str()) == 0)
                {
                    result = TRUE;
                    break;
                }
            } while (Process32Next(snapshot, &entry));
        }
        CloseHandle(snapshot);
    }

    return result;
}