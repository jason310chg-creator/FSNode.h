#include "FSNode.h"
#include "FileSystem.h"
#include <cstring>
#include <iostream>

FSNode::FSNode(int node_id, FSNodeType type, const char* content = ""){
    this->node_id = node_id;
    this->type = type;
    link_count = 0;
    open_count = 0;
    mounted_fs = nullptr;
    if(type == FSNodeType::FILE){
        strncpy(this->content, content, 255);
        this->content[255]='\0';
        }
    else{
        this->content[0]='\0';
        }
}
void FSNode::listDentries(FileSystem* fs) const {
    if (type != FSNodeType::DIRECTORY)
        return;
    
    // [TODO 5]
    std::cout << "List FSNode #" << node_id << " (DIRECTORY):" << "\n";
    for (int i = 0; i < MAX_DENTRIES; i++) {
        if (dentry_inums[i] != 0) {
            FSNode* target = fs->getNode(dentry_inums[i]);
            std::cout << "  \"" << dentry_names[i] << "\" -> FSNode #"
                      << dentry_inums[i] << " ("
                      << (target && target->getType() == FSNodeType::DIRECTORY
                              ? "DIRECTORY"
                              : "FILE")
                      << ")\n";
        }
    }
}
