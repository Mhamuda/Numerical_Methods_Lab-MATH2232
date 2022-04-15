#include <bits/stdc++.h>
using namespace std;

class LagrangeInterpolation
{
private:
    double x[100], y[100], xp, yp, p;
    int i, j;

public:
    LagrangeInterpolation()
    {
        yp = 0.0;
        p = 1.0;
        i = 0;
    }

public:
    void addData(double a, double b)
    {
        x[i] = a;
        y[i] = b;
        i++;
    }

public:
    void findInterpolation(double xp, int n)
    {
        for (i = 0; i < n; i++)
        {
            p = 1;
            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    p = p * (xp - x[j]) / (x[i] - x[j]);
                }
            }
            yp = yp + p * y[i];
        }
    }

public:
    double getInterpolation()
    {
        return yp;
    }
};

int main()
{
    LagrangeInterpolation lagrangeInterpolation;
    double x, y, xp;
    int n, i;

    cout << "How many record you will be enter : \n";
    cin >> n;

    cout << "Enter the tabulated value in the form of x y : \n";
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        lagrangeInterpolation.addData(x, y);
    }

    cout << "Enter the value for x for which you want to find y : \n";
    cin >> xp;

    lagrangeInterpolation.findInterpolation(xp, n);
    double ans = lagrangeInterpolation.getInterpolation();
    cout << "Value at " << xp << " is " << setprecision(10) << ans;

    cout << "\n";
    return 0;
}
