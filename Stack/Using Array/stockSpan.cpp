#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans(price.size());
    stack<int> s;

    for (int i = 0; i < price.size(); i++)
    {
        while (s.size() > 0 && price[s.top()] <= price[i])
        { // previous element < current element
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = i + 1;
        }
        else
        { // when we found that immediate previous high element
            ans[i] = i - s.top(); // span = i - prevHigh
        }
        s.push(i);
    }

    for (int val : ans)
    {
        cout << val << " ";
    }
    return 0;
}
