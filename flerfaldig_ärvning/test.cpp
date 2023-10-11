#include <iostream>

class Foo {
public:
        Foo(int x) : x(x) {}
        int x;
};

class Bar {
public:
        Bar(double y) : y(y) {}
        double y;
};

class Baz : public Foo, public Bar {
public:
        Baz(int x, double y);
};

Baz::Baz(int x, double y)
        : Foo(x)
        , Bar(y)
{}

int main()
{
        Baz baz(5, 3.14);
        std::cout << "X: " << baz.x << std::endl; // X: 5
        std::cout << "Y: " << baz.y << std::endl; // Y: 3.14
        return 0;
}
