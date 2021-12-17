## Constructors
```
#include <cstdio>
#include <functional>

#define __TRACE__ printf("[%p] %s\n", this, __PRETTY_FUNCTION__);

class Int
{
public:
    Int(int i = 0) : i(i)
    {
        __TRACE__;
    }

    Int(const Int& rhs) {
        __TRACE__;

        i = rhs.i;
    }

    Int(Int&& rhs) {
        __TRACE__;

        i = std::move(rhs.i);
    }

    Int& operator=(const Int& rhs) {
        __TRACE__;

        i = rhs.i;
        return *this;
    }

    Int& operator=(Int&& rhs) {
        __TRACE__;

        i = std::move(rhs.i);
        return *this;
    }

    ~Int()
    {
        __TRACE__;
    }

private:
    int i = 0;
};

int main()
{
    Int i;                  // constructor
    Int j = 10;             // constructor

    Int k(j);               // copy constructor
    Int l(std::move(k));    // move constructor
    // k is not valid after it was moved

    i = j;                  // assignment operator
    i = std::move(j);       // move operator
    // j is not valid after it was moved

    return 0;
}
```

https://en.cppreference.com/w/cpp/language/rule_of_three


