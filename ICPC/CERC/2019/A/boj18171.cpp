// CERC 2019 A
// manacher algorithm
#include <bits/stdc++.h>
using namespace std;

// 매내처 알고리즘을 적용할 수 있도록, 문자열의 처음과 끝, 사이사이에 개행문자 추가

string transform(const string &s) {  
    string ret = "$";  
    for (int i = 0; i < s.length(); i++, ret += '$') ret += s[i];  
    return ret;  
}  
vector<int> manacher(const string &s) {  
    int n = s.length(), p = 0;  
    vector<int> ret(n);  
  
    for (int i = 1; i < n; i++) {  
        int r = p + ret[p];  
        if (r >= i) ret[i] = min(r - i, ret[2 * p - i]);  
        while (i - ret[i] - 1 >= 0 && s[i - ret[i] - 1] == s[i + ret[i] + 1])  
            ret[i]++;  
        if (i + ret[i] >= r) p = i;  
    }  
   return ret;  
}  
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;  
    string s; cin >> s;  
    int ans = s.length();   
    vector<int> ret = manacher(s);  
    for (int i = 0; i < s.length(); i++) {  
        if (i + ret[i] == s.length() - 1) {  
            ans = min(ans, (int)s.length() - (ret[i] * 2 + 1));  
        }  
    }    
    vector<int> ret_ = manacher(transform(s));  
    for (int i = 0; i < ret_.size(); i += 2) {  
        if (i + ret_[i] == ret_.size() - 1) {  
            ans = min(ans, (int)s.length() - (ret_[i] * 2 + 1) / 2);  
        }  
    }   
    cout << ans;
    return 0;
}
