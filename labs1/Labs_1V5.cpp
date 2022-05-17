#include <iostream>
#include "Rational.h"

int main()
{
    int a=1, b=2;
    using namespace std;
   
    cin >> a>>b;
    Rational test1(a,b), test2(3, 6), test3(2, 6);
    cout << "\nTest1 equals " << test1;
    cout << "\nTest2 equals " << test2;
    cout << "\nTest3 equals " << test3;
    // Test our operators
    cout << "\nTest1 * Test2 equals " << test1 * test2;
    cout << "\nTest1 / Test3 equals " << test1 / test3;
    cout << "\nTest2 + Test3 equals " << test2 + test3;
    cout << "\nTest3 - Test1 equals " << test3 - test1;

    if (test1 == test2)
        cout << "\nTest1 is equal to Test2";
    if (test1 < test2)
        cout << "\nTest1 is less than Test2";
    return 0;
}