#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main(){
    //read in grid

    string grid, line;
    //read one line to get width
    cin >> line;
    int columns = line.size();
    grid += line;
    int rows = 1;
    while(true){
        cin >> line;
        if(line == "x") break;
        ++ rows;
        grid += line;
    }
    // cout << grid << endl;
    // cout << columns << endl;
    // cout << rows << endl;

    //read commands
    //s: progress grid by one time step
    //p: print grid
    char command;
    string tempGrid="";
    while(cin>>command){
        if(command == 's'){
            tempGrid = "";
            for(size_t row=0; row<rows; ++row) 
            for(size_t col=0;col<columns;++col){
                int neighbors =0;
                int checks[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
                //do checks
                for(size_t t=0; t<8; ++t){
                    int i=row+checks[t][0];
                    int j=col+checks[t][1];
                    if(i>=0 && i<rows && j>=0 && j<columns){
                        char neighbor = grid[columns*i+j];
                        if(neighbor == '0') ++neighbors;
                    }
                }
                
                if(neighbors==3) tempGrid += '0';
                else tempGrid += '.';
            }
            grid = tempGrid;
        }else if(command == 'p'){
            for(size_t i=0;i<columns;++i) cout << '|';
            cout << endl;
            for(size_t row=0; row<rows; ++row){
                for(size_t col=0;col<columns;++col){
                    cout << grid[columns*row+col];
                }
                cout << endl;
            }
            for(size_t i=0;i<columns;++i) cout << '|';
            cout << endl;
        }
    }
  
}