#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "qh_string.h"


int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。

    qh::string a;
    char array[] = "hello world";
    qh::string b(array);
    b.print();
    qh::string c(array, 5);
    c.print();
    qh::string d(c);
    assert(d.size() == 5);
    d.print();
    d = b;
    d.print();
    assert(d.size() == 11);
    assert(d[4] == 'o');
    const char *p = d.c_str();
    assert(strlen(p) == 11);
    assert(p[3] == 'l');
    delete[] p;

    assert(memcmp(array, b.data(), b.size()) == 0);
   

	#ifdef WIN32
	    system("pause");
	#endif

	return 0;
}
