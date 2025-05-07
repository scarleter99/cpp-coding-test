#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = numeric_limits<int>::max();

int a1, b1, a2, b2;

int makeGcd(int a, int b){
    if (b == 0){
        return a;
    }

    return makeGcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a1 >> b1 >> a2 >> b2;

    int b3 = b1 * b2 / makeGcd(b1, b2);
    int a3 = a1 * (b3 / b1) + a2 * (b3 / b2);

    int gcd = makeGcd(a3, b3);

    cout << a3 / gcd << " " << b3 / gcd;

    return 0;
}