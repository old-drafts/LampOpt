

# LampOpt操作文档

#### 概述

LampOpt是一个基于C++的控制台命令解析库，优点是体型小、适应全平台、方便易用。

#### 引用

可选择在IDE中直接在引用目录中添加odt.h，或直接与需编译文件放在同一目录下，并引用：
`#include "odt.h"`

#### 使用

`odt.h`头文件内定义了一个名为`LampOpt`的`namespace`，其中有以下内容：

```cpp
struct CommandRead{//用于存储读取成功的参数的结构体
		std::string CommandName; //参数名称
		int argvl;//该参数对应的参数值在argv[]中的开始下标
		int argvr;//该参数对应的参数值在argv[]中的停止下标
};
```

和一个函数`std::vector<CommandRead> getopt`，用于读取命令，其原型如下：

```cpp
std::vector<CommandRead> getopt(int argc,char *argv[],std::vector<std::string>Settings)
```

返回结果为一个`std::vector<CommandRead>`类型的容器，下标依次列出了每条参数。

参数`argc`与参数`argv[]`为main函数的形参，最后的参数`std::vector<std::string>Settings`为参数的配置文件，其书写规则如下：

1. 从第一个参数开始，分别填写长参数与短参数，如第一个参数填写--help，而第二个参数填写-h时，则--help的长参数将与-h的短参数绑定。
2. 如果一个参数的长参数与短参数完整，则返回的CommandRead结构体中CommandName将会返回短参数的名称。
3. 长参数开头应带有--，短参数开头应带有-，而短参数必须带有-，长参数不做要求。
4. 可以选择不设置长参数或短参数，只需要在该参数位置填写none即可，如果短参数位置填写none，则返回的CommandRead结构体中CommandName将会返回长参数的名称。
5. 不允许长参数与短参数均填写none的情况存在。
6. 不允许Settings内元素个数为奇数的情况，这种情况下一定不合法。
7. 如果有类似tar -xzf的情况出现，返回的数组中将依次返回x、z、f，参数值共享。

如下为简单使用实例可以读取参数并输出读取到的参数与对应参数值：

```cpp
#include "opt.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(int argc,char *argv[]){
	vector<string>str={//参数设置初始化
		"--test","-t",
		"--help","-h"
	};
	vector<LampOpt::CommandRead>Ret=LampOpt::getopt(argc,argv,str);//接收读取结果
	for(int i=0;i<Ret.size();i++){
		cout<<Ret[i].CommandName<<" ";//输出参数名称
		for(int j=Ret[i].argvl;j<=Ret[i].argvr;j++)//依次枚举参数
			cout<<argv[j]<<" ";//输出参数值
		cout<<endl;
	}
    return 0;
}
``````

#### 报错信息

`Argument setting error`：编程者的参数设置错误，详见上文中的定义要求。
`Unknown argument`：用户的参数输入错误。
