/*
During the weekly market, the fruit vendors(n) have lined up their 
stalls in a straight line. The cost of fruits(a[]) with each vendor
is different. If you are going to market, you can buy fruits only 
with following conditions:

Once you buy fruits from a vendor, you can't buy fruits from their 
adjacent vendors. i.e. a[i+1] and a[i-1]. You can skip in between i.e.
buy from 1st and 5th vendor by skipping 2nd, 3rd and 4th vendor.

The task is to find the maximum amount that can be spent on buying
fruits from the market.
*/

#include <iostream>
#include<algorithm>

using namespace std;

int solve(int x[], int i, int n) {
    if (i >= n) {
        return 0;
    }
    int a = x[i] + solve(x, i+2, n);
    int b = solve(x, i+1, n);
    return max(a, b);
}
 


int main()
{
    int n; 
    cin >> n;
    int x[n]; 
    int i; 
    for (i = 0; i < n ; i++) {
        cin >> x[i]; 
    }
    int total = solve(x, 0, n); 
    cout << total << endl;
    return 0;
}


