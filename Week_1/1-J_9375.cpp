#include <bits/stdc++.h>
using namespace std;

int tc, n;
string cloth, clothKind;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> tc;

    while(tc--)
    {
        map<string, int> clothKindMap;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> cloth >> clothKind;
            clothKindMap[clothKind]++;
        }
        
        answer = 1;
        for (auto temp : clothKindMap)
        {
            answer *= ((int)temp.second + 1);
        }

        answer--;

        cout << answer << "\n";
    }

    return 0;
}