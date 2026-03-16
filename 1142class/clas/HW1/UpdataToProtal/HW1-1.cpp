#include <iostream>

using namespace std;

const double pai=3.14159;

class Circle
{
protected:
    double radius;
public:
    Circle(double _r): radius(_r){}
    void print(){
        cout<<"Radius: "<<radius<<'\n';
    }
    double getPerimeter(){
        return (double)2*pai*radius;
    }
    double getArea(){
        return pai*radius*radius;
    }
};

class Sphere : public Circle 
{
public:
    Sphere(double _r) : Circle(_r) {}
    double getSurface(){
        return (double)2*radius*getPerimeter();
    }
    double getVolume(){
        return (double)4/3*radius*getArea();
    }
};
int main(){
    // Instantiation and printing perimeter and area of a circle
    Circle cir(6.0);
    cout << "Circle: " << endl;
    cir.print();
    cout << "Perimeter: ";
    cout << cir.getPerimeter() << endl;
    cout << "Area: ";
    cout << cir.getArea() << endl << endl;
    // Instantiation and printing perimeter and area of a sphere
    Sphere sph(6.0);
    cout << "Sphere: " << endl;
    sph.print();
    cout << "Surface: ";
    cout << sph.getSurface() << endl;
    cout << "Volume: ";
    cout << sph.getVolume() << endl << endl;

    system("pause");

    return 0;
}