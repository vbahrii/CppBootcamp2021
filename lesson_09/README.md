# Structures 
```
struct Point 
{
    int x;
    int y;
};

int main() {
    Point p2 = {10, 20};
    Point p3; 
    p3.x = 10;
    p3.y = 20;
    
    Point* p4 = new Point;
    p4->x = 10;
    p4->y = 20;
    
    return 0;
}
```

# Classes
```
class Point
{
public:
    Point(int x = 0, int y = 0) 
    {
        this->x = x;
        this->y = y;
    }
public:
    int x;
    int y;
};

int main() {
    Point p1(10, 20);
    Point* p5 = new Point(10);
    p5->y = 20;
    
    return 0;
}
```

# Methods
```
class Point 
{
public:
    Point(int x = 0, int y = 0)
        : x(x)
        , y(y)
    {
    }
    
    void setX(int x) {
        this->x = x;
    }
    
    void setY(int y) {
        this->y = y;
    }
    
    int getX() const {
        return x;
    }
    
    int getY() const {
        return y;
    }
    
    static Point createPoint(int x, int y) {
        Point p(x, y);
        return p;
    }
    
private:
    int x = 0;
    int y = 0;
};
```
