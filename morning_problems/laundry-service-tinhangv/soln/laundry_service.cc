#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    //n loads, m machines, k mins to dry
    int n,m,k;
    cin >> n >> m >> k;
    
    //time for ith washer to complete a load
    int *times = new int[m];
    
    for(int i=0; i<m; ++i){
        cin >> times[i];
    }

    //array tracking when next load is done for each machine
    int *next = new int[m];
    for(int i=0;i<m; ++i){
        next[i] = times[i]+k;
    }

    int done = 0;
    int time =0;
    while (done < n) {
        //find minimum time to finish one more load
        int* min_el = min_element(next, next+m);
        int min_ind = min_el - next;
        time = *min_el;
        //increment finish time for that machine
        next[min_ind] += times[min_ind];
        ++ done;
    }

    cout << time << endl;

    delete[] next;
    delete[] times;
    return 0;
}
