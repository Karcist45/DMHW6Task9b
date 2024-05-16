#include <bits/stdc++.h>
//#include "blazingio.hpp"

using namespace std;

string s = "CGUAAUUACGGCAUUAGCAU";
int func(map<pair<int, int>, int>& g, int l, int r){
    if(l >= r){
        return 1;
    }
    if(g.count({l, r})){
        return g[{l, r}];
    }
    int res = 0;
    for(int i = l + 1; i < r + 1; i += 2){
        if((s[l] == 'A' && s[i] == 'U') || (s[l] == 'U' && s[i] == 'A') || (s[l] == 'C' && s[i] == 'G') || (s[l] == 'G' && s[i] == 'C')){
            res += func(g, l + 1, i - 1) * func(g, i + 1, r);
        }
    }
    g[{l, r}] = res;
    return res;
}
int main() {
    map<pair<int, int>, int> g;
    int res = func(g, 0, 19);
    cout << res;
    return 0;
}
