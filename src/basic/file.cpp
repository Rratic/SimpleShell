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
file *file::search(string _filename){
    for(auto i:contain){
        if(i->name==_filename)return i;
    }
    return nullptr;
}
path::path(){isAbsolute=true;}
uint8_t path::load(string s){
    if(s=="")return EmptyString;
    if(s[0]=='/')isAbsolute=true;
    else isAbsolute=false;
    vector<string>pieces=split(s,'/');
    for(auto i:pieces){
        if(i==".."){
            if(parts.empty()&&!isAbsolute)parts.push_back("..");
            if(!parts.empty()&&parts.back()!="..")parts.pop_back();
            //"D:/../../"=>"D:/"
        }else if(i!="."){
            if(!isCorrectFileName(i))return IllegalName;
            parts.push_back(i);
        }
    }
    return 0;
}
uint8_t path::merge(path &base){
    if(isAbsolute)return WrongUse;
    for(auto i:parts){
        if(i==".."){
            if(base.parts.empty()&&!base.isAbsolute)base.parts.push_back("..");
            if(!base.parts.empty()&&base.parts.back()!="..")base.parts.pop_back();
            //"D:/../../"=>"D:/"
        }else if(i!="."){
            //不检查名字
            base.parts.push_back(i);
        }
    }
    return 0;
}
uint8_t path::mergewith(path expend){
    if(expend.isAbsolute)return WrongUse;
    for(auto i:expend.parts){
        if(i==".."){
            if(parts.empty()&&!isAbsolute)parts.push_back("..");
            if(!parts.empty()&&parts.back()!="..")parts.pop_back();
            //"D:/../../"=>"D:/"
        }else if(i!="."){
            //不检查名字
            parts.push_back(i);
        }
    }
    return 0;
}
string path::output(){
    string ans;
    if(isAbsolute)ans="/";
    for(auto i:parts){
        ans+=(i+"/");
    }
    if(parts.empty())ans+=".";
}
void path::clear(bool mode){
    isAbsolute=mode;
    parts.clear();
}
