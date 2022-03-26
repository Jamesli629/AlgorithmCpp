#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> ht;
string s;
int main(){
    getline(cin, s);
    stringstream ss(s);
    string s1;
    string t;
    while (ss >> s1){
        if (isdigit(s1[0]))
            ht[t] += stoi(s1);
        else t = s1;
    }
    int k;
    scanf("%d", &k);
    while (k--){
        string s2;
        cin >> s2;
        printf("%d\n", ht[s2]);
    }
}
