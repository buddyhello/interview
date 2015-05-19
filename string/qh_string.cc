#include "qh_string.h"
#include <iostream>
#include <string.h>
#include <assert.h>

namespace qh
{
    // TODO 将在这里写实现代码

    string::string()
        : data_(NULL), len_(0)
    {
    }

    string::string( const char* s )
    {
        len_ = strlen(s);
        data_ = new char[len_ + 1];
        strcpy(data_, s);
    }

    string::string( const char* s, size_t len )
    {
        len_ = len;
        data_ = new char[len_ + 1];
        strncpy(data_, s, len_);
        data_[len_] = '\0';
    }

    string::string( const string& rhs )
    {
        len_ = rhs.len_;
        data_ = new char[len_ + 1];
        strcpy(data_, rhs.data_);
    }

    string& string::operator=( const string& rhs )
    {
        if(this != &rhs)
        {
            delete[] data_;
            len_ = rhs.len_;
            data_ = new char[len_ + 1];
            strcpy(data_, rhs.data_);
        }
        return *this;
    }

    string::~string()
    {
        delete[] data_;
        len_ = 0;
    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
        if(data_ == NULL || len_ == 0)
            return NULL;
        char * result = new char[len_];
        strncpy(result, data_, len_);
        return result;
    }

    const char* string::c_str() const
    {
        if(data_ == NULL || len_ == 0)
            return NULL;
        char * result = new char[len_ + 1];
        strcpy(result, data_);
        return result;
    }

    char string::operator[]( size_t index )
    {
        assert(index >= 0 && index < len_);
        return data_[index];
    }

    void string::print(void) const
    {
        assert(data_ != NULL && len_ > 0);
        std::cout << data_ << std::endl;
    }

}
