#include<bits/stdc++.h>
using namespace std;

class FalsePosition
{
private:
    double a,b,xa,xb,root,eps,epsr,mid,prev;

public:
    FalsePosition()
    {
        a=0.0;
        b=0.0;
        eps = 0.0000000001;
        epsr = 10;
    }

public:
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

        do{
            a= rand()%10;
            b=rand()%10;

            if(rand()%2)
                a*=-1;
            if(rand()%2)
                b*=-1;

        }while(eq(a)*eq(b)>0);

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

        xa =a;
        xb = b;

        cerr<<"a = "<<xa<<" "<<"b= "<<xb<<"\n";

        do{
            mid = (xa*eq(xb)-xb*eq(xa))/(eq(xb)-eq(xa));

            if(eq(mid)==0.0)
                break;
            else if(eq(mid)<0)
                xa=mid;
            else
                xb=mid;

            epsr = (mid-prev)/mid;
            prev=mid;

        }while(epsr>eps);

        root =mid;
    }

};

int main()
{
    FalsePosition falsePosition;
    falsePosition.findRoot();

    double ans =falsePosition.getRoot();

    cout<<"The root of the given equation is : "<<setprecision(10)<<ans;
    cout<<"\n";

    return 0;
}
