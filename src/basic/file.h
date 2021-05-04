#include "tools.h"
class file{
    public:
    string name;
    bool isDict;
    bool isHidden;
    len_t len;
    file *in;
    vector<file *>contain;
    file(string,bool,bool,len_t,file*);
    file(file &);
    ~file();
    file *search(string,unsigned long=1,bool=false);
    bool create(string,bool=false,bool=false,len_t=0);
};
