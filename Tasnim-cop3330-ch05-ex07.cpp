#include "std_lib_facilities.h"
using namespace std;
#define error -1 //defining negative value as a sign of error

//this function find sqrt(b^2-4ac) value

void find_roots(double a, double b, double c, double *dis1, double *dis2)
{

    double z = ((b * b) - (4 * a * c));

    if (z > 0) //sqrt of a positive number give two signed answer
    {
        *dis1 = +sqrt(z);
        *dis2 = -sqrt(z);
    }
    else if (z == 0) //if z=0
    {
        *dis1 = sqrt(z);
        *dis2 = error;
    }
    else if (z < 0) //if z is negative, there is no sqrt of negative number
    {
        *dis1 = error;
        *dis2 = error;
    }
}

void do_math(double a, double b, double dis1, double dis2)
{
    double x1;
    double x2;
    if (dis1 != error && dis2 != error)
    {
        x1 = (-b + dis1) / (2 * a);
        x2 = (-b + dis2) / (2 * a);

        cout << "The roots are " << x1 << " and " << x2;
    }
    else if (dis1 != error && dis2 == error)
    {
        x1 = -b / (2 * a);

        if(x1==-0)
        {
            x1=0;
        }

        cout << "The root is " << x1;
    }
    else if (dis1 == error && dis2 == error)
    {

        cout << "This is not a real root.\nPlease enter diffrent numbers next time.";
    }
}

int main()

{
    double dis1;
    double dis2;

    double a, b, c;

    cout << "Please enter three number to calculate for a quadratic equation: \n";
    cin >> a >> b >> c;

    if (a == 0 && b != 0) //if a=0 and b is not 0 that x=-(c/b)
    {
        double x = (-c / b);

        if(x==-0)
        {
            x=0; //-0 is
        }
        cout << "The root is " << x << endl;
    }
    else if (a == 0 && b == 0) //if and b bother are 0 than there is no x to find the value for
    {
        cout << "These numbers are invalid.";
    }
    else if (b == 0 && c < 0) //if b=0 and c is negative than -c/a is poistive and sqrt is possible
    {
        double x1 = +sqrt(-c / a);
        double x2 = -sqrt(-c / a);

        cout << "The roots are " << x1 << " " << x2;
    }
    else
    {
        find_roots(a, b, c, &dis1, &dis2);
        do_math(a, b, dis1, dis2);
    }

    return 0;
}