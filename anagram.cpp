#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

void print_Y_N(bool x){
    if (x) cout << "YES";
    else cout << "NO";
    cout << endl;
}

map<char,int> split_str(string s){
    map<char,int> m;
    for (auto c:s){
        m[c]+=1;
    }
    return m;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s1,s2; cin >> s1 >> s2;
        print_Y_N(split_str(s1) == split_str(s2));
    }
    return 0;
}
