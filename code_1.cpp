
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    int num1,num2;
    stack<int> v;
    for(int i=0;i<moves.size();i++)
    {
        for(int j=0;j<board.size();j++)
        {
            if(board[j][moves[i]-1]!=0)
            {
                if(v.size()>0)
                {
                    num1=board[j][moves[i]-1];
                    num2=v.top();
                    if(num1==num2)
                    {
                        v.pop();
                        answer+=2;
                    }
                    else
                        v.push(num1);
                }
                else
                    v.push(board[j][moves[i]-1]);
                board[j][moves[i]-1]=0;
                break;
            }
        }
    }
    return answer;
}
