#include "file.h"
class path{
    public:
    bool isAbsolute;
    vector<string>parts;
    path();
    void load(string);
    path merge(path,path);
    string output();
    void clear(bool=false);
};
