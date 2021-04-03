#include "stringtools.h"
class file{
    public:
    string name;
    bool isDict;
    bool isHidden;
    file *in;
    vector<file *>contain;
    file(string nname,bool isDictionary,bool doHide,file *place);
    file(file &a);
    ~file();
};
