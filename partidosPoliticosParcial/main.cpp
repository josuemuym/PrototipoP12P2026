#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "partidosPoliticos.h"       // se incluyo la biblioteca .h

using namespace std;

int main()
{
    srand(getpid());

    //creacion del objeto de partidos politicos.
    partidosPoliticos pp;
    //llamar la funcion por medio del objeto
    pp.llamarCiclo();

    return 0;
}
