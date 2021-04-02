#include <iostream>

using namespace std;

int n;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n;
}

void answer(){
    int n1=1,n2=1,temp;
    for(int i=1;i<n;i++) {
        temp=(n1*2+n2)%10007;
        n1=n2;
        n2=temp;
    }
    cout << n2;
}

int main(void) {
    init();
    answer();
    return 0;
}