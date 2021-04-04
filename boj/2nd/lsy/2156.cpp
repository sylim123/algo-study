#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[10002][2];
int arr[10002];

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=1; i<=N; i++)
    {
        cin >> arr[i];
    }
}

void get_result()
{
    dp[1][0] = 0;
    dp[1][1] = arr[1];
    dp[2][0] = max(dp[2 - 1][0], dp[2 - 1][1]);
    dp[2][1] = max(dp[2 - 1][0], dp[2 - 1][1]) + arr[2];
    
    for(int i=3; i<=N; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 2][0] + arr[i - 1]) + arr[i];
    }

    cout << max(dp[N][0], dp[N][1]) << '\n';
}

int main(void)
{
    init();

    get_result();

    return 0;
}
