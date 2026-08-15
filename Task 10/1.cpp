#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[100];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int current = a[0];
    int maximum = a[0];

    for (int i = 1; i < n; i++)
    {
        if (current + a[i] > a[i])
            current = current + a[i];
        else
            current = a[i];

        if (current > maximum)
            maximum = current;
    }

    cout << maximum << endl;

    return 0;
}