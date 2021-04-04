#include <iostream>
#include <vector>

using namespace std;

int n;
unsigned int sum=0;
unsigned int check_sum=0;
vector<int> drink;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void answer(int current,int check) {
    if(current==n)  {
        if(check_sum>sum)
            sum=check_sum;
        return;
    }
    if(check==2) {
        answer(current+1,0);
    }
    else {
        check_sum+=drink[current];
        answer(current+1,check+1);
        check_sum-=drink[current];
        answer(current+1,0);
    }
}

int main(void) {
    init();
    int k;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin>> k;
        drink.push_back(k);
    }
    answer(0,0);
    cout <<sum<<'\n';
}