#include "filesystem.h"
filesystem::filesystem(){
    root=new file("",true,false,0,nullptr);
    current=root;
}
filesystem::~filesystem(){
    if(current==root){
        delete root;
    }
    else{
        delete current;
        delete root;
    }
}
