#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "partidosPoliticos.h"

using namespace std;

int main()
{
    srand(getpid());

    partidosPoliticos pp;
    pp.llamarCiclo();

    return 0;
}
