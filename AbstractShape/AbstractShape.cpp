#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class Shape {
public:
    virtual double calculateArea() const = 0;
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double base, double height) : base(base), height(height) {}

    virtual double calculateArea() const override {
        return 0.5 * base * height;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    virtual double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}

    virtual double calculateArea() const override {
        return length * width;
    }
};

int main() {
    Triangle triangle(5, 3);
    Circle circle(4);
    Rectangle rectangle(6, 8);

    Shape* shapes[] = { &triangle, &circle, &rectangle };

    double totalArea = 0;
    for (const auto& shape : shapes) {
        totalArea += shape->calculateArea();
    }
    std::cout << "Total area of all shapes: " << totalArea << std::endl;

    return 0;
}
