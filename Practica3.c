#include "ami.h"
#include "ami_bmp.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <string.h>

void LotkaVolterra(float a, float b, float d, float e, float f, float P0,
                   float C0, float  *Presa, float *Cazador, float dt, int NIter){
    float Pant = P0, Pact, Cant = C0, Cact;
    int i=0;

    Presa[0] = P0;
    Cazador[0] = C0;
    Pact = Pant +(dt*((a-(b*Pant)-(d*Cant))*Pant));
    if(Pact < 0.5){
       Pact=0;
    };
    Cact = Cant +(dt*((-e+(f*Pant))*Cant));
    if(Cact < 0.5){
        Cact=0;
    };
    Pant = Pact;
    Cant = Cact;

    while((i<NIter)&& (Pact > 0.5) && (Cact > 0.5)){

        Pact = Pant +(dt*((a-(b*Pant)-(d*Cant))*Pant));
        if(Pact < 0.5){
                Pact=0;
        };
        Cact = Cant +(dt*((-e+(f*Pant))*Cant));
        if(Cact < 0.5){
                Cact=0;
        };
        Pant = roundf(Pact);
        Cant = roundf(Cact);
        i++;
	Presa[i] = roundf(Pact);
	Cazador[i] = roundf(Cact);
    }
};

int main() {
        int i;
	int NIter1 = 2000;
	float a1, b1, d1, e1, f1, P01, C01, Presa1[NIter1], Cazador1[NIter1], dt1;
	int NIter2 = 2000;
	float a2, b2, d2, e2, f2, P02, C02, Presa2[NIter2], Cazador2[NIter2], dt2;
	int NIter3 = 2000;
	float a3, b3, d3, e3, f3, P03, C03, Presa3[NIter3], Cazador3[NIter3], dt3;
	int NIter4 = 2000;
	float a4, b4, d4, e4, f4, P04, C04, Presa4[NIter4], Cazador4[NIter4], dt4;

        a1 = 0.5;
        b1 = 0.00005;
        d1 = 0.0001;
        e1 = 0.06;
        f1 = 0.00015;
        P01 = 1000;
        C01 = 100;
        dt1 = 0.1;
	LotkaVolterra (a1, b1, d1, e1, f1, P01, C01, Presa1, Cazador1, dt1, NIter1);

	LotkaVolterra (a2, b2, d2, e2, f2, P02, C02, Presa2, Cazador2, dt2, NIter2);
	LotkaVolterra (a3, b3, d3, e3, f3, P03, C03, Presa3, Cazador3, dt3, NIter3);
	LotkaVolterra (a4, b4, d4, e4, f4, P04, C04, Presa4, Cazador4, dt4, NIter4);

	FILE *fp1;
        fp1 = fopen ( "equilibrio.txt", "w+" );
        for (i = 0; i < NIter1; i++) {
             fprintf(fp1, "i, %s, %s \n", i, Presa1[i], Cazador1[i]);
        }
        fputs( cadena1, fp1 );
        fclose ( fp1 );

	FILE *fp2;
	char cadena2[] = "%s, %s \n", Presa2, Cazador2;
        fp2 = fopen ( "depre-muertos.txt", "r+" );
        fputs( cadena2, fp2 );
        fclose ( fp2 );

	FILE *fp3;
	char cadena3[] = "%s, %s \n", Presa3, Cazador3;
        fp3 = fopen ( "muertos.txt", "r+" );
        fputs( cadena3, fp3 );
        fclose ( fp3 );

	FILE *fp4;
	char cadena4[] = "%s, %s \n", Presa4, Cazador4;
        fp4 = fopen ( "grndes.txt", "r+" );
        fputs( cadena4, fp4 );
        fclose ( fp4 );
        return 0;
}


