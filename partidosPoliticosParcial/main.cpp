#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "partidosPoliticos.h"       // se incluyo la biblioteca .h

using namespace std;

int main()
{
    srand(getpid());

    partidosPoliticos pp;
    pp.llamarCiclo();

    return 0;
}
