#include "stringtools.h"
#include <stdint.h>
class file{
    public:
    string name;
    bool isDict;
    bool isHidden;
    uint64_t len;
    file *in;
    vector<file *>contain;
    file(string nname,bool isDictionary,bool doHide,uint64_t leng,file *place);
    file(file &a);
    ~file();
};
class path{
    public:
    bool isAbsolute;
    vector<string>parts;
    bool load(string s);
};
