#include <bits/stdc++.h>
using namespace std;

int n, num;
int answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    while(scanf("%d", &n) != EOF){
        num = 1;
        answer = 1;

        while(true)
        {
            if (num % n == 0)
            {
                cout << answer << "\n";
                break;
            }

            num = (num * 10 + 1) % n;
            answer++;
        }
    }

    return 0;
}