#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>

using namespace std;

string a[1000];
int cnt;
string s1, s2;

int main()
{
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
        for (int j = 0; j < s2.length(); j++)
        {
            cnt++;
            a[cnt] = s1.substr(0, i + 1) + s2.substr(0, j + 1);
        }
    sort(a + 1, a + cnt + 1);
    cout << a[1];
    return 0;
}
