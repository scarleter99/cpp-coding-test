#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
string s;
vector<int> nums;
vector<char> opers;
ll answer;

ll carculate(int a, int b, char op)
{
    if (op == '+')
    {
        return a + b;
    }
    if (op == '-')
    {
        return a - b;
    }
    if (op == '*')
    {
        return a * b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> s;

    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            nums.push_back(s[i] - '0');
        }
        else{
            opers.push_back(s[i]);
        }
    } 

    for (int i = 0; i < opers.size(); i++)
    {
        nums[i] = carculate(nums[i], nums[i + 1], opers[i]);
        
        int temp = nums[0];
        for (int j = 0; j < opers.size(); j++)
        {
            temp = carculate(temp, nums[i + 1], opers[i]);
        }
    }

    return 0;
}