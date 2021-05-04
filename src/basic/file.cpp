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
file *file::search(string _filename,unsigned long _depth,bool _h){
    if(_depth==0)return nullptr;
    for(auto i:contain){
        if(i->name==_filename&&(_h||!i->isHidden))return i;// 名字相同且查找隐藏文件/文件未隐藏
        else{
            auto t=i->search(_filename,_depth-1);
            if(t!=nullptr)return t;
        }
    }
    return nullptr;
}
bool file::create(string _name,bool _d,bool _h,len_t _sz){
    file *pl=search(_name,32768,true);
    if(pl!=nullptr)return false;
    file *x=new file(_name,_d,_h,_sz,this);
    contain.push_back(x);
    return true;
}
