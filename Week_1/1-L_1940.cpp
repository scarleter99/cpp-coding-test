#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> ings;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> N >> M;

    ings = vector<int>(N);

    for(int i = 0; i < N; i++)
    {
        cin >> ings[i];

        for (int j = 0; j < i; j++)
        {
            if (ings[j] == -1)
            {
                continue;
            }
            
            if (ings[i] + ings[j] == M)
            {
                answer++;
                ings[i] = -1;
                ings[j] = -1;
                break;
            }
        }
    }

    cout << answer;

    return 0;
}