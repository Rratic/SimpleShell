#include <vector>
#include <string>
using std::string;
using std::vector;
enum FileErr{
    DomainErr,// 函数定义域错
    PathErr,// 路径错误
    IllegalName,// 不允许的命名，例如"A..Q"
    NameAlreadyUsed,// 重名
    NameAlreadyUsedByDict,// 与目录重名
};
typedef long long len_t;
bool isCorrectFileName(string);
vector<string> split(string,char=' ');
