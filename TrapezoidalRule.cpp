#include <bits/stdc++.h>
using namespace std;

class TrapezoidalRule
{
private:
    double s;

public:
    TrapezoidalRule()
    {
        s = 0.0;
    }

public:
    double eq(double x)
    {
        return 1 / (1 + x * x);
    }

public:
    void findAns(double lowerBound, double upperBound, int n)
    {
        double h = (upperBound - lowerBound) / n;
        double y[n + 5], sum = 0.0;

        for (int i = 0; i <= n; i++)
            y[i] = eq(lowerBound + i * h);

        for (int i = 1; i < n; i++)
            sum += y[i];

        s = (h / 2.0) * (y[0] + 2 * sum + y[n]);
    }

public:
    double getAns()
    {
        return s;
    }
};

int main()
{
    TrapezoidalRule trapezoidalRule;
    int n;
    double lowerBound, upperBound;
    cin >> lowerBound >> upperBound >> n;

    trapezoidalRule.findAns(lowerBound, upperBound, n);
    double ans = trapezoidalRule.getAns();

    cout << "The definite integral is : " << ans;
    cout << "\n";

    return 0;
}