#include<iostream>
#include<map>
using namespace std; 

map<string,long> memo; 

long grid_solver(int m, int n) {
    string key = to_string(m) + "," + to_string(n); 
    if (memo.find(key) != memo.end()) {
        return memo[key]; 
    }
    if (m == 1 && n == 1) return 1; 
    if ( m == 0 || n == 0) return 0; 
    memo[key] = grid_solver(m - 1, n) + grid_solver(m, n - 1); 
    return memo[key];   
}


int main() {
    int m, n;
    cin >> m >> n;  
    cout << grid_solver(m, n) << "\n"; 
    return 0; 
}