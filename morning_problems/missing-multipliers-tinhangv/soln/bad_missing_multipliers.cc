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


//O(n*m)
int main(){
	int n, m;
	cin >> n >> m;
	
	long long *prods = new long long[n];
    short int *arr = new short int[n];
    long long noZeroProd =1;
    int zeroCount =0;
	bool *empty = new bool[n];

	for(int i=0; i<n; ++i){
        //read in value
        cin >> arr[i];
        //multiply value to total if non zero
        if(arr[i] !=0) noZeroProd *= arr[i];
        else ++zeroCount;
        //empty 
        if(i-m<=0 && i+m >= n-1) empty[i]=1;
	}

    for(int i=0; i<n; ++i){
        if(empty[i]){
            prods[i] =0;
        }else{
            int zeros =0;
            prods[i] = noZeroProd;
            for(int j=i-m; j<=i+m; j++){
                if(j<0) continue;
                if(j>n-1) break;
                if(arr[j]==0) ++zeros;
                else prods[i] /= arr[j];
            }
            if(zeros < zeroCount) prods[i] =0;
        }
        cout << prods[i];
		if(i != n-1) cout << " ";
    }
	cout << endl;

	delete[] prods;
    delete[] arr;
	delete[] empty;
	return 0;
}

//not working
int main(){
	size_t n, m;
	cin >> n >> m;
	
	long long *prod = new long long[n];
    int *zeroIndices = new int[n];
    size_t zeros =0;
    long long curProd =1;
    bool *empty = new bool[n];
    long long *ret = new long long [n];

	for(size_t i=0; i<n; ++i){
        short int temp;
        cin >> temp;
        if(temp==0){
            zeroIndices[zeros] = i;
            ++zeros;
        }else{
            curProd *= temp;
        }
        prod[i] = curProd;

        //empty product
        if(i-m<=0 && i+m >= n-1)empty[i]=1;
	}
    
    for(size_t i=0; i<n; ++i){
        if(empty[i]){
            ret[i] =0;
            continue;
        }
        bool found =0;
        for(size_t j=0; j<zeros; ++j){
            if(zeroIndices[j]<i-m || zeroIndices[j]>i+m){
                ret[i] =0;
                found =1;
                break;
            }
        }
        if(found) continue;
        if(i-m<=0){
            ret[i] = prod[n-1]/prod[i+m];
            continue;
        }else{
            if(i+m<=n-1){
                ret[i] = prod[n-1] / prod[i+m] * prod[i-m-1];
                continue;
            }else{
                ret[i] = prod[i-m-1];
            }
        }
    }

    for(size_t i=0; i<n; ++i){
        cout << ret[i];
        if(i!=n-1) cout << " ";
    }
	cout << endl;

    delete[] ret;
	delete[] prod;
    delete[] zeroIndices;
    delete[] empty;
	return 0;
}

//without zero checking
#include <iostream>
using namespace std;

int main(){
	size_t n, m;
	cin >> n >> m;
	
	long long *prod = new long long[n];
    long long curProd =1;
    bool *empty = new bool[n];
    long long *ret = new long long [n];

	for(size_t i=0; i<n; ++i){
        short int temp;
        cin >> temp;
        curProd *= temp;
        prod[i] = curProd;

        //empty product
        if(i-m<=0 && i+m >= n-1)empty[i]=1;
	}
    
    for(size_t i=0; i<n; ++i){
        if(empty[i]){
            ret[i] =0;
            continue;
        }
        if(i-m<=0){
            ret[i] = prod[n-1]/prod[i+m];
            continue;
        }else{
            if(i+m<=n-1){
                ret[i] = prod[n-1] / prod[i+m] * prod[i-m-1];
                continue;
            }else{
                ret[i] = prod[i-m-1];
            }
        }
    }

    for(size_t i=0; i<n; ++i){
        cout << ret[i];
        if(i!=n-1) cout << " ";
    }
	cout << endl;

    delete[] ret;
	delete[] prod;
    delete[] empty;
	return 0;
}