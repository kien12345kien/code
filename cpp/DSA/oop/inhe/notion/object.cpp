#include <iostream>

using namespace std;

class Object{

};

class Shape : public virtual Object{
    double calArea(){
        return 0;
    }

    double calVolume(){
        return 0;
    }

    virtual string getName() {};

};

class Point : public virtual Shape{
    protected:
        double x;
        double y;
    
    public:
        Point(double x, double y) : x(x) , y(y) {}

        double calArea(){
            return 0;
        }

        double calVolume(){
            return 0;
        }

        string getName(){
            return "Point";
        }
};

class Circle : public virtual Point{
    protected:
        double radius;
    
    public:
        Circle(double x, double y, double radius): Point(x, y), radius(radius) {};

        double calArea(){
            return radius* radius* M_PI;
        }

        double calVolume(){
            return 0;
        }

        string getName(){
            return "Circle";
        }        
};

class Cylinder : public virtual Circle{
    protected:
        double height;
    
    public:
        Cylinder(double x, double y, double radius, double height): Circle(x, y, radius), height(height) {};

        double calArea(){
            return 2 * M_PI * radius * (radius + height); // Surface area of the cylinder
        }

        double calVolume(){
            return M_PI * radius * radius * height; // Volume of the cylinder
        }

        string getName(){
            return "Cylinder";
        }        
};

Cylinder cy(6, 7, 8, 9);

int main(){
    std::cout << "Cylinder: " << cy.getName() << ", Area: " << cy.calArea() << ", Volume: " << cy.calVolume() << std::endl;
    return 0;
}