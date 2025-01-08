#include <iostream>
#include <stack> //Last In First Out
#include <string>
using namespace std;

void check(){
    int L;
    cin >> L;
    string inputString;
    cin.ignore();
    getline(cin,inputString);
    //cout << inputString << endl;
    stack<char> hist;
    for(int i=0; i<L; i++){
        char c = inputString[i];
        switch(c){
            case '(':
                hist.push(')');
                break;
            case '[':
                hist.push(']');
                break;
            case '{':
                hist.push('}');
                break;
        }
        if(c==')' || c==']' || c=='}'){
            if(!hist.empty() && c == hist.top()){
                hist.pop();
            }
            else{
                cout << c << ' ' << i << endl;
                return;
            }
        }  
    }
    cout << "ok so far" << endl;
    return;
}
int main(){
    check();
    return 0;
}


