#include <bits/stdc++.h>
using namespace std;

int t, n;
string cloth, clothKind;
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--)
    {
        map<string, int> clothKindMap;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> cloth >> clothKind;
            clothKindMap[clothKind]++;
        }
        
        ret = 1;
        for (auto temp : clothKindMap)
        {
            ret *= ((int)temp.second + 1);
        }

        ret--;

        cout << ret << "\n";
    }

    return 0;
}