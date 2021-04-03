#include "basic/file.h"
class filesystem{
    public:
    file *root;
    file *current;
    filesystem();
    ~filesystem();
    void clear();
    // Basic:
    uint8_t cd(path _dic);
    uint8_t touch(path _filename,uint64_t _filesize=0,bool _h=false);
    uint8_t mkdir(path _filename,bool _h=false);
    string find(string _filename,bool _r=false,bool _h=false);
    path pwd();
    void exit();
};
