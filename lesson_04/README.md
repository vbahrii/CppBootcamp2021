# Macro directives

## constans
```
#define PI 3.14
#define WORKER_THREADS 5
#define CLIENTS_PER_THREAD 2
#define MAX_CLIENTS WORKER_THREADS * CLIENTS_PER_THREAD
```

## expressions and functions
```
#define ARRAY_SIZE 10 + 25
#define ARRAY_SIZE2 (10 + 25)
#define MUL(x, y) x * y

MUL(2,5);    // 10
MUL(2+2,5);  // 12 <--- expected 20
MUL2(2,5);   // 10
MUL2(2+2,5); // 20
```

## user defined errors
```
#warning "my warning message"
#error "my error message"
```

## conditions
```
#if 0
    int factorial = 1;
    for (int i = 2; i < 10; i++) {
           factorial *= i;
    }
#endif

#ifdef QWERTY
    #error "QWERTY is defined"
#endif
```

## include
```
#include "myheader.h"
#include <iostream>
```

## include guard
```
#ifndef MYFILE_H
#define MYFILE_H
 // your code is here
#endif 
```

```
#pragma once
```

## patform dependent code
```
#ifdef __APPLE__
    #include "TargetConditionals.h"
    #ifdef TARGET_OS_IPHONE
         // iOS
    #elif TARGET_IPHONE_SIMULATOR
        // iOS Simulator
    #elif TARGET_OS_MAC
        // Other kinds of Mac OS
    #else
        // Unsupported platform
    #endif
#elif defined _WIN32 || defined _WIN64
    #include <GL\glut.h>
#endif
```

## predefined macro
```
__FILE__
__LINE__
__DATE__
__TIME__
__FUNCTION__
__PRETTY_FUNCTION__
```

## stringify
```
#define name(x) #x

int var = 101;
std::cout << name(var) << " = " << var << std::endl; // var = 101
```

## concatenation
```
#define glue(prefix, sufix) prefix ## sufix

glue(std::c, out) << "Hello world" << std::endl;
```

## helper functions
```
#define CHECK_NULL(ptr, returnValue) if (!ptr) return returnValue

void foo(int* ptr, char* str)
{
    CHECK_NULL(ptr, );
    CHECK_NULL(str, void());
}

int safeDereference(int* ptr, int defaultValue)
{
    CHECK_NULL(ptr, defaultValue);
    return *ptr;
}

template <class T>
T safeDereference(T* ptr, T defaultValue) 
{
    CHECK_NULL(ptr, defaultValue);
    return *ptr;
}
```

```
#define LOG(msg) std::cout << __FILE__ << ":" << __LINE__ << " [" << __FUNCTION__ << "] " << msg << std::endl;

int main() 
{
    // call function
    LOG("my log line");

    // output
    "../playground/main.cpp:38 [main] my log line"
    return 0;
}
```

## run preprocessor
```
// main.cpp
#define STR "string"
#define X 10
#define Y 20
#define Z 10 + 20
#define forever while (true) {}

int main()
{
    int x = X;
    int y = Y;
    int z = Z;
    int z1 = Z * 2;
    
    CHECK_NULL(&x);
    
    return 0;
}
```

## execute
```
g++ -E main.cpp
```

## output
```
// g++ -E main.cpp

# 1 "main.cpp"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 380 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "main.cpp" 2
# 54 "main.cpp"
int main()
{
    int x = 10;
    int y = 20;
    int z = 10 + 20;
    int z1 = 10 + 20 * 2;

    while (true) {}

    return 0;
}
```


