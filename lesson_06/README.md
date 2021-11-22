# Typical program layout

This shows the typical layout of a simple computer's program memory with the text, various data, and stack and heap sections. https://en.wikipedia.org/wiki/Data_segment
![](https://upload.wikimedia.org/wikipedia/commons/thumb/5/50/Program_memory_layout.pdf/page1-299px-Program_memory_layout.pdf.jpg)

## .text
The code segment, also known as text segment, contains executable code and is generally read-only and fixed size.

## .data 
The data segment contains initialized static variables, i.e. global variables and local static variables which have a defined value and can be modified. Examples in C include:

## .bss
The BSS segment contains uninitialized static data, both variables and constants, i.e. global variables and local static variables that are initialized to zero or do not have explicit initialization in source code. Examples in C include:

## .heap
The heap segment contains dynamically allocated memory

## .stack
The stack segment contains the call stack, a LIFO structure

# Lifetime
There are three types of lifetimes in C: 
* static (program execution) 
* automatic (block execution, allocated on the stack) 
* manual (allocated on the heap). 

Only static and automatic are supported for variables and handled by the compiler, while manually allocated memory must be tracked manually across different variables

# Visiblity
There are three levels of visibility in C: 
* external linkage (global), 
* internal linkage (roughly file) 
* block scope (which includes functions); 

The lifetime and visibility of a variable are determined by its storage class https://en.wikipedia.org/wiki/C_syntax#Storage_class_specifiers

## Example 
https://en.wikipedia.org/wiki/Nm_(Unix)
```
/*
 * File name: test.c
 * For C code compile with: 
 * gcc -c test.c
 *
 * For C++ code compile with:
 * g++ -c test.cpp
 */

int global_var;
int global_var_init = 26;

static int static_var;
static int static_var_init = 25;

static int static_function()
{
	return 0;
}

int global_function(int p)
{
	static int local_static_var;
	static int local_static_var_init=5;

	local_static_var = p;

	return local_static_var_init + local_static_var;
}

int global_function2()
{
	int x;
	int y;
	return x+y;
}

#ifdef __cplusplus
extern "C"
#endif
void non_mangled_function()
{
	// I do nothing
}

int main(void)
{
	global_var = 1;
	static_var = 2;

	return 0;
}
```

# Heap memory allocation
C language provides next functions `malloc, calloc, realloc, free`
C++ gives `new, delete, new[], delete[]`

Both malloc() and new are used to allocate the memory dynamically in heap. But “new” does call the constructor of a class whereas “malloc()” does not.

## malloc/free example
```
int main() {
    {
        int stackSrray[10];
    }
    
    {
        int *array = (int*)malloc(10 * sizeof(int));
        // ...
        free(array);
    }
    
    {
        long* longValue = (long*)malloc(sizeof(long));
        *longValue = 12321;
        free(longValue);
    }
    
    return 0;
}
```

## new/delete example
```
#include <iostream>

int main() {
    {
        int* ptr = new int(0);
        *ptr = 42;
        delete ptr;
    }
    
    {
        int* array = new int[10];
        memset(array, 0, sizeof(array));
        array[1] = 1;
        std::cout << array[0] << "; " << array[1] << std::endl;
        delete[] array;
    }
    
    return 0;
}
```

## Smart pointers
```
#include <memory>

int main() {
    // unique pointers
    {
        std::unique_ptr<int> value = std::unique_ptr<int>(0);
        *value = 12;
        
        auto value2 = std::make_unique<int>(0);
        *value2 = 12;
        
        auto value3 = value; // <-- compilation error (no copy constructor)
        auto& value4 = value; // OK
    }
    
    // shared pointers
    {
        std::shared_ptr<int> value = std::shared_ptr<int>(0);
        *value = 12;
        
        auto value2 = value;
        std::cout << "Value Ref Counter = " << value.use_count() << std::endl;
        
        auto value3 = std::make_shared<int>(0);
        auto& value4 = value3;
        std::cout << "Value3 Ref Counter = " << value3.use_count() << std::endl;
    }
    
    // weak pointers
    {
        auto shared = std::make_shared<int>(5);
        std::weak_ptr<int> weak = shared;
        std::cout << "shared Ref Counter = " << shared.use_count() << std::endl;
        
        if (auto ptr = weak.lock()) {
            std::cout << "ptr Ref Counter = " << shared.use_count() << std::endl;
            *ptr = 25;
        }
    }
    
    return 0;
}
```

```
#include <iostream>
#include <memory>

struct Test 
{
    // constructor
    Test() {
        std::cout << __FUNCTION__ << "[" << this << "]" << std::endl;
    }
  
    // destructor
    ~Test() {
        std::cout << __FUNCTION__ << "[" << this << "]" << std::endl;
    }
};

int main() {
    Test t1;
    Test* t2 = new Test();
    auto t3 = std::unique_ptr<Test>();
    
    // malloc / free won't invoke a constructor and a destructor
 
    return 0;
}
```

