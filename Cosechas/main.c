//
//  main.c
//  Cosechas
//
//  Created by Adrian Zavala Coria on 09/01/22.
//

#include <stdio.h>
#include <stdlib.h>
#define NUMERO_MESES 12
#define LONGITUD_NOMBRE_MES 11
#define NUMERO_ESTADISTICAS 4

const int TOTAL_ANUAL_COSECHADO = 0;
const int PROMEDIO_MENSUAL_COSECHADO = 1;
const int MAYOR_MES_COSECHADO = 2;
const int MENOR_MES_COSECHADO = 3;

int leerNumero() {
    return rand() % 200;
}

void leerCosechas(int cosechas[NUMERO_MESES],char meses[NUMERO_MESES][LONGITUD_NOMBRE_MES]) {
    for (int i = 0; i < NUMERO_MESES; i++) {
        cosechas[i] = leerNumero();
        printf("%i - Cosecha del mes de %s:\t%i\n",(i + 1), meses[i], cosechas[i]);
    }
    
}

void calcularEstadisticas(int cosechas[NUMERO_MESES] ,int estadisticas[NUMERO_ESTADISTICAS]) {
    estadisticas[TOTAL_ANUAL_COSECHADO] = cosechas[0];
    estadisticas[MAYOR_MES_COSECHADO] = 0;
    estadisticas[MENOR_MES_COSECHADO] = 0;
    int mayorMesTonelaje = cosechas[0];
    int menorMesTonelaje = cosechas[0];
    for (int i = 1; i < NUMERO_MESES; i++) {
        estadisticas[TOTAL_ANUAL_COSECHADO] = estadisticas[TOTAL_ANUAL_COSECHADO] + cosechas[i];
        if (cosechas[i] >= mayorMesTonelaje) {
            estadisticas[MAYOR_MES_COSECHADO] = i;
            mayorMesTonelaje = cosechas[i];
        }
        if (cosechas[i] <= menorMesTonelaje) {
            estadisticas[MENOR_MES_COSECHADO] = i;
            menorMesTonelaje = cosechas[i];
        }
    }
    estadisticas[PROMEDIO_MENSUAL_COSECHADO] = estadisticas[TOTAL_ANUAL_COSECHADO] / NUMERO_MESES;
}

void generarLinea(int tonelaje, char mes[LONGITUD_NOMBRE_MES]) {
    int totalEspacios = 15 - LONGITUD_NOMBRE_MES;
    int totalAsteriscos = tonelaje / 5;
    char espacios[totalEspacios];
    char asteriscos[totalAsteriscos];
    for (int i = 0; i < totalEspacios; i++) {
        espacios[i] = ' ';
    }
    for (int i = 0; i < totalAsteriscos; i++) {
        asteriscos[i] = '*';
    }
    printf("%s%s:%s - %i\n", espacios, mes, asteriscos, tonelaje);
}

void imprimirGraficoMensual(int cosechas[NUMERO_MESES], char meses[NUMERO_MESES][LONGITUD_NOMBRE_MES]) {
    printf("\n-------------------------\n");
    printf("Cosecha mensual de trigo.\n");
    printf("-------------------------\n");
    
    
    for (int i = 0; i < NUMERO_MESES; i++) {
        generarLinea(cosechas[i], meses[i]);
    }
}

int main(int argc, const char * argv[]) {
    int cosechas[NUMERO_MESES];
    int estadisticas[NUMERO_ESTADISTICAS];
    char meses[NUMERO_MESES][LONGITUD_NOMBRE_MES] = {"enero", "febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre","diciembre"};
    
    printf("\n\n\nAplicación que genera estadísticas de la cosecha de trigo.\n");
    printf("Proporcione los datos de la cosecha mensual de trigo.\n\n");
    leerCosechas(cosechas, meses);
    calcularEstadisticas(cosechas, estadisticas);
    imprimirGraficoMensual(cosechas, meses);
    
    printf("\n\n\nTotal anual cosechado: %i\n", estadisticas[TOTAL_ANUAL_COSECHADO]);
    printf("Promedio mensual cosechado: %i\n", estadisticas[PROMEDIO_MENSUAL_COSECHADO]);
    printf("Mes de mayor cosecha: %s\n", meses[estadisticas[MAYOR_MES_COSECHADO]]);
    printf("Mes de menor cosecha: %s\n", meses[estadisticas[MENOR_MES_COSECHADO]]);
    
    return 0;
}


