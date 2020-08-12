#include <iostream>
#include "bed.h"
#include "sofa.h"
#include "sofabed.h"
int main()
{
    bed b;
    sofa s;
    sofabed sb;
    b.sleep();
    s.sit();
    sb.sleep();
    sb.sit();
    return 0;
}

