#include "file.h"
file::file(string nname,bool isDictionary,bool doHide,uint64_t leng,file *place){
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
    if(in!=nullptr)delete in;
    for(auto i:contain)delete i;
}
