#include <bits/stdc++.h>
using namespace std;

class Simpsons13Rule
{
private:
    double s;

public:
    Simpsons13Rule()
    {
        s = 0.0;
    }

public:
    double eq(double x)
    {
        return 1 / (1 + x);
    }

public:
    void findSimpson(double lowerBound, double upperBound, int n)
    {
        double h = (upperBound - lowerBound) / n;
        double y[n + 5], sum = 0.0, sum2 = 0.0;

        for (int i = 0; i <= n; i++)
            y[i] = eq(lowerBound + i * h);

        for (int i = 1; i < n; i++)
        {
            if (i & 1)
                sum += y[i];
            else
                sum2 += y[i];
        }

        s = (h / 3.0) * (y[0] + 4 * sum + 2 * sum2 + y[n]);
    }

public:
    double getAns()
    {
        return s;
    }
};

int main()
{
    Simpsons13Rule simpsons13Rule;
    int n;
    double lowerBound, upperBound;
    cin >> lowerBound >> upperBound >> n;

    simpsons13Rule.findSimpson(lowerBound, upperBound, n);
    double ans = simpsons13Rule.getAns();

    cout << "Required value of integration is : " << ans;
    cout << "\n";

    return 0;
}