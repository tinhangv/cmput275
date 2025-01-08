#include <iostream>
using namespace std;


void fibonacci(int n){
    int x=0, y=1, temp;
    for(int i=0; i<n; i++){
        cout << x << endl;
        temp = y;
        y += x;
        x = temp;
    }
}

int powers(int a, int b){
    int x =a;
    for(int i=0; i<b; i++) x*=a;
    return x;
}

int main(){
    //fibonacci(5);
    cout << powers(2,5) << endl;
    return 0;
}
