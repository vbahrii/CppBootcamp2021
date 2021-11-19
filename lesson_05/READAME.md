# Functions

## Name Mangling
https://en.wikipedia.org/wiki/Nm_(Unix)

main.c (main.cpp)
```
void func(int i) {}
void func2(int i, double d) {}
int func3(int i, double d, char c) { return 0; }

int main() {return 0;}
```

### C
`gcc main.c -o gcc.out`
`mn gcc.out`

> Output:
0000000100000000 T __mh_execute_header
0000000100003f60 T _func
0000000100003f70 T _func2
0000000100003f80 T _func3
0000000100003fa0 T _main
                 U dyld_stub_binder


### C++
`g++ main.cpp -o g++.out`
`mn g++.out`

> Output:
0000000100003f60 T __Z4funci
0000000100003f70 T __Z5func2id
0000000100003f80 T __Z5func3idc
0000000100000000 T __mh_execute_header
0000000100003fa0 T _main
                 U dyld_stub_binder

https://www.ibm.com/docs/en/zos/2.1.0?topic=scd-nm-display-symbol-table-object-library-executable-files
> Description
A - Absolute symbol, global
a - Absolute symbol, local
B - Uninitialized data (bss), global
b - Uninitialized data (bss), local
D - Initialized data (bbs), global
d - Initialized data (bbs), local
F - File name
l - Line number entry (see the –a option)
N - No defined type, global. This is an unspecified type, compared to the undefined type U.
n - No defined type, local. This is an unspecified type, compared to the undefined type U.
S - Section symbol, global
s - Section symbol, local
T - Text symbol, global
t - Text symbol, local (static)
U - Undefined symbol
>>>

## Name Demangling 
https://www.ibm.com/docs/en/xl-c-and-cpp-aix/12.1.0?topic=names-demangling-compiled-cfilt

`c++filt __Z5func3idc __Z5func2id`

> Output: 
func3(int, double, char)
func2(int, double)

## Disable mangling in C++

```
#ifdef __cplusplus
extern "C" {
#endif
    void non_mangled_function()
    {
    	// I do nothing
    }
#ifdef __cplusplus
}
#endif
```

## Overloading
```
void func(int i) { func(i, 0); }
void func(int i, double d) { func(i, d, '0'); }
void func(int i, double d, char c) 
{ 
    int result = i;
    if (d != 0.0) {
        result += 1;
    }
    if (c != '0') {
        result *= 2;
    }
    
    std::cout << result << std::endl;
}
```

## Default arguments
```
void func(int i, double d = 0.0, char c = '0') 
{
    // ...
}
```

## Template functions
```
#include <iostream>

template <class T>
void printType(T t) 
{
    std::cout << __PRETTY_FUNCTION__ << " " << typeid(t).name() << std::endl;
}

void printType(int t)
{
    std::cout << __PRETTY_FUNCTION__ << " " << typeid(t).name() << std::endl;
}

int main()
{
	printType(false);
	printType("str");
	printType(1);
	
	return 0;
}
```

> Output: 
void printType(T) [T = bool] b
void printType(T) [T = const char *] PKc
void printType(int) i

## Lambda functions
```
[](){};
// [] - capture list
// () - argument list
// {} - function body

[]{}; // lambda without argument list
```

```
int main() 
{
    auto lambda0 = []{};
    auto lambda1 = [](){};
    auto lambda2 = [](int a, int b){ return a + b;};
    
    std::cout << typeid(lambda0).name() << std::endl;
    std::cout << typeid(lambda1).name() << std::endl;
    std::cout << typeid(lambda2).name() << std::endl;
}
```

> Output:
Z4mainE3$_0
Z4mainE3$_1
Z4mainE3$_2


## Capture list
```
#include <iostream>

int main()
{
	int x = 0;
	int y = 0;
	auto lambda = [x, &y](int a, int b) mutable {
		x = a;
		y = b;	
	};

	lambda(1,2);
	std::cout << "x = " << x << ", y = " << y << std::endl;
	
	return 0;
}
```

`g++ -std=c++11 lambda.cpp && ./a.out`
> Output: 
x = 0, y = 2

## Trailing return type
```
int main()
{
	auto sum = [](int a, int b) -> int {
		return a + b;	
	};

	int x = 1;
	int y = 2;
	auto result = sum(x, y);
	std::cout << x << " + " << y << " = " result << std::endl;
	
	return 0;
}
```
