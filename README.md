

# LampOpt

## 概述

LampOpt是一个超小型参数解析库，允许您进行参数到值的点对点映射。  
例有以下命令（别名:`-maxret`=`--max_retries`：
```shell
my_git -global -maxret=8 -username=cpp -passwd=xxx -dir=./
```
将C++解析得到的内容化为JSON可得：
```
{
  "-global":"true",
  "--max_retries":"8",
  "-username":"cpp",
  "-passwd":"xxx",
  "-dir":"./"
}
```
当然是可以配置别名的。
## 例子
```cpp
#include "./opt.h"
#include <iostream>
#include <vector>
#include <map>
int main(int argc,char** argv){
  std::vector<std::string> args(argc-1);
  std::map<std::string,std::string> alias; // aliases
  alias["--help"]="-h";
  for(size_t i=1;i<argc;i++) args[i-1] = std::string(argv[i]);
  LamaOpt::Arguments i(args,alias);
  std::cout<<i.args["-h"]<<std::endl;
  return 0;
}
```
```shell
main -h # main --help
```
## 引用
您可以将其复制到您的项目文件中，然后使用`#include "./opt.h"`来包含头文件。  

## 方法&类
解析器的实现置于`LampOpt::Arguments`中，是一个类，其中，`LampOpt`是一个`namespace`。  
对于`LampOpt::Arguments`类，您可以定义它，并由构造函数传入`std::vector<std::string>`来解析参数。  
在构造函数完成后，您可以访问其中的`args`成员，它保存了由传入参数得出的参数表。  
对于一个参数，要求其使用 **=** 符号来指定这个参数的值。若不指定的情况，则参数内容默认为`"true"`。  

## 重要声明
This project was under the GPL-2.0 License.  
Copyright(c) 2022 Lampese.  
Copyright(c) 2022 nu11ptr.  