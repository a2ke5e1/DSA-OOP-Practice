/*
reverse the sentence without reversing the words
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    vector<string> v;
    string temp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            v.push_back(temp);
            temp = "";
        } else {
            temp += s[i];
        }
    }
    v.push_back(temp);
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0; 
}