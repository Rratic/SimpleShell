#include "console.h"
filesystem glo_system;
bool session(len_t id){
    string s;
    while(getline(cin,s)){
        vector<string>t=split(s,' ');
        if(t.size()==0)continue;
        if(t.front()=="exit")return true;
    }
    return false;
}
bool sessions(){
    len_t i=1;
    while(true){
        if(!session(i))return true;
        ++i;
    }
    return false;
}
