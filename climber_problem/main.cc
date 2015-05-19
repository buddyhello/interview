#include <stdio.h>
#include <assert.h>
#include <vector>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

#define H_ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
    static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

/*函数功能：从pos位置开始到字符为delim位置的子字符串转换为整数
  参数：str:测试字符串
  	pos:转换的起始位置
  	delim: 字符串分割符
  返回值:  转换后的整数
*/

int strtoint(const string& str, size_t &pos, char delim)
{
    size_t end = str.find_first_of(delim, pos);
    string temp;
    if(end != std::string::npos)
    {
        temp = str.substr(pos, end-pos);
        pos = end+1;
    }
    else
    {
    //如果测试字符串最后一个字符不是'\n'，直接将pos到结尾的字符转换为整数保存
        temp = str.substr(pos);
    }
    return atoi(temp.c_str());
}
/*函数功能：将爬山数据转换为整数，并用vector<vector<int> >进行保存
  函数参数：str 测试字符串，代表爬山的数据
  返回值：转换后的vector<vector<int>
*/

vector<vector<int> > generate_vec(const string& str)
{
    vector<vector<int> > result;        //保存山的数据
    if(str.empty()) return result;
    size_t start = 0;
    int len = strtoint(str, start, '\n');   //山的数目
    vector<int> temp;
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            temp.push_back(strtoint(str, start, ','));   //保存山的水平起始位置与终止位置
        }
        temp.push_back(strtoint(str, start, '\n'));     //保存山的高度
        result.push_back(temp);
        temp.clear();
    }
    return result;
}

/*函数功能：计算爬山者需要爬的步数
  函数参数：需要爬的山的分布，使用字符串代表
  返回值：需要爬的步数
*/

int resolve(const char* input)
{
    string str(input);
    vector<vector<int> > vec;
    vec = generate_vec(str);
    int ret = 0;
    int mountain_num = vec.size();
    ret += vec[mountain_num-1][1];    //水平方向需要爬的步数为A到B的水平距离

    for (int i = 0; i < mountain_num; ++i)
    {
        ret += vec[i][2]*2;           //首先计算所有的山都不发生重叠的情况
    }

    for (int i = 1; i < mountain_num; ++i)
    {
        if(vec[i][0] <= vec[i-1][1])
            ret -= min(vec[i-1][2], vec[i][2])*2;   //发生重叠时，总步数减去两座山最小高度的2倍
    }
    return ret;
}

int main(int argc, char* argv[])
{
    const char* input[] = {
        "3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
        "1\n1,2,1\n",
        "2\n1,2,1\n2,3,2",
        "3\n1,2,1\n2,3,2\n3,6,1",
        "4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
        "5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
        "1\n0,1,1",
        "2\n0,1,1\n2,4,3",
        "3\n0,1,1\n2,4,3\n3,5,1",
        "4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
        "5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
        "6\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3\n7,9,4",
        "7\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3\n7,9,4\n10,11,2",
        "8\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3\n7,9,4\n10,11,2\n11,15,5\n",
        "9\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3\n7,9,4\n10,11,2\n11,15,5\n12,17,3\n",
        "10\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3\n7,9,4\n10,11,2\n11,15,5\n12,17,3\n15,19,7\n"
        };
    int expectedSteps[] = {25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20, 23, 29, 39, 41, 51};
    for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
    {
        assert(resolve(input[i]) == expectedSteps[i]);
    }
    return 0;
}
