#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;
//#define debug

void print(string &grid, int rows, int columns){
    for(int i=0;i<columns;++i) cout << '|';
    cout << endl;
    for(int row=0; row<rows; ++row){
        for(int col=0;col<columns;++col){
            cout << grid[columns*row+col];
        }
        cout << endl;
    }
    for(int i=0;i<columns;++i) cout << '|';
    cout << endl;
}

void step(string &grid, int rows, int columns){
    string tempGrid = "";
    for(int row=0; row<rows; ++row){
        for(int col=0;col<columns;++col){
            #ifdef debug 
            cout << "row:" << row << " col:" << col << endl; //debug
            #endif
            int neighbors =0;
            int checks[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
            //do checks
            #ifdef debug 
            cout << '['; //debug 
            #endif
            for(int t=0; t<8; ++t){
                int i=row+checks[t][0];
                int j=col+checks[t][1];
                #ifdef debug 
                cout << '{'; //debug
                #endif
                if(i>=0 && i<rows && j>=0 && j<columns){
                    char neighbor = grid[columns*i+j];
                    if(neighbor == 'O') ++neighbors;
                    #ifdef debug 
                    cout << (neighbor == 'O') ; //debug
                    #endif
                }
                #ifdef debug 
                cout << '}'; //debug
                #endif
            }    
            if(neighbors==3 || (grid[columns*row+col] == 'O' && neighbors == 2)) tempGrid += 'O';
            else tempGrid += '.';
            #ifdef debug 
            cout << ']' ; //debug
            cout << " n=" << neighbors << endl; //debug
            #endif
        }
        #ifdef debug 
        cout << endl; //debug
        #endif
    }
    grid = tempGrid;
}

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
    while(cin>>command){
        if(command == 's'){
            step(grid,rows,columns);
        }else if(command == 'p'){
            print(grid,rows,columns);
        }
    }
}