/* This program allows the user to enter and work with fractions. */
#include<iostream>
#include<string>
#include <math.h>
#include<cstring>
using namespace std;
/*void ReadFraction(int & Num, int & Denom, int & Num2, int & Denom2, int & Num3, int & Denom3,int & Num4, int & Denom4)
/* This function will allow the user to enter two fraction. */

int reduce2(int &newNum, int &newDenom, int &whole)
{
    whole = 0;
    int oldNum = newNum;
    if (newNum >= newDenom)
    {
        if (newNum % newDenom != 0)
        {
            newNum = newNum % newDenom;
            whole = (oldNum-newNum)/newDenom;
        }
        else if (newNum % newDenom == 0)
        {
            whole = newNum/newDenom;
            newNum = 0;
        }
    }
    else
    {
        return(newNum, newDenom, whole);
    }
    return(newNum, newDenom, whole);

}

int reduce1(int &newNum, int &newDenom)
{
    int a = 0;
    int b = 0;
    int i = 0;
    a = newDenom;
    b = newNum;

    for (i = 50; i > 1; i--)
    {
        if ((a % i == 0) && (b % i == 0))
            {
                a /= i;
                b /= i;
            }

        newDenom = a;
        newNum = b;
    }
    return(newNum, newDenom);
}

void addfractions(int &Num, int &Denom, int &Num2, int & Denom2)
{
    int newNum;
    int newDenom;
    int a,b,c,d,e,f;
    c = Num;
    d = Denom;
    e = Num2;
    f = Denom2;
    if (Denom != Denom2)
    {
        a = Denom;
        b = Denom2;
        a = Denom * Denom2;
        b = Denom2*Denom;
        c = Num * Denom2;
        e = Num2 * Denom;

    }
    newNum = c + e;
    newDenom =b;

    cout << "Sum of " << Num << "/" << Denom << " and " << Num2 << "/" << Denom2 << " is "<< newNum << "/" << newDenom << endl;
    cout << newNum << "/" << newDenom << " is reduced to ";
    reduce1(newNum,newDenom);
    cout << newNum << "/" << newDenom << endl;
    cout << newNum << "/" << newDenom << " is reduced to ";
    int whole = 0;
    reduce2(newNum,newDenom,whole);
    cout << whole << " and " << newNum << "/" << newDenom << endl;
}

void Input_Fractions(int &Num, int &Num2, int &Num3, int &Num4, int &Denom, int &Denom2, int &Denom3, int &Denom4)
{
    cout << "Enter the numerator for the first fraction: ";
    cin >> Num;
    while (Num < 0)
    {
        cout << "Invalid input. Enter a positive number: ";
    }
    cout << endl;

    cout << "Enter the denominator for the first fraction: ";
    cin >> Denom;
    while (Denom <=0){
        cout << "Invalid input. Enter a positive nonzero number: ";
        cin >> Denom;
    }
    cout << endl;

    cout << "Enter the numerator for the second fraction: ";
    cin >> Num2;
    while (Num2 < 0)
    {
        cout << "Invalid input. Enter a positive number: ";
        cin >> Num2;
    }
    cout << endl;

    cout << "Enter the denominator for the second fraction: ";
    cin >> Denom2;
    while (Denom2 <=0){
        cout << "Invalid input. Enter a positive nonzero number: ";
        cin >> Denom2;
    }
    cout << endl;

    cout << "Enter the numerator for the third fraction: ";
    cin >> Num3;
    while (Num3 < 0)
    {
        cout << "Invalid input. Enter a positive number: ";
        cin >> Num3;
    }
    cout << endl;

    cout << "Enter the denominator for the third fraction: ";
    cin >> Denom3;
    while (Denom3 <=0){
        cout << "Invalid input. Enter a positive nonzero number: ";
        cin >> Denom3;
    }
    cout << endl;

    cout << "Enter the numerator for the fourth fraction: ";
    cin >> Num4;
    while (Num4 < 0)
    {
        cout << "Invalid input. Enter a positive number: ";
        cin >> Num4;
    }
    cout << endl;

    cout << "Enter the denominator for the fourth fraction: ";
    cin >> Denom4;
    while (Denom4 <=0)
    {    
        cout << "Invalid input. Enter a positive nonzero number: ";
        cin >> Denom4;
    }
    cout << endl;
}

bool IsGreater(int &Num, int &Denom, int &Num2, int &Denom2)
{
    float a,b;
    a = Num/Denom;
    b = Num2/Denom;
    if (a > b)
    {
        cout << Num << "/" << Denom << " is greater than " << Num2 << "/" << Denom2 << endl;
        return true;
    }
    else
    { 
        cout << Num << "/" << Denom << " is not greater than " << Num2 << "/" << Denom2 << endl;
        return false;
    }
}

int powerr(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return x * powerr(x,n-1);
    }
}

void FracPower(int &Num, int &Denom, int n)
{

    int x;
    int y;
    x = powerr(Num,n);
    y = powerr(Denom, n);
    reduce1(x,y);
    cout << Num << "/" << Denom << " raised to the power of " << n << " is " << x << "/" << y << endl;
    int whole;
    cout << x << "/" << y << " is reduced to ";
    reduce2(x,y,whole);
    cout << whole << " and " << x << "/" << y << endl;



}

int main()
{    
        char an;
        do
        {
            int Num, Denom, Num2, Denom2, Num3, Num4, Denom3, Denom4 = 0;
            int n;
            //ReadFraction(Num, Denom,Num2,Denom2);
            //Reduce(Num, Denom, Num2, Denom2);
            Input_Fractions(Num, Num2, Num3, Num4, Denom, Denom2, Denom3, Denom4);
            addfractions(Num, Denom, Num2, Denom2);
            addfractions(Num, Denom, Num3, Denom3);
            addfractions(Num2, Denom2, Num3, Denom3);
            addfractions(Num2, Denom2, Num4, Denom4);
            IsGreater(Num, Denom, Num2, Denom2);
            IsGreater(Num2, Denom2, Num3, Denom3);
            IsGreater(Num2, Denom2, Num4, Denom4);
            IsGreater(Num3, Denom3, Num4, Denom4);
            FracPower(Num, Denom, 2);
            FracPower(Num2, Denom2, 3);
            FracPower(Num3, Denom3, 4);
            FracPower(Num4, Denom4, 5);
            cout <<"Would you like to do another fraction? ";
            cin >> an;
            cout << endl;
        } while ((an == 'y') || (an == 'Y'));
        
        return(0);
}