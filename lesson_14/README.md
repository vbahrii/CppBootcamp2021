# STL Containers
 * vector
 * list
 * set
 
![vector](https://4.bp.blogspot.com/-Mei6WNl9-5Y/WbETqEGkyLI/AAAAAAABVgY/RpSHsE7aS8osVYD20yUNSOwEuny_J8h4ACLcBGAs/s1600/%25E8%259E%25A2%25E5%25B9%2595%25E5%25BF%25AB%25E7%2585%25A7%2B2017-09-07%2B%25E4%25B8%258B%25E5%258D%25885.38.19.png)

![list](https://i.stack.imgur.com/7Qtyo.png)

![set (rb tree)](http://4.bp.blogspot.com/-pz-RYXed8Iw/UuPpXTjyMLI/AAAAAAAAADA/mmt1D8mz0Jk/s1600/Internal+Structure+of+Sets+and+Multisets.png)

## Containers common methods
* size()
* empty()
* iterators: begin(), end(), rbegin(), rend(), cbegin(), cend(), crbegin(), crend()

## Iterators
https://en.wikipedia.org/wiki/Iterator

In computer programming, an iterator is an object that enables a programmer to traverse a container, particularly lists. Various types of iterators are often provided via a container's interface. Though the interface and semantics of a given iterator are fixed, iterators are often implemented in terms of the structures underlying a container implementation and are often tightly coupled to the container to enable the operational semantics of the iterator. An iterator performs traversal and also gives access to data elements in a container, but does not itself perform iteration (i.e., not without some significant liberty taken with that concept or with trivial use of the terminology)[citation needed]. An iterator is behaviorally similar to a database cursor. Iterators date to the CLU programming language in 1974.

The C++ language makes wide use of iterators in its Standard Library and describes several categories of iterators differing in the repertoire of operations they allow. These include forward iterators, bidirectional iterators, and random access iterators, in order of increasing possibilities.

## Examples
```
#include <iostream>

#include <vector>
#include <list>
#include <set>
#include <map>

#define __TRACE__ std::cout << "=====" << __PRETTY_FUNCTION__ << "=====" << std::endl;

struct Person
{
    std::string name;
    int age;
};

class VectorUsage
{
public:
    template <class T>
    void printVector(const std::vector<T>& v, std::string_view title = "") {
        if (!title.empty()) {
            std::cout << title << " ";
        }

        std::cout << "[";
        bool first = true;
        for (const auto& e : v) {
            if (!first)
                std::cout << ", ";
            std::cout << e;
            if (first) {
                first = false;
            }
        }
        std::cout << "]" << std::endl;
    }

    void primitiveTypes() {
        __TRACE__

                std::vector<int> v;
        v = {1,2,3};

        if (v[0] == 1) {
            v[0]++;
        }

        printVector(v);

        std::cout << "vector size: " << v.size() << " is empty: " << std::boolalpha << v.empty() << std::endl;
        v.clear();
        std::cout << "vector size: " << v.size() << " is empty: " << std::boolalpha << v.empty() << std::endl;
    }

    void methodAtVsOperator() {
        __TRACE__

                try {
            std::vector<int> v;
            v.at(1) = 0; // method at() may throw an exception
        } catch (std::range_error& e) {
            std::cerr << "exception caught: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "unknown exception caught" << std::endl;
        }

        if (0) {
            std::vector<int> v;
            v[1] = 0; // no exceptions - doesn't check for out of range index
        }
    }

    void iterators() {
        __TRACE__

                std::vector<int> v = {5,3,1};

        // auto == std::vector<int>::iterator
        for (auto it = v.begin(); it != v.end(); ++it) {
            *it = *it + 1;
        }
        printVector(v, "Increased by 1");

        // auto == std::vector<int>::const_iterator
        for (auto it = v.cbegin(); it != v.cend(); ++it) {
            // *it = 0; // const iterator prevents assignment
        }

        std::cout << "Print in reversed order: ";
        // auto == std::vector<int>::reverse_iterator
        for (auto it = v.rbegin(); it != v.rend(); ++it) {
            std::cout << *it;
        }
        std::cout << std::endl;

        // auto == const int&
        for (const auto& it : v) { (void)it; }

        // auto == int&
        for (auto& it : v) { (void)it; }
    }

    void useAsArray() {
        __TRACE__

                std::vector<int> v{1,2,3,4,5};
        int* array = v.data();

        for (int i = 0; i < 5; i++) {
            array[i] += 1;
            std::cout << i << " => " << array[i] << std::endl;
        }
    }

    void customTypes() {
        __TRACE__

                std::vector<Person> p;
        p.push_back(Person{"John", 30});
        p.push_back(Person{"Peter", 12});

        std::cout << "size: " << p.size() << std::endl;
        p.pop_back();
        std::cout << "size after pop_back: " << p.size() << std::endl;
    }

    void sizeVsCapacity() {
        __TRACE__

                std::vector<int> v(3); // inserts 3 default elements
        std::cout << "size: " << v.size() << ", capacity: " << v.capacity() << std::endl;

        for (int i = 0; i < 5; i++) {
            v.push_back(i);
        }
        std::cout << "size: " << v.size() << ", capacity: " << v.capacity() << std::endl;

        std::vector<int> v1;
        v1.reserve(5);
        std::cout << "v1 size: " << v1.size() << ", capacity: " << v1.capacity() << std::endl;
        for (int i = 0; i < 25; i++) {
            v1.push_back(i);
        }
        std::cout << "v1 size: " << v1.size() << ", capacity: " << v1.capacity() << std::endl;
    }

    void run()
    {
        primitiveTypes();
        customTypes();
        useAsArray();

        iterators();

        methodAtVsOperator();
        sizeVsCapacity();
    }
};

void listUsage()
{
    __TRACE__

            // std::list is a container that supports constant time
            // insertion and removal of elements from anywhere in the container.
            // Fast random access is not supported.
            // https://en.cppreference.com/w/cpp/container/list
            std::list<int> l = {1,2,3,4,5};
    // l[0] = 2; // operator[] is not implemented due to efficiency issues

    for (auto it = l.begin(); it != l.end(); ++it) {
        *it = 0;
    }
}

//https://en.cppreference.com/w/cpp/container/set/
//std::set is an associative container that contains a sorted set of unique objects of type Key.
// Sorting is done using the key comparison function Compare.
// Search, removal, and insertion operations have logarithmic complexity.
// Sets are usually implemented as red-black trees.
void setUsage()
{
    __TRACE__

    std::set<int> s = {3, 4, 2, 6, 1};
    for (const auto& e : s) {
        std::cout << e << std::endl;
    }

    std::cout << "s size = " << s.size() << std::endl;
    s.insert(5);
    s.insert(6);
    std::cout << "s size = " << s.size() << std::endl;

    s.erase(5);
    std::cout << "s size = " << s.size() << std::endl;
}

void setCustomTypes() {
    struct User {
        std::string name;
        int age;

        bool operator<(const User& rhs) const {
            return this->age < rhs.age;
        }
    };
    std::set<User> users;
    users.insert({"Jack", 21});

    auto comparator = [](const Person& lhs, const Person& rhs) -> bool { return lhs.age < rhs.age; };
    std::set<Person, decltype(comparator)> people(comparator);
    people.insert({"John", 33});


    ////
    struct PersonCmp {
        bool operator()(const Person& lhs, const Person& rhs) const {
            return lhs.age < rhs.age;
        }
    };
    std::set<Person, PersonCmp> p;
    p.insert({"Nick", 44});

}

// https://en.cppreference.com/w/cpp/container/map
void mapUsage()
{
    __TRACE__

    std::map<std::string, int> users;
    users.insert({"Jack", 20});
    users["Jack"] = 45;
    users["Nick"] = 4;

    std::cout << "Jack's age: " << users["Jack"] << std::endl;
    std::cout << "John's age: " << users["John"] << std::endl;
    std::cout << "users size: " << users.size() << std::endl;
}

int main()
{
    // https://en.cppreference.com/w/cpp/container/vector
    VectorUsage().run(); // std::vector is a sequence container that encapsulates dynamic size arrays.
    setCustomTypes();
    return 0;
}

```
