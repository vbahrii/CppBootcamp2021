# Operator overloading
https://en.cppreference.com/w/cpp/language/operators

## Functor
```
#include <iostream>

class Functor
{
public:
    int operator()(int x, int y) {
        return x + y;
    }
};

int main()
{
    Functor f;
    auto result = f(10, 20);
    std::cout << "result: " << result << std::endl;
    
    result = [](int x, int y) { return x + y; }(10, 20);
}
```

## Ostream operator overloading
```
class Person
{
public:
    Person(const std::string_view inName, int inAge) : name(inName), age(inAge)
    {
    }

    friend std::ostream& operator<< (std::ostream& os, const Person& inPerson);

private:
    std::string name;
    int age;
};

std::ostream& operator<< (std::ostream& os, const Person& inPerson) {
    os << inPerson.name << " " << inPerson.age << std::endl;
    return os;
}

int main()
{
    Person person("John", 38);
    std::cout << person << std::endl;
    std::cout << Person("Tony", 23) << std::endl;
}
```

## Arrow operator overloading
```
#include <iostream>
#include <string>

template <class T>
class SafePointer
{
public:
    SafePointer(T* inPtr) : ptr(inPtr)
    {

    }

    ~SafePointer()
    {
        if (ptr) {
            delete ptr;
        }
    }

    operator bool() {
        return ptr != nullptr;
    }

    T* operator->() {
        return ptr;
    }

private:
    T* ptr = nullptr;
};

class Test
{
public:
    Test() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    ~Test() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    void print() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

int main() {
    SafePointer sp(new Test);
    if (sp) {
        sp->print();
    }

    return 0;
}

```

# OOP 
## Inheritance

```
#define __USE_PROTECTED_MEMBERS__
#define __USE_PRIVATE_INHERITANCE__

class Point2D
{
public:
    void set(int inX, int inY) {
        x = inX;
        y = inY;
    }

    void setX(int inX) { x = inX; }
    void setY(int inY) { y = inY; }

    int getX() const {return x;}
    int getY() const {return y;}

#ifdef __USE_PROTECTED_MEMBERS__
    protected: // allows to use x and y in derived classes directly
#else
    private:
#endif
    int x;
    int y;
};

class Point3D :
        #ifndef __USE_PRIVATE_INHERITANCE__
            public
        #endif
        Point2D
{
public:
    void set(int inX, int inY, int inZ) {
#ifdef __USE_PROTECTED_MEMBERS__
        x = inX;
        y = inY;
#else
        Point2D::set(inX, inY);
#endif
        z = inZ;
    }

    void setZ(int inZ) { z = inZ; }
    int getZ() const {return z;}

private:
    int z;
};


int main()
{
    Point2D p2d;
    p2d.set(20, 10);
    p2d.setX(1);
    p2d.setY(2);

    ///
    Point3D p3d;
    p3d.set(10,20,30);

#ifndef __USE_PRIVATE_INHERITANCE__
    p3d.setX(10);
    p3d.setY(10);
#endif
    p3d.setZ(10);

    return 0;
}
```

## Multiple inheritance
```
class Animal
{
public:
    int age;
};

class Donkey : public Animal
{

};

class Horse : public Animal
{

};

class Mule : public Donkey, public Horse
{

};

int main()
{
    Donkey donkey;
    Horse horse;
    Mule mule;

    donkey.age = 4;
    horse.age = 3;
    mule.age = 1; // <-- 'age' found in multiple base classes (diamond problem)
}
```
