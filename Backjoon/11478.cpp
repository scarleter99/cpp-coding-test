#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = numeric_limits<int>::max();

string str;
set<string> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        string temp = "";
        for (int j = i; j < str.size(); j++) {
            temp += str[j];
            s.insert(temp);
        }
    }

    cout << s.size() << "\n";

    return 0;
}