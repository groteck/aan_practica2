#include "ami.h"
#include "ami_bmp.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include <string.h>

void LotkaVolterra(float a, float b, float d, float e, float f, float P0,
                   float C0, float  *Presa, float *Cazador, float dt, int NIter){
    float Pant = P0, Pact, Cant = C0, Cact;
    int i;

    Presa[0] = P0;
    Cazador[0] = C0;
    Pact = Pant +(dt*((a-(b*Pant)-(d*Cant))*Pant));
    if(Pact < 0.5){
       Pact=0;
    }
    Cact = Cant +(dt*((-e+(f*Pant))*Cant));
    if(Cact < 0.5){
        Cact=0;
    }
    Pant = Pact;
    Cant = Cact;

    for (i = 0; i<NIter; i++) {
        Pact = Pant +(dt*((a-(b*Pant)-(d*Cant))*Pant));
        if(Pact < 0.5){
                Pact=0;
        }
        Cact = Cant +(dt*((-e+(f*Pant))*Cant));
        if(Cact < 0.5){
                Cact=0;
        }
        Pant = roundf(Pact);
        Cant = roundf(Cact);
	Presa[i] = Pant;
	Cazador[i] = Cant;
    }
}

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

        a2 = 0.5;
        b2 = 0.00005;
        d2 = 0.0001;
        e2 = 0.06;
        f2 = 0.00015;
        P02 = 1000;
        C02 = 100;
        dt2 = 0.1;

	LotkaVolterra (a2, b2, d2, e2, f2, P02, C02, Presa2, Cazador2, dt2, NIter2);

        a3 = 0.5;
        b3 = 0.00005;
        d3 = 0.0001;
        e3 = 0.06;
        f3 = 0.00015;
        P03 = 1000;
        C03 = 100;
        dt3 = 0.1;

	LotkaVolterra (a3, b3, d3, e3, f3, P03, C03, Presa3, Cazador3, dt3, NIter3);
        a4 = 0.5;
        b4 = 0.00005;
        d4 = 0.0001;
        e4 = 0.06;
        f4 = 0.00015;
        P04 = 1000;
        C04 = 100;
        dt4 = 0.1;

	LotkaVolterra (a4, b4, d4, e4, f4, P04, C04, Presa4, Cazador4, dt4, NIter4);

	FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	FILE *fp4;
        fp1 = fopen ( "equilibrio.txt", "w+" );
        for (i = 0; i < NIter1; i++) {
             fprintf(fp1, "%d, %f, %f \n", i, Presa1[i], Cazador1[i]);
        }
        fclose( fp1 );

        for (i = 0; i < NIter2; i++) {
             fprintf(fp2, "i, %s, %s \n", i, Presa2[i], Cazador2[i]);
        }

        fclose ( fp2 );
        for (i = 0; i < NIter3; i++) {
             fprintf(fp3, "i, %s, %s \n", i, Presa3[i], Cazador3[i]);
        }

        fclose ( fp3 );

        for (i = 0; i < NIter4; i++) {
             fprintf(fp4, "i, %s, %s \n", i, Presa4[i], Cazador4[i]);
        }
        fclose ( fp4 );
        return 0;
}
