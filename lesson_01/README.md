# Data Types

## Primitives
```
char c;
bool b;
int i;
float f;
double d;
```

## More Integer Types
```
short int si;
long int li;
long long int lli;
size_t st;
int8_t i8;
int16_t i16;
int32_t i32;
int64_t i64;
```

## Arrays
```
char c[100];
double d[2];
int i[10];
```

## Arrays Example
```
int arr1[5];
int arr2[5] = {1,2,3};
for (int i = 0; i < 10; i++) 
{
    std::cout << arr1[i] << std::endl; // 0 32766 262635520 1-486221136
    std::cout << arr2[i] << std::endl; // 1 2 3 0 0
}
```

## Strings
```
const char* sz = nullptr;
std::string str;
```

## Variable Initialization
```
int a;
int b = 0;

int main() 
{
    int c;
    int d = 0;
    
    return 0;
}
```

## References
```
int a = 1;
int& b = a;
int* c = &b;

b = 2; // a == 2
*c = 3; // a == 3

int d = 42;
b = d; // a == 42
c = &d;
*c = 11; // d == 1; a == 42
```

# Conditional Branching 

```
bool b = true;
if (b == true) {
    std::cout << "b is true" << std::endl;
}
else  {
    std::cout << "b is false" << std::endl;
}

/////////////////////
int a = 5;
if (a == 1) {
    
}
else if (a == 2) {
    
}
else if (a > 2 && a <= 4) {
    // a = 3 || 4
}
else if (a == 5 || a == 6 || a == 7) {
    // a = 5 || 6 || 7
}
else {
    // a > 7 || a < 1
}
```

# Loops

## Print even numbers
```
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
        std::cout << i;   
    }
}
```
## Output
```
02468
```

## Print alphabet
```
for (char c = 'A'; c <= 'Z'; c++) {
    std::cout << c;
}
```
## Output
```
ABCDEFGHIJKLMNOPQRSTUVWXYZ
```
![ASCII TABLE](https://www.kindpng.com/picc/m/397-3973028_images-ascii-table-ascii-table-printable-hd-png.png)


