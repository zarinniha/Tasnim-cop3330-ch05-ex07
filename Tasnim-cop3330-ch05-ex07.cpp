#include "std_lib_facilities.h"
using namespace std;

//this function find sqrt(b^2-4ac) value

void find_roots(double a, double b, double c,double *dis1,double *dis2)
{

    double z= ((b*b)-(4*a*c));

    if(z>0)
    {
        *dis1= +sqrt(z);
        *dis2= -sqrt(z);

    }else if(z==0)
    {
        *dis1=sqrt(z);
        *dis2=-1;
    }else if(z<0)
    {
       *dis1=-1;
       *dis2=-1;

    }
}

void do_math(double a, double b, double dis1, double dis2)
{
    double x1;
    double x2;
    if(dis1!=-1 &&dis2!=-1)
    {
        x1=(-b+dis1)/(2*a);   
        x2=(-b+dis2)/(2*a);

        cout<<"The roots are "<<x1<<" and "<<x2;


    }else if(dis1!=-1 && dis2==-1)
    {
        x1 = -b/(2*a);

        cout<<"The root is "<<x1;
    }else if(dis1==-1 &&dis2==-1)
    {

       cout<<"This is not a real root.\n Please enter diffrent numbers next time.";
    }
}


int main()

{
    double dis1;
    double dis2;

    double a,b,c;

    cout<<"Please enter three number to calculate for a quadratic equation: \n";
    cin>>a>>b>>c;

    find_roots(a,b,c,&dis1,&dis2);
    do_math(a,b,dis1,dis2);
    return 0;
}