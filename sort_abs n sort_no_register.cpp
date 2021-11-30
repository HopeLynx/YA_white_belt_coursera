#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool my_comparison(int a, int b){
    return (abs(a) < abs(b)) ? true : false;
}

bool my_comp(string a, string b){
    string tmp_a = a;
    string tmp_b = b;
    transform(tmp_a.begin(), tmp_a.end(), tmp_a.begin(), ::tolower);
    transform(tmp_b.begin(), tmp_b.end(), tmp_b.begin(), ::tolower);

    return (tmp_a < tmp_b) ? true : false;
}

int main(){
    vector<string> vec;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        string tmp; cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end(),my_comp);
    for (auto i : vec){
        cout << i << " ";
    }
    return 0;
}
