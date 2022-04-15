#include <bits/stdc++.h>
using namespace std;

class Bisection
{
private:
    double a, b, root, eps;

public:
    Bisection()
    {
        a = 0.0;
        b = 0.0;
        eps = 0.0000000001;
    }

public:
    double eq(double x)
    {
        return x * x * x + 3 * x - 5;
    }

public:
    void findInterval()
    {
        do
        {
            a--;
            b++;
        } while (eq(a) * eq(b) >= 0);

        if (eq(b) < 0)
            swap(a, b);

        return;
    }

public:
    double getRoot()
    {
        return root;
    }

public:
    void findRoot()
    {
        findInterval();
        double mid = (a + b) / 2;

        while (abs(eq(b) - eq(a)) > eps)
        {
            if (eq(mid) == 0.0)
                break;
            else if (eq(mid) > 0)
                b = mid;
            else
                a = mid;

            mid = (a + b) / 2;
        }

        root = mid;
    }
};

int main()
{
    Bisection bisection;
    bisection.findRoot();
    double ans = bisection.getRoot();

    cout << "The root of the given equation is : " << setprecision(10) << ans;
    cout << "\n";

    return 0;
}