
#include<iostream>
#include<math.h>

/* Tu je definirana taylorjeva vrsta arctan, spreminjamo lahko stopnjo vrste */
double taylor(double x, int n)
{
    double sum;
    double value = 0.0;
    for (int i=0; i<=n; i++)
    {
        sum=((pow(-1.0,i) * pow(x/2,(2.0*i+1.0))) / (2.0*i+1));
        value+=sum;
    }
    return value;
}


/* Tu se definira funkcija, ki jo želimo integrirati */
#define f(x) exp(3*x)*taylor(x,n)

using namespace std;
int main()
{
 float spodnja=0, zgornja = M_PI/4, integral=0.0, razmak, k;
 int i, stkorakov,n;

 /* Input */
 cout<<"Vnesite število razdelkov ";
 cin>>stkorakov;
 cout<<"Vnesite na koliko mest želite izračunati Taylorjevo vrsto arctan(x): ";
 cin>>n;

 /* Računanje */

 /* Določanje velikosti koraka */
 razmak = (zgornja - spodnja)/stkorakov;

 /* Računanje začetne vrednosti integrala (vrednost funkcije na začetku in koncu) */
 integral = f(spodnja) + f(zgornja);

 for(i=1; i<= stkorakov-1; i++)
 {
  k = spodnja + i*razmak;
  
  integral = integral + 2 * (f(k));
 }

integral = integral * razmak/2;

 cout<< endl<<"Vrednost integrala je: "<< integral;

 return 0;
}

