#include<iostream>
#include<map>
using namespace std; 

map<int,long> memo; 

long fib(int n) {
    if (memo.find(n) != memo.end()) {
        return memo[n]; 
    }
    if (n <= 2) return 1; 
    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];  
}


int main() {
    int n;
    cin >> n;  
    cout << fib(n) << "\n"; 
    return 0; 
}