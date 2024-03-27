#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "intSet.h"

using namespace std;
//#define debug

#ifdef debug
//#include <utility> //*REMOVE AFTER
#endif

//default constructor
intSet::intSet():
    data{new int[4]}, size{0}, capacity{4}{
        #ifdef debug
        cout << "[default constructor called]" << endl;
        cout << "size: "<< size << ", cap: " << capacity << endl;
        #endif
    }

//destructor
intSet::~intSet(){
    delete[] data; 
    #ifdef debug
    cout << "[destructor called]" << endl;
    #endif
}

//copy constructor
intSet::intSet(const intSet &other): 
    data{new int[other.capacity]}, size{other.size}, capacity{other.capacity}{
        for(size_t i=0;i<other.size;++i){
            data[i] = other.data[i];
        }

        #ifdef debug
        cout << "[copy constructor called]" << endl;
        #endif
    }

//copy assignment operator
intSet &intSet::operator=(const intSet &other){ 
    #ifdef debug
    cout << "[copy assignment operator called]" << endl;
    #endif

    if(this==&other) return *this;

    int *oldData = data;
    data = new int[other.capacity];
    for(size_t i=0;i<other.size;++i){
        data[i] = other.data[i];
    }
    delete[] oldData;
    
    size = other.size;
    capacity = other.capacity;
    return *this;
}

//move constructor
intSet::intSet(intSet &&other): 
    data{other.data},size{other.size},capacity{other.capacity}{
        #ifdef debug
        cout << "[move constructor called]" << endl;
        #endif

        other.data = nullptr;
        other.size=0; 
    }

//Move Assignment operator
intSet &intSet::operator=(intSet &&other){
    #ifdef debug
        cout << "[move assignment operator called]" << endl;
    #endif

    if(this!=&other){
        delete[] data;
        data = other.data;
        size = other.size;
        capacity = other.capacity;
        other.data =nullptr;
        other.size =0;
    }
    return *this;
}

//set union
intSet intSet::operator|(const intSet &other) const{
    #ifdef debug
    cout<< "[set union called]" << endl;
    #endif

    intSet ret;
    size_t i=0; 
    size_t j=0;
    while(i<size && j<other.size){
        if(data[i]==other.data[j]){
            ret.add(data[i]);
            ++i; ++j;
        }else if(data[i]<other.data[j]){
            ret.add(data[i]);
            ++i;
        }else if(data[i]>other.data[j]){
            ret.add(other.data[j]);
            ++j;
        }
    }
    while(i<size){
        ret.add(data[i]);
        ++i;
    }
    while(j<other.size){
        ret.add(other.data[j]);
        ++j;
    }
    return ret;
}

//set intersection
intSet intSet::operator&(const intSet &other) const{
    #ifdef debug
    cout << "[set intersection called]" << endl;
    #endif

    intSet ret;
    size_t start=0;
    for(size_t i=0; i<size; ++i){
        for(size_t j=start; j<other.size; ++j){
            if(data[i]==other.data[j]){
                start =j;
                ret.add(data[i]);
            }
        }
    }
    return ret;
}

//set equality
bool intSet::operator==(const intSet &other)const{
    #ifdef debug 
    cout << "[set equality called]" << endl;
    #endif

    if(size != other.size)return 0;
    for(size_t i=0; i<size; ++i){
        if(data[i]!=other.data[i]) return 0;
    }
    return 1;
}

//subset
bool intSet::isSubset(const intSet &other) const{
    #ifdef debug
    cout << "[isSubset called]" << endl;
    #endif

    if(size < other.size) return 0;
    size_t start =0;
    for(size_t j=0; j<other.size; ++j){
        bool found = 0;
        for(size_t i=start; i<size; ++i){
            if(data[i]==other.data[j]){
                found = 1;
                start = i;
                break;
            }
        }
        if(!found) return 0;
    }
    return 1;
}  

//contains element
bool intSet::contains(int e) const{
    #ifdef debug
    cout << "[contains called]" << endl;
    #endif

    for(size_t i=0; i<size; ++i){
        if(data[i]==e) return 1;
    }
    return 0;
}

//add element
void intSet::add(int e){
    #ifdef debug 
        cout << "[adding value: "<< e << "]" << endl;
    #endif
    
    //double array capacity if max reached
    if(size == capacity){
        #ifdef debug 
            cout << "array capacity doubled" << endl;
        #endif
        
        int *newData = new int[capacity*2];
        for(size_t i=0; i<size; ++i) newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = capacity*2;
    }
    //insert value to correct place
    #ifdef debug
    cout << "inserting value" << endl;
    #endif
    if(size>0)if(e>data[size-1]){
        data[size++] = e;
        return;
    }
    for(size_t i=0; i<size; ++i){
        if(data[i] == e) return;
        if(data[i]>e){
            //shift all elements right of arr[i]
            for(size_t j=size; j>i; --j) data[j] = data[j-1];
            data[i]=e;
            ++size;
            return;
        }
    }
    data[size++] = e;
}

//remove element
void intSet::remove(int e){
    #ifdef debug
    cout << "[removing value: " << e << "]\n";
    #endif
    for(size_t i=0; i<size; ++i) if(data[i]==e){
        for(size_t j=i; j<size-1; ++j) data[j] = data[j+1];
        --size;
        return;
    }
}

//print set
ostream &operator<<(ostream &out, const intSet &is){
    #ifdef debug
    out << "[print set called]\n";
    #endif
    out << "(";
    for(size_t i=0; i<is.size; ++i) {
        out << is.data[i];
        if(i!=is.size-1) out << ", ";
    }
    return out << ")";
}
#ifdef debug
int main(){
    // intSet *test = new intSet;
    // test -> add(1);
    // delete test;
    
    intSet obj1;
    obj1.add(-3);
    obj1.add(4);
    obj1.add(-1);
    obj1.add(2);
    obj1.add(5);
    cout << "obj1: " << obj1 << endl;

    intSet obj2;
    obj2.add(-3);
    obj2.add(4);
    obj2.add(-1);
    cout << "obj2: " << obj2 << endl;

    //intSet obj3 = obj1 & obj2;
    //cout << "obj3: " << obj3 << endl;

    cout << obj1.isSubset(obj2) << endl;
}
#endif