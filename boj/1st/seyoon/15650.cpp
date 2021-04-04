#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool visited[9];
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

    for(int i=n+1; i<=N; i++)
    {
        if(visited[i]) continue;

        visited[i] = true;
        v.push_back(i);
        perm(depth + 1, limit, i);
        v.pop_back();
        visited[i] = false;
    }
}

int main(void)
{
    init();

    cin >> N >> M;

    perm(0, M, 0);

    return 0;
}
