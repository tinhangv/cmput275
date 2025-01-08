#include <iostream>

template <typename T>
T max(T a, T b){
    return a>b? a: b;
}

struct Operation{
    int lhs, rhs;
    char op;
    //calculate is a const method, it promises not to mutate the object
    int Calculate() const{
        int val=0;
        switch(op){
            case '+': val= lhs+rhs; break;
            case '-': val= lhs-rhs; break;
            case '*': val= lhs*rhs; break;
            case '/': val= lhs/rhs;
        }
        return val;
    }

    bool operator>(const Operation &r){
        return Calculate() > r.Calculate() ?  1:  0;
    }
};

std::ostream &operator<<(std::ostream &out, const Operation &r){
    return out << "Expression(" << r.lhs << r.op << r.rhs << ")" ;
}

int main(){
    using std::cout;
    using std::endl;
    Operation op{1,5,'+'};
    Operation mult{20,7,'*'};
    cout << "1+5=" << op.Calculate() << endl;
    cout << "20*7=" << mult.Calculate() << endl;
    cout << mult << endl;

    int i=10, j=-50;
    short int x=5;
    float q=33.3, r=56.7;
    //max(i,j) is the same as max<int>(i,j), 
    //the comiler infers the type T from arguments
    std::cout << max(i,j) << std::endl;
    std::cout << max(q,r) << std::endl;

    //when arguments are not the same type we must specify
    //the type for T
    std::cout << max<int>(x,i) << std::endl;

}