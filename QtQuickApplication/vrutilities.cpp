#include "vrutilities.h"

/*
 * Copied from https://github.com/sector3studios/r3e-api/blob/master/sample-c/src/utils.c
 * MODIFIED!
 */
bool VRUtilities::isProcessRunning(const wchar_t* name) {
    BOOL result = false;
    HANDLE snapshot = nullptr;
    PROCESSENTRY32W entry;

    ZeroMemory(&entry, sizeof(entry));
    entry.dwSize = sizeof(PROCESSENTRY32W);

    snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot != INVALID_HANDLE_VALUE)
    {
        if (Process32FirstW(snapshot, &entry))
        {
            do
            {
                if (wcscmp(entry.szExeFile, name) == 0)
                {
                    result = TRUE;
                    break;
                }
            } while (Process32NextW(snapshot, &entry));
        }
        CloseHandle(snapshot);
    }
    return result;
}

std::chrono::milliseconds VRUtilities::getCurrentTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
}
