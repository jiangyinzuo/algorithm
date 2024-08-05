/*
Any semigroup can do fast pow algorithm.

Suppose that there has a semigroup <A, *>,
x belongs to A. Now calculate the following formula
x*x*x*...*x (x^n) by fast pow algorithm.
*/

#include<iostream>
#include<string>
using namespace std;

template <typename T>
T fast_pow(T x, int n)
{
    if(n<0)
        throw string("Error in function fast_pow: index must be a non-negative integer.");
    
    T res = 1;
    while(n){
        if(n&1) res *= x;
        x *= x;
        n /= 2;
    }
    return res;
}

int main()
{
    try {
        cout << fast_pow(2, 13) << endl;
    }
    catch(string &s){
        cout << s << endl;
    }
    catch(...){
        cout << "unknown error" << endl;
    }
    return 0;
}