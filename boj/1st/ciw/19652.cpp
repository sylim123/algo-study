#include <iostream>
#include <vector>

using namespace std;

int n,m,current=1;
vector<int> num;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs_check( int m, int depth) {
    if(depth == m) {
        for(int i=0;i<depth;i++) cout << num[i] << ' ';
        cout<<'\n';  
        return;
    }
    for(int i=current;i<n+1;i++) {
        
        num.push_back(i);
        current=i;
        dfs_check(m,depth+1);
        num.pop_back();

    }
}
int main(void)
{
    init();
    cin >> n >> m;
    dfs_check(m,0);
}