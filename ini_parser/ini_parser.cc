#include "ini_parser.h"


namespace qh
{
    INIParser::INIParser(){}
    INIParser::~INIParser(){}

    bool INIParser::Parse(const char* ini_data, size_t ini_data_len, const std::string& line_seperator, const std::string& key_value_seperator)
    {
    	std::string str(ini_data, ini_data_len);
    	size_t start, end;
    	std::string temp;
    	start = str.find_first_not_of(line_seperator);   //start为键的起始位置
    	if(start == std::string::npos)
    		return false;
    	while(start != std::string::npos)
    	{
    	    end = str.find_first_of(line_seperator, start+1);     //end为下一个行分割符的起始位置
    	    if(end != std::string::npos)
	    {
	         temp = str.substr(start, end-start);
	    }
	    else
	    {
	         temp = str.substr(start);                      //字符串末尾没有行分割符
	    }
	    if(temp.find(key_value_seperator) == std::string::npos)
	        return false;
            size_t pos = temp.find_first_of(key_value_seperator);   //键分割符所在位置
	    std::string key = temp.substr(0, pos);                  //键
	    std::string value = temp.substr(pos+1);                 //值
	    ini_map[key] = value;
            if(end == std::string::npos)
                break;
	    start = str.find_first_not_of(line_seperator, end+1);   //下一个键起始位置
    	}
        return true;
    }

    const std::string INIParser::Get(const std::string& key, bool* found)
    {
    	if(ini_map.find(key) != ini_map.end()) //找到返回键所对应的值
    	{
    	    if(found) *found = true;
    	    return ini_map[key];
    	}
    	else
    	{
    	    if(found) *found = false;     //如果没有找到返回空字符串
    	    return "";
    	}
    }
}
