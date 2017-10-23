//
// Created by stark on 21-Oct-17.
//

#include "SharedMemoryAccess.h"

SharedMemoryAccess::SharedMemoryAccess(std::string sharedMemoryName, int size) {
    this->sharedMemoryName = sharedMemoryName;
    this->size = size;
    this->isOpen = false;

    this->handle = nullptr;
    this->buffer = nullptr;
}

SharedMemoryAccess::~SharedMemoryAccess() {
    if (this->isOpen)
        close();
}

bool SharedMemoryAccess::open() {
    if (this->isOpen)
        return true;

    this->handle = OpenFileMapping(FILE_MAP_READ, FALSE, TEXT(this->sharedMemoryName.c_str()));

    if (!this->handle)
        return false;

    this->buffer = MapViewOfFile(this->handle, FILE_MAP_READ, 0, 0, (DWORD)this->size);

    if (!this->buffer) {
        close();
        return false;
    }

    this->isOpen = true;
    return true;
}

bool SharedMemoryAccess::opened() {
    return isOpen;
}

void SharedMemoryAccess::close() {
    if (!this->isOpen)
        return;

    if (this->buffer) {
        UnmapViewOfFile(this->buffer);
        this->buffer = nullptr;
    }
    if (this->handle) {
        CloseHandle(this->handle);
        this->handle = nullptr;
    }

    this->isOpen = false;
}

void* SharedMemoryAccess::getBuffer() {
    return this->buffer;
}