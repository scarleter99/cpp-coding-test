#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n;
ll temp = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--)
    {
        cin >> n;

        int num2 = 0, num5 = 0;

        for(int j = 2; j <= n; j *= 2)
        {
            num2 += n / j;  
        }

		for(int j = 5; j <= n; j *= 5)
        {
			num5 += n / j; 
		}

		cout << min(num2, num5) << "\n";
    }

    return 0;
}