#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> v;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
}

void get_ans()
{
    if(v.size() == 1)
    {
        cout << v[0] * v[0] << '\n';
        return;
    }

    sort(v.begin(), v.end());
    cout << v[0] * v[v.size() - 1] << '\n';
}

int main(void)
{
    init();

    get_ans();

    return 0;
}
