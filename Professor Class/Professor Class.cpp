#include <iostream>
#include "Professor.h"

int main()
{
    Professor test;
    Professor Douglas("Donald", "Douglas", true, 217);

    // default professor class
    cout << test.toString() << endl;
    
    // whitespace
    cout << endl;

    // Filled professor class
    cout << Douglas.toString() << endl;
}