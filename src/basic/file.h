#include "stringtools.h"
#include <stdint.h>
#define EmptyString 1// 字符串为空
#define BadPath 2// 路径错误
#define IllegalName 3// 不允许的命名，例如"A..Q"
#define WrongUse 4// 不按要求使用
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
    uint8_t load(string s);
    uint8_t merge(path &base);// 以a为基路径，此为相对路径，将a路径延长
    string output();
};
