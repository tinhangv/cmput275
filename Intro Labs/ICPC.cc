#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_set<string> set;
    string output[12];
    int count = 0;
    for(int i=0;i<n;i++){
        string university, team;
        cin >> university;
        cin >> team;
        
        if(set.find(university) != set.end())
            continue;
        else if(count<12){
            set.insert(university);
            output[count] = university + ' ' + team;
            count ++;
        }
    }

    for(int i=0; i<12; i++)
        cout << output[i] << endl;
    return 0;
}