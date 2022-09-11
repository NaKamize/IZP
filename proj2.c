#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define I_0 1.e-12
#define U_T 25.8563e-12

//nastavenie ukazovatela konca stringu  na chybu na NULL
//funkcia prijma ako parameter ukazovatel na argument
//funckia z stringove argumentu vrati ciseldnu hodnotu v double
double prevodStringDouble(char* argument)
{
    char* ukazovatelKonca = NULL;

    double cislo  = strtod(argument, &ukazovatelKonca);

    if(*ukazovatelKonca != '\0')
    {
        fputs("Nezadal si hodnotu v double!",stderr);
        return 1;
    }
    return cislo;
}
// vyjadrena rovnica pomocou napatia U_P, U_0, R.
double vypocitaneUp(double U_p, double u_0, double R)
{
    return I_0 * (exp(U_p / U_T) - 1) - ((u_0 - U_p) / R);
}
// algoritmicka schema polenia intervalov ktora vracia prud i_p
double bisekcia(double u_0, double eps, double R)
{
    double a = 0;
    double b = u_0;
    double stred = (a + b) /2;
    int i = 0;
    while(fabs(vypocitaneUp(stred, u_0, R)) > eps)
    {
	if(i > 0){
		 stred = (a + b) /2;
	}

	printf("UP: %.25lf\n", fabs(vypocitaneUp(stred, u_0, R)));
        if (vypocitaneUp(stred, u_0, R) < 0)
        {
            a = stred;
        } else{
            b = stred;
        }

	i++;
    }return stred;
}

double diode (double u_0, double eps, double R)
{
 double U_p = u_0 - bisekcia(u_0, eps, R) * R;
return U_p;
}

int main(int argc, char* argv[])
{
    if(argc != 4)	// osetrenie poctu vstupov
    {
        fputs("Zadal si privela argumentov!", stderr);
        return 1;
    }
    // pretypovanie stringov z argumentu programu na double
    double  u_0 = prevodStringDouble(argv[1]);
    double  odporR = prevodStringDouble(argv[2]);
    double  eps = prevodStringDouble(argv[3]);
    if(u_0 < 0)
    {
	fputs("error: invalid arguments", stderr);
    }
// vypis vystupnych velicin
    double up = diode(u_0, eps, odporR);

    printf("Up = %g V\n", up);
    printf("Ip = %g A\n", u_0 - up);
    
    return 0;
}

