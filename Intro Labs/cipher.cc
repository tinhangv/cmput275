#include <iostream>
#include <string>
using namespace std;

int main(){
    string input, output;
    cin >> input;
    for(int i=0; i<input.size(); i++){
        char c = (input[i]-96+3)%26 +96;
        output += c;
    }
    cout << output << endl;
    return 0;
}