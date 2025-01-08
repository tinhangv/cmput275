#include <iostream>
using namespace std;

template <typename T>
struct Vec2D{
    T x,y;
    Vec2D operator*(int c){
        return Vec2D{x*c, y*C};
    }
};

ostream &operator<<(ostream &out, const Vec2D &v) {
  return out << "[" << v.x << ", " << v.y << "]";
}

int main(){
    Vec2D<int> a{1,2};
    Vec2D<float> z{2.5,3.5};
    Vec2D<float> scaled = z*7;
    cout << scaled.x << ", " << scaled.y << endl;
    Vec2D<Vec2D<int>> doubleVec{Vec2D<int>{1,2}, Vec2D<int>{3,4}};
    doubleVec = doubleVec*5;
    cout << doubleVec << endl;
}