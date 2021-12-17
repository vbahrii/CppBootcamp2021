# Custom Vector class

```
#include <cstdio>
#include <functional>
#include <memory>

#define __TRACE__ printf("[%p] %s\n", this, __PRETTY_FUNCTION__);

template <class T>
class Vector
{
private:
    static constexpr int kDefaultCapacity = 5;
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

    T& operator[](size_t idx)
    {
        return mArray.get()[idx];
    }

    void resize(std::size_t size)
    {
        reserve(size);
        if (size > mSize) {
            for (int i = mSize; i < size; i++) {
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

private:
    std::unique_ptr<T[]> mArray;
    std::size_t mSize;
    std::size_t mCapacity;
};

int main()
{
    Vector<int> vector;
    vector.push_back(1);

    printf("size=%d, capacity=%d\n", vector.size(), vector.capacity());

    vector.pop_back();
    printf("size=%d, capacity=%d\n", vector.size(), vector.capacity());

    vector.push_back(2);
    vector.push_back(3);
    vector.push_back(4);
    vector.push_back(5);

    vector.resize(10);

    for (int i = 0; i < vector.size(); i++) {
        printf("vector[%d]=%d\n", i, vector[i]);
    }

    return 0;
}

```

## Output
```
size=1, capacity=5
size=0, capacity=5
vector[0]=2
vector[1]=3
vector[2]=4
vector[3]=5
vector[4]=0
vector[5]=0
vector[6]=0
vector[7]=0
vector[8]=0
vector[9]=0
```
