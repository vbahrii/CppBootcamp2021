# Polymorphism

## Abstract class
```
class Abstract
{
public:
    virtual void foo() = 0; // pure virtual function
};

int main() {
    Abstract a; //  error: variable type 'Abstract' is an abstract class
    return 0;
}
```

## dynamic_cast
```
class Shape
{
public:
    virtual ~Shape() = 0;
};
Shape::~Shape() {}


class Rectangle : public Shape {
public:
    ~Rectangle() override {}
};

class Square : public Rectangle {

};

int main()
{
    Shape* pRectangle = new Rectangle;
    Shape* pSquare = new Square;

    Rectangle* rect = dynamic_cast<Rectangle*>(pRectangle);
    Square* square = dynamic_cast<Square*>(pSquare);

    if (rect) {
//        ...
    }

    if (square) {
//        ...
    }

    delete pRectangle;
    delete pSquare;

    return 0;
}
```

## virtual desctructor
```
#include <iostream>
#include <memory>

#define __TRACE__ std::cout << __PRETTY_FUNCTION__ << " [" << this << "]" << std::endl;

class Shape
{
public:
    Shape() {
        __TRACE__
    }
    /*virtual*/ ~Shape() {
        __TRACE__
    }
};

class Rectangle : public Shape {
public:
    Rectangle() {
        __TRACE__
    }
    ~Rectangle() {
        __TRACE__
    }
};


int main()
{
    {
        Rectangle* pRectangle = new Rectangle;
        delete pRectangle;
    }

    std::cout << "------------" << std::endl;

    {
        Shape* pRectangle = new Rectangle;
        delete pRectangle;
    }

    std::cout << "------------" << std::endl;

    {
        std::shared_ptr<Shape> pRectangle = std::make_shared<Rectangle>(); // shared_ptr stores the original type of an object
    }

    std::cout << "------------" << std::endl;

    {
        std::unique_ptr<Shape> pRectangle = std::make_unique<Rectangle>();
    }

    return 0;
}
```

Output
```
Shape::Shape() [0x7fa69a405910]
Rectangle::Rectangle() [0x7fa69a405910]
Rectangle::~Rectangle() [0x7fa69a405910]
Shape::~Shape() [0x7fa69a405910]
------------
Shape::Shape() [0x7fa69a405910]
Rectangle::Rectangle() [0x7fa69a405910]
Shape::~Shape() [0x7fa69a405910]
------------
Shape::Shape() [0x7fa69a405938]
Rectangle::Rectangle() [0x7fa69a405938]
Rectangle::~Rectangle() [0x7fa69a405938]
Shape::~Shape() [0x7fa69a405938]
------------
Shape::Shape() [0x7fa69a405910]
Rectangle::Rectangle() [0x7fa69a405910]
Shape::~Shape() [0x7fa69a405910]
```

## Type slicing
```
#include <iostream>

class Shape {
public:
    virtual void print() {
        std::cout << "Shape" << std::endl;
    }
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void print() {
        std::cout << "Circle" << std::endl;
    }
};

void print(Shape shape) {
    shape.print();
}

int main()
{
    Shape* shape = new Circle;
    print(*shape);
    delete shape;

    return 0;
}
```

## Shadowing (name hiding)
```
#include <iostream>

class Shape {
public:
    virtual void print() {
        std::cout << "Shape" << std::endl;
    }
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void print(const std::string& inName) {
        std::cout << inName << std::endl;
    }
};

int main()
{
    Circle* shape = new Circle;
    shape->print(); // compilation error
    delete shape;

    return 0;
}
```

## Pure virual call
```
#include <iostream>

class Shape {
public:
    Shape() {
        print(); // pure virtual function call
    }

    virtual void print() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void print() override {
        std::cout << "Circle" << std::endl;
    }
};

int main()
{
    Shape* shape = new Circle;
    delete shape;

    return 0;
}



```

## virtual methods in action
### Painters
```
class IPainter {
public:
    virtual ~IPainter() = default;

    struct Rect {
        int x1;
        int y1;
        int x2;
        int y2;
    };
    struct Brush {};
    void setBrush(Brush) {}
    Brush getBrush() { return {}; }

    virtual void drawPoint() {}
    virtual void drawLine() {}
    virtual void drawArc() {}
    virtual void drawText(Rect /* inRect */, const std::string& /* inText */) {}
};

class ConsolePainter : public IPainter {
public:
    virtual void drawText(Rect inRect, const std::string& inText) {
        (void)inRect;
        std::cout << inText << std::endl;
    }
};
```

### Shapes
```
class Shape
{
public:
    Shape() = default;
    virtual ~Shape() = default;

    virtual void paint(IPainter* painter)  {
        if (painter) {
            painter->drawText({0, 0, 100, 40}, "Shape");
        }
    }
};

class Rectangle : public Shape {
public:
    virtual void paint(IPainter* painter)  {
        if (painter) {
            painter->drawText({0, 0, 100, 40}, "Rectangle");
        }
    }
};

class Square : public Shape {

};

class Circle : public Shape {
public:
    virtual void paint(IPainter* painter)  {
        if (painter) {
            painter->drawText({0, 0, 100, 40}, "Circle");
        }
    }
};
```

### Usage
```
int main()
{
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle);
    shapes.push_back(new Square);
    shapes.push_back(new Circle);

    IPainter* painter = new ConsolePainter;

    for (const auto& shape : shapes) {
        if (shape) {
            shape->paint(painter);
        }
    }

    for (const auto& shape : shapes) {
        delete shape;
    }
    shapes.clear();

    delete painter;
    painter = nullptr;

    return 0;
}
```

### Output
```
Rectangle
Shape
Circle
```


