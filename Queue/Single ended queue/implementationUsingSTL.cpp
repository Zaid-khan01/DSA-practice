#include<iostream>
#include<queue>
using namespace std;

int main(int argc, char const *argv[])
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}
