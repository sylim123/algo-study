#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void perm(int depth, int limit, int n)
{
    if(depth == limit)
    {
        for(int i=0; i<limit; i++) cout << v[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i=1; i<=N; i++)
    {
        v.push_back(i);
        perm(depth + 1, limit, i);
        v.pop_back();
    }
}

int main(void)
{
    init();

    cin >> N >> M;

    perm(0, M, 0);

    return 0;
}
