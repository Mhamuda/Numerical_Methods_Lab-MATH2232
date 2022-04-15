#include <bits/stdc++.h>
using namespace std;

class NewtonRaphson
{
private:
    double root, eps;

public:
    NewtonRaphson()
    {
        root = 2.0;
        eps = 0.0000000001;
    }

public:
    double eq(double x)
    {
        return x * x * x - 2 * x - 5;
    }

public:
    double ddxeq(double x)
    {
        return 3 * x * x - 2;
    }

public:
    double getRoot()
    {
        return root;
    }

public:
    void findRoot()
    {
        while (abs(eq(root)) > eps)
        {
            root = root - (eq(root) / ddxeq(root));
        }
    }
};

int main()
{
    NewtonRaphson newtonRaphson;
    newtonRaphson.findRoot();
    double ans = newtonRaphson.getRoot();

    cout << "The root of the given equation is : " << setprecision(10) << ans;
    cout << "\n";

    return 0;
}