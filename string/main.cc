#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "qh_string.h"


int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�

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
