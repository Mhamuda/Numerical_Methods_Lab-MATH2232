#include <bits/stdc++.h>
using namespace std;

class NewtonDividedDifferenceInterpolation
{
private:
    double x[100], y[100][100], term, result;
    int i, j, k;

public:
    NewtonDividedDifferenceInterpolation()
    {
        i = 0;
        k = 0;
        result = 0.0;
    }

public:
    void addData(double a, double b)
    {
        x[i] = a;
        y[i][k] = b;
        i++;
    }

public:
    double productTerm(int i, double val)
    {
        double pro = 1;

        for (int j = 0; j < i; j++)
        {
            pro *= (val - x[j]);
        }

        return pro;
    }

public:
    void findDivideDiffTable(int n)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                y[j][i] = (y[j][i - 1] - y[j +1][i - 1]) / (x[j] - x[i+j]);
            }
        }
    }

public:
    void applyFormula(double val, int n)   
    {
        result = y[0][0];

        for (int i = 1; i < n; i++)
        {
            result += (productTerm(i, val) * y[0][i]);
        }
    }

public:
    void printDiffTable(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                cout << setprecision(4) << y[i][j] << "\t";
            }
            cout << "\n";
        }
    }

public:
    double getAns()
    {
        return result;
    }
};

int main()
{
    NewtonDividedDifferenceInterpolation NDDI;
    double x, y, point;
    int n;
    cout << "How many record you will be enter : \n";
    cin >> n;

    cout << "Enter the tabulated points in the form of x y : \n";

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        NDDI.addData(x, y);
    }

    NDDI.findDivideDiffTable(n);
    NDDI.printDiffTable(n);

    cout<<"Enter the value of x for which you want to find the y : \n";
    cin >> point;

    NDDI.applyFormula(point, n);
    double ans = NDDI.getAns();

    cout << "\nValue at " << point << " is " << setprecision(10) << ans;
    cout << "\n";

    return 0;
}