#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 1;
    while(100*pow(n, 2) > pow(2, n))
    {
        //n++;  //Why doesn't this work!!????
        n += 1;
    }
    cout << "The smallest number of items is " << n << endl;
    printf("Hi");
}