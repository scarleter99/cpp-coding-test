#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;

void bubble_sort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 5;
    int arr[] = {3, 5, 4, 2, 1};

    bubble_sort(arr, n);

    for(int i : arr){
        cout << i;
    }

    return 0;
}