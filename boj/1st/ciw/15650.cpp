#include <iostream>
#include <vector>

using namespace std;

bool check[9]={false};
int n,m;
vector<int> num;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs_check( int m, int depth,int k) {
    if(depth == m) {
        for(int i=0;i<depth;i++) cout << num[i] << ' ';
        cout<<'\n';  
        return;
    }
    for(int i=k;i<n+1;i++) {
        if(!check[i])    
        {
            num.push_back(i);
            check[i]=true;
            dfs_check(m,depth+1,i);
            check[i]=false;
            num.pop_back();
        }
    }

}
int main(void)
{
    init();
    cin >> n >> m;
    dfs_check(m,0,1);
}