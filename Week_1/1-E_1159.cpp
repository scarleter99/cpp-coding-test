#include <bits/stdc++.h>
using namespace std;

vector<int> alphaCnts(26);
vector<char> answers;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string name;
    for (int i = 0; i < N; i++)
    {
        cin >> name;

        alphaCnts[name[0] - 'a']++;
        if (alphaCnts[name[0] - 'a'] == 5)
        {
            answers.push_back(name[0]);
        }
    }

    if (answers.empty())
    {
        cout << "PREDAJA";
        return 0;
    }

    sort(answers.begin(), answers.end());

    for (char ret : answers)
    {
        cout << ret;
    }

    return 0;
}