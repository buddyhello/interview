#include <stdlib.h>
#include "qh_vector.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�
    
    int array[] = {1,2,6,28};
   
    qh::vector<int> num_vect;
    num_vect.push_back(1);
    num_vect.push_back(2);
    
    for (int i = 0; i < 2; ++i)
    {
        assert(num_vect[i] == array[i]);
    }
    assert(num_vect.size() == 2);
    assert(num_vect.capacity() == 3);
    
    qh::vector<int> num_vect2;
    num_vect2 = num_vect;

    for (int i = 0; i < 2; ++i)
    {
        assert(num_vect2[i] == array[i]);
    }
    assert(num_vect2.size() == 2);
    assert(num_vect2.capacity() == 3);

    qh::vector<int> num_vect3(num_vect2);
    num_vect3.push_back(6);
    num_vect3.push_back(28);
    for (int i = 0; i < 4; ++i)
    {
        assert(num_vect3[i] == array[i]);
    }
    assert(num_vect3.capacity() == 7);
    assert(num_vect3.size() == 4);

    num_vect3.pop_back();
    for (int i = 0; i < 3; ++i)
    {
         assert(num_vect3[i] == array[i]);
    }
    assert(num_vect3.capacity() == 7);
    assert(num_vect3.size() == 3);

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

