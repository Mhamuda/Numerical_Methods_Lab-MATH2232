#include<bits/stdc++.h>
using namespace std;

class Bisection
{
public:
    double a,b,xa,xb,mid,prev,root,eps,epsr;

public:
    Bisection()
    {
        a=0.0;
        b=0.0;
        eps=0.0000000001;
    }

private:
    double eq(double x)
    {
        return x*x*x-2*x-5;
    }

public:
    void findInterval()
    {
        // This program will create different sequence of
        // random numbers on every program run

        // Use current time as seed for random generator
        srand(time(0));

        do
        {
            a=rand()%10;
            b=rand()%10;

            if(rand()%2)
                a*=-1;
            if(rand()%2)
                b*=-1;

        }
        while(eq(a)*eq(b)>0);

        if(a>b)
            swap(a,b);
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
        xa = a;
        xb = b;

        cerr <<"a = "<< xa << " "<<"b = "<< xb << "\n"; // Randomly generated interval range

        do{
            mid = (a+b)/2;

            if(eq(mid)==0.0)
                break;
            else if(eq(mid)<0)
                a=mid;
            else
                b=mid;

            epsr = abs((mid-prev)/mid); //relative error
            prev=mid;

        }while(epsr>eps);

        root=mid;
    }
};

int main()
{
    Bisection bisection;
    bisection.findRoot();

    double ans = bisection.getRoot();

    cout<<"The root of the given equation is : "<<setprecision(10)<<ans;
    cout<<"\n";

    return 0;
}
