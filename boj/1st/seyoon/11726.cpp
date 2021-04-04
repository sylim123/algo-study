#include <iostream>

using namespace std;

int n;
int dp[1002];

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void get_ans()
{
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 10007;
    }
}

int main(void)
{
    init();

    cin >> n;

    get_ans();

    cout << dp[n] << '\n';

    return 0;
}
