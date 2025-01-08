#include <iostream>

using namespace std;

int main() {
  size_t S,A;
  cin >> S >> A;

  long long *nums = new long long[A];
  
  //read all the addresses
  for(size_t i=0; i<A; ++i){
    cin >> nums[i];
  }

  size_t i=0; //counter 
  size_t j=0; //start at beginning
  while(true){
    ++i;
  
    //if current addr leads to value, print value
    if(nums[j]<0){
      cout << nums[j] << endl;
      return 0;
    }
  
    if(i>A){
      cout << "There was a cycle" << endl;
      return 0;
    }

    j = nums[j]-S;
  }

  delete[] nums;

  return 0;
}
