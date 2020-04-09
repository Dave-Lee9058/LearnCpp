#include <iostream>

int main()
{
    char buff[50];
    int n, a = 5, b = 3;
    n = sprintf(buff, "%d + %d =  %d", a, b, a+b);
    printf("[%s] is a string %d chars long \n"
            "## Test ## ", buff, n);

    return 0;
}