#include <bits/stdc++.h>
using namespace std;

class Secant
{
private:
    double a, b, root, eps;

public:
    Secant()
    {
        a = 2.0;
        b = 3.0;
        eps = 0.0000000001;
    }

public:
    double eq(double x)
    {
        return x * x * x - 2 * x - 5;
    }

public:
    double getRoot()
    {
        return root;
    }

public:
    void findRoot()
    {
        do
        {
            root = b - ((eq(b) * (b - a)) / (eq(b) - eq(a)));
            a = b;
            b = root;
        } while (abs(eq(root)) > eps);
    }
};

int main()
{
    Secant secant;
    secant.findRoot();
    double ans = secant.getRoot();

    cout << "The root of the givn equation is : " << setprecision(10) << ans;
    cout << "\n";
    return 0;
}