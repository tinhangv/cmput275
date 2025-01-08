# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
using namespace std ;
int main () {
vector < string > myVec = { " cab " , " bac " , " cba " , " acb " , " abc " };
sort ( myVec . begin () , myVec . end () ) ;
for ( auto s : myVec ) cout << s << endl ;
}