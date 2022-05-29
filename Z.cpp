#include<bits/stdc++.h>
using namespace std;
// str = "abababab"
// Z[] = {x, 0, 6, 0, 4, 0, 2, 0}


vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
    vector<int>v = z_function("aaaacbaa");
	return 0;
}
