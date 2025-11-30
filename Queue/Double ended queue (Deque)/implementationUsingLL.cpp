#include<iostream>
#include<deque>
using namespace std;
int main(int argc, char const *argv[])
{
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3); // 1, 2, 3

    d.push_front(4); // 4, 1, 2, 3
    d.pop_back();

    while(!d.empty()){
        cout<<d.front()<<" "; // 4, 1, 2
        d.pop_front();
    }
    return 0;
}
