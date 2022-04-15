#include <bits/stdc++.h>
using namespace std;

class NewtonForwardInterpolation
{
private:
    double x[100], y[100][100], term, result;
    int i, j, k;

public:
    NewtonForwardInterpolation()
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
    void calculateDiffTable(int n)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
            }
        }
    }

public:
    void getDiffTable(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << setprecision(4) << x[i] << "\t";

            for (int j = 0; j < n - i; j++)
            {
                cout << setprecision(4) << y[i][j] << "\t";
            }
            cout << "\n";
        }
    }

public:
    double u_cal(double u, int n)
    {
        double temp = u;

        for (int i = 1; i < n; i++)
            temp *= (u - i);

        return temp;
    }

public:
    int fact(int n)
    {
        int f = 1;

        for (int i = 2; i <= n; i++)
            f *= i;

        return f;
    }

public:
    void applyFormula(double val, int n)
    {
        result = y[0][0];
        double u = (val - x[0]) / (x[1] - x[0]);

        for (int i = 1; i < n; i++)
        {
            result += (u_cal(u, i) * y[0][i]) / fact(i);
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
    NewtonForwardInterpolation NFI;
    double x,y,point;
    int n;

    cout<<"How many record you will be enter : \n";
    cin>>n;

    cout<<"Enter the tabulated points in the form of x y : \n";

    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        NFI.addData(x,y);
    }
    cout<<"Enter the value of x for which you want to find the y : \n";
    cin>>point;

    NFI.calculateDiffTable(n);
    NFI.getDiffTable(n);

    NFI.applyFormula(point,n);
    double ans = NFI.getAns();

    cout<<"Value at "<<point<<" is : "<<setprecision(10)<<ans;
    cout<<"\n";

    return 0;
}