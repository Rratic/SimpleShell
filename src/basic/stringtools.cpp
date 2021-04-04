#include "stringtools.h"
bool isCorrectFileName(string s){
    if(s=="."||s.find("..")!=s.npos||s.length()>255)return false;
    return true;
}
vector<string> split(string s,char sign){
    vector<string>ans;
    size_t l=s.length();
    string temp;
    for(size_t i=0;i<l;++i){
        if(s[i]==sign){
            if(temp!=""){
                ans.push_back(temp);
                temp="";
            }
        }
        else temp+=s[i];
    }
    if(temp!="")ans.push_back(temp);
    return ans;
}
