#include <iostream>
#include "FileSystem.h"

int main () {
    FileSystem* fs1 = new FileSystem(8);
    fs1->getRoot()->printInfo();
    delete fs1;
}
