#include <bits/stdc++.h>
using namespace std;

int x, now, cnt, stick = 64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x;

    if (x == stick){
        cnt = 1;
    }
    else{
        while(now != x){
            stick /= 2;
            if(now + stick <= x){
                now += stick;
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}