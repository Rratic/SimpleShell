#include "basic/path.h"
class filesystem{
    public:
    file *root;
    file *current;
    path currentpath;
    filesystem();
    ~filesystem();
    void clear();
    file *trace(path _filepath,bool _h=true);
    // Basic:
    void cd(path _dic);
    void touch(path _filename,len_t _filesize=0,bool _h=false);
    void mkdir(path _filename,bool _h=false);
    string find(string _filename,bool _r=false,bool _h=false);
    path pwd();
    void exit();
};
