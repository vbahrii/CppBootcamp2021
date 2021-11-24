# Type overflow

```
#include <iostream>

#define PRINT_VAR(var) std::cout << #var << " = " << var << std::endl;

void typeOveflow() {
    short s = SHRT_MAX - 5;
    for (int i = 0; i < 10; i++) {
        s++;
        PRINT_VAR(s);
    }

    unsigned char c = 3;
    for (int i = 0; i < 5; i++) {
        c--;
        PRINT_VAR((int)c);
    }
}
```

# Type cast
```
#include <iostream>

#define PRINT_VAR(var) std::cout << #var << " = " << var << std::endl;

void typeCasts()
{
    {
        double pi = 3.14;
        int a = pi;
        PRINT_VAR(a);

        int b = (int)pi;
        PRINT_VAR(b);
        
        int c = static_cast<int>(pi);
        PRINT(c);
    }


    {
        int i = SHRT_MAX + 1;
        short s = i;
        PRINT_VAR(i);
        PRINT_VAR(s);
    }

    {
        const int i = 10;
        int* ptr = const_cast<int*>(&i);
        *ptr = 11;
        std::cout << "[" << &i << "] i = " << i << " => " << *(&i) << std::endl;
    }
}
```

```
struct S1 { int a; };

int main()
{
    S1 s1;

    int* ptr = (int*)&s1;
    int* ptr2 = static_cast<int*>(&s1); // <-- not allowed
    int* ptr3 = reinterpret_cast<int*>(&s1);
    
    return 0;
}
```

# Pointer to pointer
```
template <class T>
void safe_delete_bad(T* ptr) {
    if (ptr) {
        delete ptr;
        ptr = nullptr;
    }
}

template <class T>
void safe_delete(T** ptr) {
    if (ptr && *ptr) {
        delete *ptr;
        *ptr = nullptr;
    }
}

template <class T>
void safe_delete_by_ref(T*& ptr) {
    if (ptr) {
        delete ptr;
        ptr = nullptr;
    }
}

int main() {
    auto ptr = new int(5);
    std::cout << ptr << std::endl;
    safe_delete_bad(ptr);
    // safe_delete(&ptr);
    //safe_delete_by_ref(ptr);
    std::cout << ptr << std::endl;
    
    return 0;
}
```

# Function output parameters
```
int div(int dividend, int divisor, bool* outDivisionByZero) {
   if (divisor == 0) {
       if (outDivisionByZero) {
           *outDivisionByZero = true;
       }
       return 0;
   }

   if (outDivisionByZero) {
       *outDivisionByZero = false;
   }
   return dividend / divisor;
}

int div2(int dividend, int divisor, bool& ouDivisionByZero) {
    ouDivisionByZero = false;
    if (divisor == 0) {
       ouDivisionByZero = true;
       return 0;
   }

   return dividend / divisor;
}

void divUsage() {
    bool isDivisionByZero = false;
    div(4, 0);
    div(4, 0, &isDivisionByZero);

    div2(4, 0, isDivisionByZero);
}
```

# Copy array
```
void copyArray() {
    // This works in C and C++
    int a[] = { 1, 2, 3, 4 };
    int b[4];
    memcpy(b, a, 4*sizeof(int)); // int is a POD
    
    // This is the preferred method to copy raw arrays in C++ and works with all types that can be copied:
    std::copy(a, a+4, b);
    
    // In C++11, you can also use this:
    std::copy(std::begin(a), std::end(a), std::begin(b));
}
```

# Enums
```
enum ErrorType {
    errorType_None,
    errorType_FileNotFound,
    errorType_UnknownError
};

enum class EErrorType {
    None,
    FileNotFound,
    UnknownError
};
```
