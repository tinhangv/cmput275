#include <iostream>
using namespace std;

//average
// int main(){
//     int x,y,z;
//     cin >> x;
//     cin >> y;
//     cin >> z;
//     cout << double(x+y+z)/3 << endl;
// }

//second to last digit
int main(){
    int x;
    cin >> x;
    x=abs(x%100);
    cout << (x-x%10)/10 << endl;
}

// int main(){
//     unsigned short int x = 65535;
//     x += 1;
//     cout << x << endl;
// }

// int main () {
//     unsigned long i = 0;
//     while ( true ) {
//         if ( i == 0xFAD9CEA62ul ) {
//             break ;
//         }
//         i ++;
//     }
//     cout << i << " is equal to 0 xFAD9CEA62 " << endl ;
//     return 0;
// }

// int main () {
// cout << 3/2 << endl ;
// cout << 3.0/2 << endl ;
// cout << double (3) /2 << endl ;
// }

// int main () {
// char my_char = 'a';
// cout << my_char + 2 << endl ;
// }