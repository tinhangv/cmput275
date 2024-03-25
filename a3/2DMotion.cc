#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
#include "2DMotion.h"
using namespace std;

//point constructor
Point::Point(double x, double y): x{x},y{y} {}
Point::Point():x{0},y{0}{}

int Point::quadrant(){
    return y>=0 ? (x>=0 ? 1: 2) : (x<0 ? 3: 4);
}

Point operator+(Point p, Force F){
    return Point{p.x+F.mag*cos(F.angle*PI/180), p.y+F.mag*sin(F.angle*PI/180)};
}

//point input output operators
istream &operator>>(istream &in, Point &p){
    return in >> p.x >> p.y;
}
ostream &operator<<(ostream &out, const Point &p){
    out << fixed << setprecision(2);
    return out << "(" << p.x << ", " << p.y << ")";
}

//force constructor
Force::Force(double angle, double mag): angle{angle},mag{mag} {}
Force::Force():angle{0},mag{0}{}

//force input output operators
istream &operator>>(istream &in, Force &F){
    return in >> F.angle >> F.mag;
}
ostream &operator<<(ostream &out, const Force &F){
    out << fixed << setprecision(2);
    return out << F.angle << " degrees with magnitude of " << F.mag;
}

Force operator*(Force F, int i){
    return Force{F.angle, F.mag*i};
}
