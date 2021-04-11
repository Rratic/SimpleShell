#include "filesystem.h"
filesystem::filesystem(){
    root=new file("",true,false,0,nullptr);
    current=root;
}
filesystem::~filesystem(){
    delete root;
}
void filesystem::clear(){
    for(auto i:root->contain)delete i;
    current=root;
    currentpath.clear(true);
}
