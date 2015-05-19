#ifndef QIHOO_VECTOR_H_
#define QIHOO_VECTOR_H_
#include <assert.h>
#include <cstdio>


namespace qh
{
    template<class T>
    class vector {
    public:
        //ctor
        vector()
            : data_(NULL), size_(0), capacity_(0)
        {
        }
        
        explicit vector(size_t n, const T& value);
         
        vector(const vector<T>& rhs)
            :size_(rhs.size_), capacity_(rhs.capacity_)
        {   
            // operator=(rhs);          
            data_ = new T[capacity_];
            for (size_t i = 0; i < size_; ++i)
            {
                data_[i]  = rhs.data_[i];
            }
        }

        vector<T>& operator=(const vector<T>& rhs);
      
        //dtor
        ~vector()
        {
            clear();
        }

        //get vector size
        size_t size() const
        {
            return size_;
        }
        //get vector capacity
        size_t capacity() const
        {
            return capacity_;
        }
        // set & get
        T& operator[](size_t index)
        {
            assert(index >= 0 && index < size_);
            return data_[index];
        }

        // set
        void push_back(const T& element);
        
        void pop_back(void){ size_--; }

        void resize(int new_size)
        {
            if (new_size > capacity_)
                reserve(new_size*2);
            size_ = new_size;
            
        }

        void reserve(size_t new_capacity);
        void clear(void) { delete[] data_; }
        void empty(){ return 0 == size_; }

    private:
        T*      data_;
        size_t  size_;
        size_t  capacity_;
        enum  { SPACE_CAPACITY = 4 };
    };

template <class T>
vector<T>:: vector( size_t n, const T& value)
    : size_(n), capacity_(size_ + SPACE_CAPACITY)
{
    data_ = new T[capacity_];
    for (size_t i = 0; i < n; i++)
    {
        data_[i] = value;
    }
}

template <class T>
vector<T>& vector<T>::operator=(const vector<T>& rhs)
{
    if (this != &rhs)
    {
        delete[] data_;
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;

        data_ = new T[capacity()];
        for (size_t i = 0; i < size_; ++i)
        {
            data_[i]  = rhs.data_[i];
        }
    }
    return *this;
}

template <class T>
void vector<T>::reserve(size_t new_capacity)
{
    if (new_capacity < size_) return;
    
    T* old_array = data_;
    data_ = new T[new_capacity];
    for (size_t i = 0; i < size_; ++i)
    {
        data_[i] = old_array[i];
    }

    capacity_ = new_capacity;
    delete[] old_array;
}

template <class T>
void vector<T>::push_back(const T& element)
{
    if( size_ == capacity_ )
        reserve( 2*capacity_ + 1 );
    data_[ size_++ ] = element;
}
}

#endif


