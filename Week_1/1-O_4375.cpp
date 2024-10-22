#include <bits/stdc++.h>
using namespace std;

int n, num;
int ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> n){
        num = 1;
        ret = 1;

        while(true)
        {
            if (num % n == 0)
            {
                cout << ret << "\n";
                break;
            }

            num = (num * 10 + 1) % n;
            ret++;
        }
    }

    return 0;
}