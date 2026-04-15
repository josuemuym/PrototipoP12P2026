#ifndef PARTIDOSPOLITICOS_H
#define PARTIDOSPOLITICOS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

//definicion de constantes
#define NUMERO_PARTIDOS 5
#define NUMERO_RONDAS 2
#define MAX_CALIFICACION 100000
#define MIN_CALIFICACION 0
#define MAXIMA_LONGITUD_CADENA 100

class partidosPoliticos
{
    public:
        partidosPoliticos();
        void llamarCiclo();
        ~partidosPoliticos();

    private:
        float partido_1;
        float partido_2;
        float partido_3;

        int  busquedaAleatorios(int minimo, int maximo);
        void llenarMatriz(float matriz[NUMERO_PARTIDOS][NUMERO_RONDAS + 1]);
        void imprimirMatrizLinea();
        float imprimirMatriz(float matriz[NUMERO_PARTIDOS][NUMERO_RONDAS + 1],char partidos[NUMERO_PARTIDOS][MAXIMA_LONGITUD_CADENA],string nombrePartido);
};

#endif
