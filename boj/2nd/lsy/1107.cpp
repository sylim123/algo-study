#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

const int dest = 100;
int N, M, result = INT_MAX;
vector<int> valid_num;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    bool invalid[11] = {false,};
    for(int i=0; i<M; i++)
    {
        int temp;
        cin >> temp;
        invalid[temp] = true;
    }
    for(int i=0; i<10; i++)
    {
        if(!invalid[i]) valid_num.push_back(i);
    }
}

int get_gab(int a, int b)
{
    return abs(a - b);
}

int get_num_from_vec(vector<int> &v)
{
    int ret = 0;
    for(int i=0; i<v.size(); i++)
    {
        ret += v[i] * pow(10, i);
    }
    return ret;
}

void dfs(int depth, int limit, vector<int> &v)
{
    if(depth == limit)
    {   
        int num = get_num_from_vec(v);
        int gab = get_gab(num, N);
        result = min(result, gab + limit);
        return;
    }

    for(int i=0; i<valid_num.size(); i++)
    {
        v.push_back(valid_num[i]);
        dfs(depth + 1, limit, v);
        v.pop_back();
    }
}

void get_result()
{
    result = min(result, get_gab(dest, N));

    for(int i=1; i<=6; i++)
    {
        vector<int> v;
        dfs(0, i, v);
    }

    cout << result << '\n';
}

int main(void)
{
    init();

    get_result();

    return 0;
}
