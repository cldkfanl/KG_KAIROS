#include<iostream>
#include<vector>

using namespace std;





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    int left = 0;
    int right = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
        right += tmp;
    }
    for (int i = 0; i < N; i++) {
        left = max(left, arr[i]);
    }
    while (left <= right) {
        int mid = (left + right) / 2;
        int sum = 0, cnt = 0;
        for (int i = 0; i < N; i++) {
            if (sum + arr[i] > mid) {
                sum = 0;
                cnt++;
            }
            sum += arr[i];
        }
        if (sum != 0) {
            cnt++;
        }

        if (cnt > M) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << left;

    return 0;
}