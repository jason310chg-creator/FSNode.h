#include "FileHandle.h"
#include <cstring>
#include <iostream>

void FileHandle::seek(int pos) {
    if (pos < 0) pos = 0;
    if (pos > 255) pos = 255;
    offset = pos;
}

int FileHandle::tell() const { return offset; }

bool FileHandle::isOpen() const { return is_open; }

const char* FileHandle::read() const {
    if (!is_open) return "";
    return node->getContent() + offset;
}

void FileHandle::write(const char* data) {
    if (!is_open) return;
    char buf[256];
    strncpy(buf, node->getContent(), 255);
    buf[255] = '\0';
    strncpy(buf + offset, data, 255 - offset);
    buf[255] = '\0';
    node->setContent(buf);
}

void FileHandle::printInfo() const {
    if (is_open)
        std::cout << "[FileHandle] open   -> FSNode #" << node->getNodeId() << "\n";
    else
        std::cout << "[FileHandle] closed\n";
}
