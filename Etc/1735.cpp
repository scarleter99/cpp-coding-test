#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = numeric_limits<int>::max();

int a1, b1, a2, b2;

int gcd(int a, int b){
    if (b == 0){
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a1 >> b1 >> a2 >> b2;

    int b3 = b1 * b2 / gcd(b1, b2);
    int a3 = a1 * (b3 / b1) + a2 * (b3 / b2);

    int temp = gcd(a3, b3);

    cout << a3 / temp << " " << b3 / temp;

    return 0;
}