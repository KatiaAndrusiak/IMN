#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void Picarda(FILE * file){
    double beta = 0.001;
    int N =500;
    double gamma = 0.1;
    int tmax = 100;
    double delta_t = 0.1;
    double u0 =1;
    double TOL = 10e-7;
    double alfa = beta*N - gamma;
    int n = tmax/delta_t;
    double un1=0.0;
    double un=u0;
    double unm =u0;
    for(int i = 0;  i < n; i++){
        for(int m = 0; m <= 20; m++){
            un1 = un + (delta_t/2)*((alfa*un-beta*un*un)+ (alfa*unm - beta*unm*unm));
            if(fabs(un1 - unm)< TOL) break;
            else{
                unm = un1;
            }
        }
        un = un1;
        unm = un1;
        fprintf(file,"%.2f\t%f\t%f\n", i*delta_t, un, N - un);
    }
}

void Newtona(FILE * file){
    double beta = 0.001;
    int N =500;
    double gamma = 0.1;
    int tmax = 100;
    double delta_t = 0.1;
    double u0 =1;
    double TOL = 10e-7;
    double alfa = beta*N - gamma;
    int n = tmax/delta_t;
    double un1=0.0;
    double un=u0;
    double unm =u0;
    for(int i = 0;  i < n; i++){
        for(int m = 0; m <= 20; m++){
            un1 = unm - ((unm - un - (delta_t/2)*((alfa*un-beta*un*un)+ (alfa*unm - beta*unm*unm)))/(1 - (delta_t/2)*(alfa - 2*beta*unm)));
            if(fabs(un1 - unm)< TOL) break;
            else{
                unm = un1;
            }
        }
        un = un1;
        unm = un1;
        fprintf(file,"%.2f\t%f\t%f\n", i*delta_t, un, N - un);
    }
}
double f(double u){
    double beta = 0.001;
    int N =500;
    double gamma = 0.1;
    return (beta*N - gamma)*u - beta*u*u;
}
void RK2(FILE * file){
    double beta = 0.001;
    int N =500;
    double gamma = 0.1;
    int tmax = 100;
    double delta_t = 0.1;
    double u0 =1.0;
    double TOL = 10e-7;
    double alfa = beta*N - gamma;
    int n = tmax/delta_t;
   double b1 = 0.5;
    double b2 = 0.5;
    double a11 = 0.25;
    double a12 = 0.25 - sqrt(3)/6.0;
    double a21 = 0.25 + sqrt(3)/6.0;
    double a22 = 0.25;
    double m11, m12, m21, m22;
    double F1, F2;
    double U1 = u0;
    double U2 = u0;
    double dU1 = 0.0;
    double dU2 = 0.0;
    double un = u0;
    double umn = 0.0;
    double Um1 = 0.0;
    double Um2 = 0.0;
    for( int i = 0; i < n; i++)
    {
        F1 = U1 - un - delta_t * (a11 * (alfa * U1 - beta * pow(U1,2) + a12 * (alfa * U2 - beta * pow(U2,2))));
        F2 = U2 - un - delta_t * (a21 * (alfa * U1 - beta * pow(U1,2) + a22 * (alfa * U2 - beta * pow(U2,2))));

        m11 = 1 - delta_t * a11 * (alfa - 2 * beta * U1);
        m12 = - delta_t * a12 * (alfa - 2 * beta * U2);
        m21 = - delta_t * a21 * (alfa - 2 * beta * U1);
        m22 = 1 - delta_t * a22 * (alfa - 2 * beta * U2);

        dU1 = (F2 * m12 - F1 * m22)/(m11 * m22 - m12 * m21);
        dU2 = (F1 * m21 - F2 * m11)/(m11 * m22 - m12 * m21);

        for( int m = 0; m <= 20; m++)
        {
            Um1 = U1 + dU1;
            Um2 = U2 + dU2;
            if(fabs(Um1 - U1) < TOL || fabs(Um2 - U2) < TOL) break;
            else{
                U1 = Um1;
                U2 = Um2;
            }
        }
        umn = un + delta_t * (b1 * f(U1) + b2 * f(U2));
        un = umn;
        U1 = un;
        U2 = un;
        fprintf(file,"%.2f\t%g\t%g\n", i*delta_t, un, N - un);

    }

}



int main()
{
    FILE * picarda, *newtona, *rk2;
    picarda = fopen("picarda.dat","w");
    newtona = fopen("newtona.dat", "w");
    rk2 = fopen("rk2.dat","w");

    Picarda(picarda);
    Newtona(newtona);
    RK2(rk2);
    return 0;
}
