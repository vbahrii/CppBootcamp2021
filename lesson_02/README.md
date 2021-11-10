# Math

```
void foo() {
    int a = 6;
    int b = 10;
    
    auto c = a + b; // 16
    c = a - b; // -4
    c = a * b; // 60
    c = a / b; // 0
    c = b / a; // 1
    c = a % b; // 6
    c = b % a; // 4
    
    auto d = 10 / 6.0; // 1.66667
}
```

# Arrays
https://en.cppreference.com/w/c/language/array_initialization

```
int arr[10] = {0};
int arr2[2][2] = {{0, 1}, {2, 3}};
int arr3[5][2];
memset(arr3, 0, sizeof(arr3));

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        std::cout << "arr2[" << i << "][" << j << "] = " << arr2[i][j] << std::endl;
    }
}
```

## Find min exmaple
```
#include <iostream>
#include <climits>

int findMinElement(int* arr, int size) 
{
    int min = INT_MIN;
    if (size > 0) {
        min = arr[0];
        
        for (int i = 1; i < size; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
    }
    
    return min;
}

int main()
{
    int arr[] = {0, 11, -10, 32};
    auto min = findMinElement(arr, sizeof(arr));
    std::cout << "min element: " << min << std::endl;
    
    return 0;
}
```

```
void arrayElements() {
    int arr[] = {1,2,3,4,5};
    auto size = sizeof(arr)/sizeof(arr[0]);

    for (size_t i = 0; i < size; i++) {
        std::cout << i << " " << &arr[i] << std::endl;
    }

    std::cout << "arr[0] = " << arr[0] << std::endl;
    std::cout << "arr[1] = " << 1[arr] << std::endl;
    std::cout << "arr[2] = " << *arr + 2 << std::endl;
    std::cout << "arr[3] = " << *(3 + arr) << std::endl;

    *(arr + 4) = 5;
    std::cout << "arr[4] = " << arr[4] << std::endl;
}
```

# C strings

```
#include <iostream>
#include <typeinfo>

void foo() {
    char str[] = "hello world";
    std::cout << "sizeof(str) = " << sizeof(str) << ", strlen(str) = " << strlen(str) << std::endl; // sizeof(str) = 12, strlen(str) = 11
}

void bar() {
    const char* str = "my string";
    char str2[]     = "my string 2";
    char str3[100]  = "my string 3";
    auto str4       = "my string 4";
    int a[5];

    std::cout << typeid(str).name() << std::endl;  // PKc
    std::cout << typeid(str2).name() << std::endl; // A10_c
    std::cout << typeid(str3).name() << std::endl; // A100_c
    std::cout << typeid(str4).name() << std::endl; // PKc
    std::cout << typeid(a).name() << std::endl;    // A5_i
}

void printString() {
    char str[] = "Hello world";
    char* ptr = str;
    while (*ptr != '\0') {
        std::cout << *ptr;
        ptr++;
    }
    std::cout << std::endl;
}

int myStrlen(char* str) {
    int len = 0;
    char* ptr = str;
    while (*ptr != '\0') {
        ptr++;
        len++;
    }
    return len;
}
```

