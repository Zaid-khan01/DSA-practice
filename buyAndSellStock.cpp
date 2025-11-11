#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter size = ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter elements = ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int minPrice = v[0];   // lowest price seen so far
    int maxProfit = 0;     // best profit

    for (int i = 1; i < n; i++) {
        // Update profit if selling today is better
        maxProfit = max(maxProfit, v[i] - minPrice);

        // Update minPrice if today’s price is lower
        minPrice = min(minPrice, v[i]);
    }

    cout << "Maximum Profit = " << maxProfit << endl;

    return 0;
}
