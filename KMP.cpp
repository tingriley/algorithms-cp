#include<bits/stdc++.h>
using namespace std;
//https://yeefun.github.io/kmp-algorithm-for-beginners/
/*
a a b a a b c c a 
0 1 0 1 2 3 0 0 1 
*/ 
vector<int> prefix_function(string s){
    int n = (int)s.length();
    vector<int>p(n, 0);
    for(int i = 1; i < n; i++){
        int j = p[i-1];
       
        while(j > 0 && s[i]!=s[j]){
            j = p[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        p[i] = j;


    }
    return p;
}

int findPattern(string str, string pattern) {
    vector<int> lps = prefix_function(pattern);
  
    int i = 0, j = 0;
    while (i < str.length()) {
      if (str[i] == pattern[j]) {
          i++;
          j++;
      } else {
          if (j == 0) {
              i++;
          } else {
              j = lps[j - 1];
          }
      }
      if (j == pattern.length()) return i - pattern.length();
    }
    return -1;
}
int main(){
    string s1 = "aabaabcca";
    vector<int> p = prefix_function(s1);
    for(char c: s1){
        cout << c << " ";
    }
    cout << endl;
    for(int v: p){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}