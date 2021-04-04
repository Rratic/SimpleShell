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
file *filesystem::trace(path _filepath){
    if(!_filepath.isAbsolute)_filepath.mergewith(currentpath);
    file *temp=root;
    for(auto i:_filepath.parts){
        temp=temp->search(i);
        if(temp==nullptr)return nullptr;
    }
    return temp;
}
