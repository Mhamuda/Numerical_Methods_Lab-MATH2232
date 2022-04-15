#include <bits/stdc++.h>
using namespace std;

class FalsePosition
{
private:
    double a, b, root, eps;
    int itr;

public:
    FalsePosition()
    {
        a = 0.0;
        b = 0.0;
        eps = 0.0000000001;
        itr = 1;
    }

public:
    double eq(double x)
    {
        return x * x * x - 2 * x - 5;
        // return x * x * x + 3 * x - 5;
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
    double getMid(double a, double b)
    {
        return (a * eq(b) - b * eq(a)) / (eq(b) - eq(a));
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
        double mid = getMid(a, b);

        while (abs(eq(b) - eq(a)) > eps && itr != 1000000)
        {
            if (eq(mid) == 0.0)
                break;
            else if (eq(a) * eq(mid) < 0)
                b = mid;
            else
                a = mid;

            itr++;
            mid = getMid(a, b);
        }

        root = mid;
    }
};

int main()
{
    FalsePosition falsePosition;
    falsePosition.findRoot();
    double ans = falsePosition.getRoot();

    cout << "The root of the given equation is : " << setprecision(10) << ans;
    cout << "\n";

    return 0;
}