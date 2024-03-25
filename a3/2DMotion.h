#ifndef MOTION2D
#define MOTION2D
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

// Predefined constant for pi, to be used if/when converting degrees
// to radians.
#define PI 3.14159265

// Forward declation of Force. Needed in case any of Point references
// the existence of type Force.
class Force;

class Point {
    // Private fields and helpers here.
    double x,y;
    
  public:
    // Required public interface here.

    //default constructor
    Point(double x,double y);
    Point();
    //overloaded input operator
    friend istream &operator>>(istream &, Point &);
    //overloaded output operator
    friend ostream &operator<<(ostream &, const Point &);
    //quadrant function
    int quadrant();
    //overloaded addition operator btw point and force
    friend Point operator+(Point, Force);
};


class Force {
    // Private fields and helpers here.
    double angle, mag;
  public:
    // Required public interface here.

    //default constructor
    Force(double angle,double mag);
    Force();
    //overloaded input operator
    friend istream &operator>>(istream &, Force &);
    //overloaded output operator
    friend ostream &operator<<(ostream &, const Force &);
    //overloaded multiplication operator between Force and int
    friend Force operator*(Force, int);
    //overloaded addition operator btw point and force
    friend Point operator+(Point, Force);
};


//overloaded addition operator btw point and force
Point operator+(Point p, Force F);
#endif
