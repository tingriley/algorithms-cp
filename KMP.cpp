#include<bits/stdc++.h>
using namespace std;

vector<int> build(string &t){
    vector<int>next(t.size());
    next[0] = -1;

    for(int i = 1, j = -1; i < t.size(); i++){
        while(j >= 0 && t[i] != t[j+1])
            j = next[j];

        if(t[i] == t[j+1])
            j++;

        next[i] = j;
    }
    return next;
}

bool match(string &s, string &t, vector<int> &next) {
    for (int i = 0, j = -1 ; i < s.size() ; i++) {
        while (j >= 0 && s[i] != t[j + 1])
            j = next[j];
 
        if (s[i] == t[j + 1])
            j++;
         
        if (j + 1 == (int)t.size())
            return true;
    }
    return false;
}

int main()
{
    string s = "aabaaaabab";
    string t = "aabab";
    vector<int>next = build(t);
    cout << match(s, t, next) << "\n";
    return 0;
}
