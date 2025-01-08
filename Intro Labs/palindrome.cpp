#include <iostream>
#include <vector> //dynamically sized array
#include <queue> //First In First Out
#include <stack> //Last In First Out
using namespace std;

void palindrome(){
    int n;
    cin >> n;
    char word[n];
    for(int i=0; i<n; i++) cin >> word[i];
    bool isPalindrome = true;
    for(int i=0; i<n/2; i++){
        if(word[i]!=word[n-i-1]){
            isPalindrome = false;
            break;
        }
    }
    string output = isPalindrome? "Palindrome" : "Not a Palindrome";
    cout << output << endl;
}

void palindromeVector(){
    char c;
    vector<char> inputStr;
    while (cin >> c){
        inputStr.push_back(c);
    }
    bool isPalindrome = true;
    int n = inputStr.size();
    for(int i=0; i<n/2; i++){
        if(inputStr[i]!=inputStr[n-i-1]){
            isPalindrome = false;
            break;
        }
    }
    string output = isPalindrome? "Palindrome" : "Not a Palindrome";
    cout << output << endl;
}

int main(){
    //palindrome();
    //palindromeVector();

    return 0;
}
