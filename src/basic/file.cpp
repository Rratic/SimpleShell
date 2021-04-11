#include "file.h"
file::file(string nname,bool isDictionary,bool doHide,len_t leng,file *place){
    name=nname;
    isDict=isDictionary;
    isHidden=doHide;
    len=leng;
    in=place;
}
file::file(file &a){
    isDict=a.isDict;
    isHidden=a.isHidden;
    len=a.len;
    in=a.in;
    for(auto i:a.contain){
        file *temp(i);
        contain.push_back(temp);
    }
}
file::~file(){
    for(auto i:contain)delete i;
}
file *file::search(string _filename,unsigned long _depth){
    if(_depth==0)return nullptr;
    for(auto i:contain){
        if(i->name==_filename)return i;
        else{
            auto t=i->search(_filename,_depth-1);
            if(t!=nullptr)return t;
        }
    }
    return nullptr;
}
