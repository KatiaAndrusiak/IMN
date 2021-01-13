#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void Eulera(FILE *dane, double delta_t){
    double lambda = -1;
    double tmin = 0;
    double tmax = 5;
    int n = (int)((tmax - tmin) / delta_t);
    double y[n+2];
    y[0] = 1;
    for( int i = 0; i < n; i++){
       y[i+1]=y[i] + delta_t*(lambda* y[i]);
      // printf( " %d \t %f \t %f \t %f \n", i+1,  y[i+1], exp(lambda*delta_t*(double)i),exp(lambda*delta_t*(double)i )- y[i+1] );
       fprintf(dane, "%f \t %f \t %f \t %g \n", (i )*delta_t,  y[i], exp(lambda*delta_t*(double)i), fabs(y[i]- exp(lambda*delta_t*(double)i )) );
    }
    // printf("\n\n\n");
}

void RK2(FILE *dane, double delta_t){
    double lambda = -1;
    double tmin = 0;
    double tmax = 5;
    int n =(tmax - tmin) / delta_t;
    double y[n+2];
    y[0] =1;
    for( int i = 0; i < n; i++){
        double k1 = lambda*y[i];
        double k2 = lambda*(y[i] + delta_t*k1);
        y[i+1]=y[i] + (delta_t/2.0)*(k1 + k2);

        //printf( " %d \t %f \t %f \t %f \n", i+1,  y[i+1], exp(lambda*delta_t*(double)i),exp(lambda*delta_t*i )- y[i+1] );
        fprintf(dane, "%f \t %f \t %f \t %g \n", (i )*delta_t,  y[i], exp(lambda*delta_t*(double)i),  fabs(y[i]- exp(lambda*delta_t*(double)i )));
    }
    // printf("\n\n\n");
}

void RK4(FILE *dane,  double delta_t){
    double lambda = -1;
    double tmin = 0;
    double tmax = 5;
    int n = (int)((tmax - tmin) / delta_t);
    double y[n + 2];
    y[0] = 1;
    for( int i = 0; i < n; i++){
        double k1 = lambda*y[i];
        double k2 = lambda*(y[i] + (delta_t/2)*k1);
        double k3 = lambda*(y[i] + (delta_t/2)*k2);
        double k4 = lambda*(y[i] + delta_t*k3);
        y[i+1]=y[i] + (delta_t/6.0)*(k1 + 2*k2 + 2*k3 +k4);

        //printf( " %d \t %f \t %f \t %f \n", i+1,  y[i+1], exp(lambda*delta_t*(double)i),exp(lambda*delta_t*(double)i )- y[i+1] );
        fprintf(dane, "%f \t %f \t %f \t %g \n", (i )*delta_t,  y[i], exp(lambda*delta_t*(double)i),  fabs(y[i] - exp(lambda*delta_t*(double)i )));

    }
   //  printf("\n\n\n");
}

double Vn(double Wv, double t){
return 10*sin(Wv*t);}


void  RRZ(FILE * dane, double idx){

    double delta_t = 0.0001;
    double R = 100;
    double L = 0.1;
    double C = 0.001;
    double w0= 1.0/(sqrt(L*C));
    double T0= (2*M_PI)/w0;
    double Wv = idx*w0;
    double tmin = 0;
    double tmax = 4*T0;

    int n = (tmax - tmin) / delta_t;

    double Q[n+2];
    double I[n+2];
    Q[0] = 0;
    I[0] = 0;

    for( int i = 0; i < n; i++){
        double k1_Q = I[i];
        double k1_I = ( Vn(Wv,i*delta_t) / L) - (1/(L*C)) * Q[i] - (R/L)*I[i];
        double k2_Q = I[i] + (delta_t/2)*k1_I;
        double k2_I = (Vn(Wv,(i + 0.5)*delta_t)/L) - (1/(L*C))*(Q[i] + (delta_t/2)*k1_Q) - (R/L)*(I[i] + (delta_t/2)*k1_I);
        double k3_Q = I[i]+(delta_t/2)*k2_I;
        double k3_I = (Vn(Wv,(i + 0.5)*delta_t)/L)-(1/(L*C))*(Q[i] + (delta_t/2)*k2_Q) - (R/L)*(I[i] + (delta_t/2)*k2_I);
        double k4_Q = I[i] + delta_t*k3_I;
        double k4_I = (Vn(Wv,(i + 1)*delta_t)/L) - (1/(L*C))*(Q[i] + delta_t*k3_Q) - (R/L)*(I[i] + delta_t*k3_I);
        Q[i+1] = Q[i] + (delta_t/6)*(k1_Q + 2*k2_Q + 2*k3_Q + k4_Q);
        I[i+1] = I[i] + (delta_t/6)*(k1_I + 2*k2_I + 2*k3_I + k4_I);

        //printf( " %d \t %f \t %f \n", i+1,  Q[i+1], I[i+1]);
        fprintf(dane, " %f \t %f \t %f \n", (i )*delta_t,  Q[i], I[i]);
    }
    printf("\n\n\n");

}

int main()
{

    double delta_t1 = 0.01;
    double delta_t2 = 0.1;
    double delta_t3 = 1.0;

    ////////////////////////////zad1
    FILE *dane1;
    dane1 = fopen("dane1.dat", "w");

    Eulera(dane1, delta_t1);
    Eulera(dane1, delta_t2);
    Eulera(dane1, delta_t3);

    fclose(dane1);

    ////////////////////////////zad2
    FILE *RK2_dat;
    RK2_dat = fopen("RK2.dat", "w");

    RK2(RK2_dat, delta_t1);
    RK2(RK2_dat, delta_t2);
    RK2(RK2_dat, delta_t3);

    fclose(RK2_dat);
   ///////////////////////////zad3
    FILE *RK4_dat;
    RK4_dat = fopen("RK4.dat", "w");

    RK4(RK4_dat, delta_t1);
    RK4(RK4_dat, delta_t2);
    RK4(RK4_dat, delta_t3);

    fclose(RK4_dat);

    //zad4
    FILE *RRZ_1, *RRZ_2, *RRZ_3, *RRZ_4;
    RRZ_1 = fopen("RRZ_1.dat", "w");
    RRZ_2 = fopen("RRZ_2.dat", "w");
    RRZ_3 = fopen("RRZ_3.dat", "w");
    RRZ_4 = fopen("RRZ_4.dat", "w");
    double idx1 = 0.5;
    double idx2 = 0.8;
    double idx3 = 1.0;
    double idx4 = 1.2;
    RRZ(RRZ_1, idx1);
    RRZ(RRZ_2, idx2);
    RRZ(RRZ_3, idx3);
    RRZ(RRZ_4, idx4);

    fclose(RRZ_1);
    fclose(RRZ_2);
    fclose(RRZ_3);
    fclose(RRZ_4);

    return 0;
}
