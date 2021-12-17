# Singleton pattern

```
#include <cstdio>

class Singleton
{
private:
    Singleton() {}
    ~Singleton() {}

public:
    static Singleton& get()
    {
        static Singleton singleton;
        return singleton;
    }

    void method()
    {
        printf("Singleton::method\n");
    }
};

int main()
{
    Singleton::get().method();

    return 0;
}
```
