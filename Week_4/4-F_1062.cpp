#include <bits/stdc++.h>
using namespace std;

int n, k;
int words[54];
int ret;

int count(int mask){
    int cnt = 0;
    for (int word : words){
        if (word && (word & mask) == word){
            cnt++;
        }
    }

    return cnt;
}

int algo(int index, int k, int mask){
    if (k <= 0 || index == 26){
        return count(mask);
    }

    int temp = algo(index + 1, k - 1, mask | (1 << index));

    if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' 
        && index != 'i' - 'a' && index != 'c' - 'a'){
        int temp2 = algo(index + 1, k, mask);
        temp = max(temp, temp2);
    }

    return temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        for (char c : temp){
            words[i] |= 1 << c - 'a';
        }
    }

    ret = algo(0, k, 0);

    cout << ret;

    return 0;
}