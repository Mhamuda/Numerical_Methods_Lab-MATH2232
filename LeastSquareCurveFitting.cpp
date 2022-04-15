#include <bits/stdc++.h>
using namespace std;

class LeastSquareCurveFitting
{
private:
    double y0, y1, sumX, sumY, sumXX, sumXY;

public:
    LeastSquareCurveFitting()
    {
        sumX = 0.0;
        sumY = 0.0;
        sumXX = 0.0;
        sumXY = 0.0;
    }

public:
    void LeastSquare(double x[], double y[], double n)
    {
        for (int i = 0; i < n; i++)
        {
            sumX += x[i];
            sumY += y[i];
            sumXX += (x[i] * x[i]);
            sumXY += (x[i] * y[i]);
        }

        y1 = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
        y0 = (sumY / n) - y1 * (sumX / n);
    }

public:
    void get_ans()
    {
        cout << "Hence the best straight line fit is given by : \n";
        cout << "Y = " << y0 << " + " << y1 << "x";
        cout << "\n";
    }
};

int main()
{
    LeastSquareCurveFitting LSCF;
    int n;
    cin >> n;

    double x[n], y[n];

    for (int i = 0; i < n; i++)
        cin >> x[i];

    for (int i = 0; i < n; i++)
        cin >> y[i];

    LSCF.LeastSquare(x, y, n);
    LSCF.get_ans();

    return 0;
}