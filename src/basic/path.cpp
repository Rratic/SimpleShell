#include "path.h"
path::path(){isAbsolute=true;}
void path::load(string s){
    if(s[0]=='/')isAbsolute=true;
    else isAbsolute=false;
    vector<string>pieces=split(s,'/');
    for(auto i:pieces){
        if(i==".."){
            if(parts.empty()&&!isAbsolute)parts.push_back("..");
            if(!parts.empty()&&parts.back()!="..")parts.pop_back();
            // 根目录寻上层目录依然是根目录
        }else if(i!="."){
            if(!isCorrectFileName(i))throw IllegalName;
            parts.push_back(i);
        }
    }
}
path path::merge(path base,path append){
    if(isAbsolute)throw DomainErr;
    for(auto i:append.parts){
        if(i==".."){
            if(!base.isAbsolute&&base.parts.empty())base.parts.push_back("..");
            if(!base.parts.empty()&&base.parts.back()!="..")base.parts.pop_back();
        }else if(i!="."){//忽略 .
            // 不检查名字
            base.parts.push_back(i);
        }
    }
    return base;
}
string path::output(){
    string ans;
    if(isAbsolute)ans="/";
    for(auto i:parts){
        ans+=(i+"/");
    }
    if(parts.empty())ans+=".";
    return ans;
}
void path::clear(bool mode){
    isAbsolute=mode;
    parts.clear();
}
