#include <iostream>
using namespace std;

//O(n^2)
int main(){
	int n, m;
	cin >> n >> m;
	
	long long *prods = new long long[n];
	
	bool *empty = new bool[n];
	for(int i=0; i<n; ++i){
		prods[i] = 1;
		empty[i] =1;
	} 

	for(int i=0;i<n;++i){
		int x;
		cin >> x;
		for(int j=0;j<n;++j){
			if(j<i-m || j>i+m){
				prods[j]*=x;
				empty[j] = 0;
			}
		}
	}

	for(int i=0; i<n; ++i){
		cout << (empty[i] ? 0 : prods[i]);
		if(i != n-1) cout << " ";
	}
	cout << endl;

	delete[] prods;
	delete[] empty;
	return 0;
}