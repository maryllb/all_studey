#include <iostream>
#include "dog.h"
#include "cat.h"
#include "Animal.h"
int main()
{

    Animal *a1 = new dog;
    Animal *a2 = new cat;
    a1->voice();
    a2->voice();
    delete a1;
    delete a2;
}

