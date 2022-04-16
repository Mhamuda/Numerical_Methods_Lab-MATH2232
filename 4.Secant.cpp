#include<bits/stdc++.h>
using namespace std;

class Secant
{
private:
    double a,b,xa,xb,x,root,eps,epsr;

public:
    Secant()
    {
        srand(time(0));
        a = rand()%100;
        b = rand()%100;
        eps = 0.0000000001;
        epsr = 1000;
    }

public:
    double f(double x)
    {
        return x*x*x-2*x-5;
    }

public:
    double getRoot()
    {
        return root;
    }

public:
    void findRoot()
    {
        xa = a;
        xb = b;
        cerr<<"a = "<<xa<<" b = "<<xb<<"\n";

        do{
            x = xb - ((f(xb)*(xb-xa))/(f(xb)-f(xa)));
            xa=xb;
            xb=x;

            epsr = abs((xb-xa)/xb);

        }while(epsr>eps);

        root = x;
    }
};


int main()
{
    Secant secant;
    secant.findRoot();

    double ans = secant.getRoot();

    cout<<"The root of the equation is : "<<setprecision(10)<<ans;
    cout<<"\n";

    return 0;
}
