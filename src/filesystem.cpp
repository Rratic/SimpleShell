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
file* filesystem::trace(path _filepath,bool _h=true){
    file *begin;
    if(_filepath.isAbsolute)begin=root;
    else begin=current;
    for(auto i:_filepath.parts){
        bool flag=true;
        vector<file*>::iterator j;
        for(j=begin->contain.begin();j!=begin->contain.end();++j){
            if((*j)->name==i){
                flag=false;
                break;
            }
        }
        if(flag)return nullptr;
        begin=*j;
    }
    return nullptr;
}

void filesystem::cd(path _dic){
    file *pl=trace(_dic);
    if(pl==nullptr)throw PathErr;
    current=pl;
    if(_dic.isAbsolute)currentpath=_dic;
    else currentpath=merge(currentpath,_dic);
}
void filesystem::touch(path _filepath,len_t filesize,bool _h){
    string filename=_filepath.parts.back();
    _filepath.parts.pop_back();
    file *pl=trace(_filepath);
    if(pl==nullptr)throw PathErr;
    for(auto i:pl->contain){
        if(i->name==filename){
            if(i->isDict)throw NameAlreadyUsedByDict;
            else delete i;// 删除
            break;
        }
    }
    pl->create(filename,false,_h,filesize);// 再新建
}
void filesystem::mkdir(path _filename,bool _h=false){
    string filename=_filename.parts.back();
    _filename.parts.pop_back();
    file *pl=trace(_filename);
    if(pl==nullptr)throw PathErr;
    for(auto i:pl->contain){
        if(i->name==filename){
            throw NameAlreadyUsedByDict;
        }
    }
    pl->create(filename,false,_h,0);// 再新建
}
string filesystem::find(string _filename,bool _r=false,bool _h=false){
}
path filesystem::pwd(){
    return currentpath;
}
