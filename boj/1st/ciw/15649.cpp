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

void dfs_check( int m, int depth) {
    if(depth == m) {
        for(int i=0;i<depth;i++) cout << num[i] << ' ';
        cout<<endl;  
        return;
    }
    for(int i=1;i<n+1;i++) {
        if(!check[i])    
        {
            num.push_back(i);
            check[i]=true;
            dfs_check(m,depth+1);
            check[i]=false;
            num.pop_back();
        }
    }

}
int main(void)
{
    init();
    cin >> n >> m;
    dfs_check(m,0);
}