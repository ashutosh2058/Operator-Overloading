
#include <iostream>
#include<math.h>
using namespace std;

class DM;

class DB
{
    int feet;
    float inches;
    friend class DM;

public:
    void getdata()
    {
        cout << "Enter number in inches : ";
        int n;
        cin >> n;
        feet = n / 12;
        inches = fmod(n, 13);
        cout << endl;
    }
    void putdata()
    {
        cout << "Distance : " << feet << " feets " << inches << " inches " << endl;
            cout << endl;
    }
    DB operator+(DM &b);
};
class DM
{
    int meter;
    float centimeter;
    friend class DB;

public:
    void getdata()
    {
        int num;
        cout << "Enter num in centimeter : ";
        cin >> num;
        meter = num / 100;
        centimeter = fmod(num, 100);
        cout << endl;
    }
    void putdata()
    {
        cout << "Distance : " << meter << " meters " << centimeter << "centimeters." << endl;
cout<< endl;
    }
    DM operator + (DB &b)
    {
        DM a;
        a.centimeter = 2.54 * (b.feet * 12 + b.inches);
        a.meter = meter + (a.centimeter + centimeter) / 100;
        a.centimeter = fmod((centimeter + a.centimeter), 100);
        return a;
    }
};
DB DB::operator + (DM &b)
{
    DB a;
    a.inches = 0.393701 * (b.meter * 100 + b.centimeter);
    a.feet = feet + (int)(inches + a.inches) / 12;
    a.inches = fmod((inches + a.inches), 12);
    return a;
}
int main()
{
    DM a;
    DB b;
    a.getdata();
    b.getdata();
    a.putdata();
    b.putdata();
    cout << "\t\t***Operator overloading Result***\n" << endl;
    DM c = a + b;
    DB d = b + a;
    c.putdata();
    d.putdata();
    return 0;
}
