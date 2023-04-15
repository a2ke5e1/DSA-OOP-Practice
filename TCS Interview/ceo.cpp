/*
Tim is CEO of company 'C'. He has decided to reward employees of his company as they work
really hard. So he has decided to spend employees for a trip to Goa. But he doesn't 
want to reward all his employees as some of them didn't really work hard. So, to make
a group which is to be sent to Ga, he opened his company employee database. 

Here he will make a group based on two factors -
A seniority factor 'S' and a performance factor 'F'.
So, he decided that the group he will choose should follow the following conditions -


*The difference betwween the sniority factor of any employee 
with any other employee should be less than 'd' units, as he wants to
send groups of similar age groups and seniority.

*Secondly, he also wants that the group being sent should have a
maximum performance factor. i.e., the sum of performance factors
of the members of the group should be maximum.

so that he can sent only high performing employees of a particular
age group.

The first line of input contains two space-separated integers 'n' and 'd' 
where 'n' is the total number of employees in the company. The next line 
comtains 'n' employees with their seniority factor 'S' and performance
factor 'F'. Your task is to help Time find out the maximum performance
factor that Tim can attain in that group.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    int n, d; 
    cin >> n >> d;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int s, f; 
        cin >> s >> f;
        v.push_back(make_pair(s, f));
    }

    sort(v.begin(), v.end());
    int i = 0, j = 0, sum = 0, ans = 0;
    while (j < n) {
        if (v[j].first - v[i].first < d) {
            sum += v[j].second;
            j++;
        } else {
            sum -= v[i].second;
            i++;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}