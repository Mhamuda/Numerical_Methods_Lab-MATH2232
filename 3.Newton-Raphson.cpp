#include<bits/stdc++.h>
using namespace std;

class NewtonRaphson
{
private:
    double a,prevX,curX,root,eprs,eps;

public:
    NewtonRaphson()
    {
        srand(time(0));   // prottekbar program run korle vinno vinno random value generate korbe

        a = rand()%10;
        eps = 0.0000000001;
        eprs=1000;
    }

public:
    double eq(double x)
    {
        return x*x*x-2*x-5;
    }

public:
    double ddxeq(double x)
    {
        return 3*x*x-2;
    }

public:
    double getRoot()
    {
        return root;
    }

public:
    void findRoot()
    {
        prevX = a;
        cerr<<"a = "<<prevX<<"\n";

        do{
            curX = prevX - (eq(prevX)/ddxeq(prevX));
            eprs = abs((curX-prevX)/curX);
            prevX = curX;

        }while(eprs>eps);

        root =curX;

    }
};

int main()
{
    NewtonRaphson newtonRaphson;
    newtonRaphson.findRoot();

    double ans = newtonRaphson.getRoot();

    cout<<"The root of the given equation is : "<<setprecision(10)<<ans;
    cout<<"\n";

    return 0;
}
