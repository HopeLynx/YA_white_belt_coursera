#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void req_dec_to_bin(int n){
  if (n >= 2)
    req_dec_to_bin(n / 2);
  cout << (n % 2);
}

int Factorial(int n){
    if (n < 2) return 1;
    return n * Factorial(n-1);
}

bool IsPalindrom(string s){
    string tmp = s; reverse(tmp.begin(),tmp.end());
    return tmp == s;
}

vector<string> PalindromFilter(vector<string> words,int minLength){
    auto r = remove_if(words.begin(),words.end(),[&minLength](string s){return !IsPalindrom(s) || s.length()<minLength;});
    words.erase(r,words.end());
    return words;
}

void UpdateIfGreater(int first,int& second){
    if (first > (second)) (second) = first;
}

void MoveStrings(vector<string>& src,vector<string>& dest){
    dest.insert(dest.end(),src.begin(),src.end());
    src.clear();
}

void Reverse(vector<int>& v){
    reverse(v.begin(),v.end());
}

vector<int> Reversed(const vector<int>& v){
    vector<int> ans;
    ans.insert(ans.end(),v.rbegin(),v.rend());
    return ans;
}


int main(){
    //string a;
    //cin >> a;
//    vector<string> m;
//    m.insert(m.end(),"aba");
//    m.insert(m.end(),"abacaba");
//    vector<string> v =PalindromFilter(m,5);
//    for (auto it:v){cout << it << endl;}
//    int x=5,y=3;
//    cout << x <<" " << y<<endl;
//    UpdateIfGreater(x,y);
//    cout << x <<" " << y<<endl;

    int n;int tmp;vector<int> v;int sum=0;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> tmp;
        sum+=tmp;
        v.push_back(tmp);
    }
    sum /= n;
    vector<int> ans;
    for (int i=0;i<n;i++){
        if (v[i] > sum) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto it : ans) cout << it << " ";


    return 0;
}
