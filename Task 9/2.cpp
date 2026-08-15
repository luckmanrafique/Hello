#include <iostream>
using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    const int n = 5;
    const int capacity = 10;

    string items[n] =
    {
        "Water Bottle",
        "Jacket",
        "Snacks",
        "Flashlight",
        "First Aid Kit"
    };

    int weight[n] = {3, 4, 2, 5, 3};
    int usefulness[n] = {8, 9, 6, 10, 7};

    int dp[n + 1][capacity + 1] = {0};

    // 0/1 Knapsack
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    usefulness[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum Usefulness: "
         << dp[n][capacity] << endl;

    // Find selected items
    int w = capacity;

    cout << "\nSelected Items:\n";

    int totalWeight = 0;
    int totalUsefulness = 0;

    for (int i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            cout << items[i - 1]
                 << " | Weight: "
                 << weight[i - 1]
                 << " kg | Usefulness: "
                 << usefulness[i - 1]
                 << endl;

            totalWeight += weight[i - 1];
            totalUsefulness += usefulness[i - 1];

            w = w - weight[i - 1];
        }
    }

    cout << "\nTotal Weight: "
         << totalWeight << " kg" << endl;

    cout << "Total Usefulness: "
         << totalUsefulness << endl;

    return 0;
}