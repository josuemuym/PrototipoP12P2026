#include "partidosPoliticos.h"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

partidosPoliticos::partidosPoliticos()
{
    partido_1 = 0;
    partido_2 = 0;
    partido_3 = 0;
}

void partidosPoliticos::llamarCiclo()
{
    float matriz_partidos_1[NUMERO_PARTIDOS][NUMERO_RONDAS + 1];
    float matriz_partidos_2[NUMERO_PARTIDOS][NUMERO_RONDAS + 1];
    float matriz_partidos_3[NUMERO_PARTIDOS][NUMERO_RONDAS + 1];

    char opcion;
    bool repetir = true;

    char partidos[NUMERO_PARTIDOS][MAXIMA_LONGITUD_CADENA] = {"Libre", "Vamos", "Creo", "UNE", "Unidos"};

    do
    {
        system("cls");

        cout << "*** Votos de partidos politicos en 3 departamentos de Guatemala ***"
             << endl << endl;

        llenarMatriz(matriz_partidos_1);
        partido_1 = imprimirMatriz(matriz_partidos_1, partidos, "Departamento de Guatemala");

        llenarMatriz(matriz_partidos_2);
        partido_2 = imprimirMatriz(matriz_partidos_2, partidos, "Departamento de Escuintla");

        llenarMatriz(matriz_partidos_3);
        partido_3 = imprimirMatriz(matriz_partidos_3, partidos, "Departamento de Sacatepequez");

        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;

        if (opcion == 'n')
            repetir = false;

    } while (repetir);
}

int partidosPoliticos::busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void partidosPoliticos::llenarMatriz(float matriz[NUMERO_PARTIDOS][NUMERO_RONDAS + 1])
{
    int y, x;
    for (y = 0; y < NUMERO_PARTIDOS; y++)
    {
        float suma = 0;
        int calificacion = 0;

        for (x = 0; x < NUMERO_RONDAS; x++)
        {
            calificacion = busquedaAleatorios(MIN_CALIFICACION, 10000);
            suma += calificacion;
            matriz[y][x] = calificacion;
        }

        matriz[y][NUMERO_RONDAS] = suma;
    }
}

void partidosPoliticos::imprimirMatrizLinea()
{
    int x;
    cout << "+--------";
    for (x = 0; x < NUMERO_RONDAS + 1; x++)
    {
        cout << "+---------";
    }
    cout << "+\n";
}

float partidosPoliticos::imprimirMatriz(float matriz[NUMERO_PARTIDOS][NUMERO_RONDAS + 1],char partidos[NUMERO_PARTIDOS][MAXIMA_LONGITUD_CADENA],string nombrePartido)
{
    int y, x;

    float promedioMayor = matriz[0][NUMERO_RONDAS];
    float promedioMenor = matriz[0][NUMERO_RONDAS];
    int totalGeneral = 0;
    float promedioGeneral = 0;

    char partidoPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char partidoPromedioMenor[MAXIMA_LONGITUD_CADENA];
    memcpy(partidoPromedioMayor, partidos[0], MAXIMA_LONGITUD_CADENA);
    memcpy(partidoPromedioMenor, partidos[0], MAXIMA_LONGITUD_CADENA);

    cout << nombrePartido << endl;
    imprimirMatrizLinea();

    cout << setw(9) << "Partidos";
    for (x = 0; x < NUMERO_RONDAS; x++)
    {
        cout << setw(9) << "Ronda " << x + 1;
    }
    cout << setw(8) << "Total" << endl;
    imprimirMatrizLinea();

    for (y = 0; y < NUMERO_PARTIDOS; y++)
    {
        cout << "!" << setw(8) << partidos[y] << "!";

        for (x = 0; x < NUMERO_RONDAS; x++)
        {
            int calificacion = matriz[y][x];
            cout << setw(9) << calificacion << "!";
        }

        float total = matriz[y][NUMERO_RONDAS];
        totalGeneral += total;

        if (total > promedioMayor)
        {
            promedioMayor = total;
            memcpy(partidoPromedioMayor, partidos[y], MAXIMA_LONGITUD_CADENA);
        }
        if (total < promedioMenor)
        {
            promedioMenor = total;
            memcpy(partidoPromedioMenor, partidos[y], MAXIMA_LONGITUD_CADENA);
        }

        cout << setw(9) << (int)total << "!" << endl;
        imprimirMatrizLinea();
    }

    promedioGeneral = totalGeneral / NUMERO_PARTIDOS;

    cout << "Mayor numero de votos: " << setw(10) << partidoPromedioMayor
         << setw(10) << promedioMayor << endl;
    cout << "Menor numero de votos: " << setw(10) << partidoPromedioMenor
         << setw(10) << promedioMenor << endl;
    cout << "Promedio de votos    : " << setw(10) << promedioGeneral << endl << endl;

    return promedioGeneral;
}

partidosPoliticos::~partidosPoliticos()
{
    // destructor
}
