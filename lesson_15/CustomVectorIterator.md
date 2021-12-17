# Custom Vector Iterator class

## iterator class code
```
class iterator
{
public:
    iterator(T* ptr)
        : mPtr(ptr)
    {

    }

    iterator& operator++()
    {
        mPtr++;
        return *this;
    }

    iterator operator++(int)
    {
        iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator==(const iterator& rhs)
    {
        return (mPtr == rhs.mPtr);
    }

    bool operator!=(const iterator& rhs)
    {
        return !(*this == rhs);
    }

    T& operator*()
    {
        return *mPtr;
    }

    T* operator->()
    {
        return mPtr;
    }

private:
    T* mPtr = nullptr;
};

```

## New methods for Vector

```
template <class T>
class Vector
{
// ..... //
public:
    iterator begin()
    {
        return iterator(mArray.get());
    }

    iterator end()
    {
        return iterator(mArray.get() + mSize);
    }
};
```

## Full Example
```
#include <cstdio>
#include <functional>
#include <memory>
#include <algorithm>
#include <iterator>

#define __TRACE__ printf("[%p] %s\n", this, __PRETTY_FUNCTION__);

template <class T>
class Vector
{
private:
    static constexpr int kDefaultCapacity = 5;

public:
    class iterator
    {
    public:
        iterator(T* ptr)
            : mPtr(ptr)
        {

        }

        iterator& operator++()
        {
            mPtr++;
            return *this;
        }

        iterator operator++(int)
        {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const iterator& rhs)
        {
            return (mPtr == rhs.mPtr);
        }

        bool operator!=(const iterator& rhs)
        {
            return !(*this == rhs);
        }

        T& operator*()
        {
            return *mPtr;
        }

        T* operator->()
        {
            return mPtr;
        }

    private:
        T* mPtr = nullptr;
    };

public:
    Vector(int size = 0, int capacity = 0)
        : mSize(size)
        , mCapacity(capacity > 0 ? capacity : kDefaultCapacity)
    {
        mArray = std::unique_ptr<T[]>(new T[mCapacity]);
    }

    std::size_t size() const
    {
        return mSize;
    }

    std::size_t capacity() const
    {
        return mCapacity;
    }

    bool empty() const
    {
        return size() == 0;
    }

    void push_back(const T& value)
    {
        mArray.get()[mSize++] = value;
    }

    void pop_back()
    {
        if (mSize > 0)
            mSize--;
    }

    T& operator[](std::size_t idx)
    {
        return mArray.get()[idx];
    }

    void resize(std::size_t size)
    {
        reserve(size);
        if (size > mSize) {
            for (std::size_t i = mSize; i < size; i++) {
                mArray.get()[i] = T();
            }
        }
        mSize = size;
    }

    void reserve(std::size_t capacity)
    {
        if (capacity > mCapacity) {
            auto array = std::unique_ptr<T[]>(new T[capacity]);
            memcpy(array.get(), mArray.get(), mSize * sizeof(T));
            mArray = std::move(array);
            mCapacity = capacity;
        }
    }

    iterator begin()
    {
        return iterator(mArray.get());
    }

    iterator end()
    {
        return iterator(mArray.get() + mSize);
    }

private:
    std::unique_ptr<T[]> mArray;
    std::size_t mSize;
    std::size_t mCapacity;
};

int main()
{
    Vector<int> vector;
    vector.push_back(1);
    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);
    vector.push_back(5);

    vector.resize(10);

    for (int i = 0; i < vector.size(); i++) {
        printf("vector[%d]=%d\n", i, vector[i]);
    }

    for (auto it = vector.begin(); it != vector.end(); ++it) {
        printf("%d\n", *it);
    }


    struct Int
    {
    public:
        void method() { printf("method\n");}
    };

    Vector<Int> v;
    v.push_back({});
    v.push_back({});

    for (auto it = v.begin(); it != v.end(); ++it) {
        it->method();
    }

    return 0;
}
```



