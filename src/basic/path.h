#include "file.h"
class path{
    public:
    bool isAbsolute;
    vector<string>parts;
    path();
    void load(string);
    string output();
    void clear(bool=false);
};
path merge(path,path);
