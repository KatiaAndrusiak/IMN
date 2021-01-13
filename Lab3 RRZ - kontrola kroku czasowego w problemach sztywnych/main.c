#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

 double g(double alfa, double xn, double vn){
    return alfa * (1 - pow(xn,2))*vn - xn;
 }


void trapez( double xn, double vn, double dt, double alfa, double *x_res, double *v_res){
    double TOL = pow(10, -10);
    double xn1 = xn;
    double vn1 = vn;
    double dx = 0.0;
    double dv = 0.0;
    do{
        double a11 = 1;
        double a12 = - dt/2.0;
        double a21 = - (dt/2.0) * (-2 * alfa * xn1 * vn1 - 1);
        double a22 = 1 - (dt/2.0)* alfa * (1 - pow(xn1, 2));

        double F = xn1 - xn - (dt/2.0)*( vn +  vn1);
        double G = vn1 - vn - (dt/2.0)*(g(alfa, xn, vn) + g(alfa, xn1, vn1));

        dx = (-F * a22 - (-G) * a12) /(a11 * a22 - a12 * a21);
        dv = (a11 * (-G) - a21 * (-F)) / (a11 * a22 - a12 * a21);

        xn1 += dx;
        vn1 += dv;

     }while (fabs(dx) < TOL && fabs(dv) < TOL);

    *x_res = xn1;
    *v_res = vn1;
}

void rk2( double xn, double vn, double dt, double alfa, double *xn1, double *vn1){
    double k1x, k1v, k2x, k2v;
     k1x = vn;
     k1v = alfa * (1.0 - pow(xn,2)) * vn - xn;

     k2x = vn + dt * k1v;
     k2v = alfa * (1.0 - pow((xn + dt * k1x),2)) * (vn + dt * k1v) - (xn + dt * k1x);

    *xn1 = xn + (dt/2.0)*(k1x + k2x);
    *vn1 = vn + (dt/2.0)*(k1v + k2v);
}

void step_control( void (*fun)(double, double, double, double, double*, double*), double TOL, FILE *file){
    double x0 = 0.01;
    double v0 = 0.0;
    double dt0 = 1.0;
    double S = 0.75;
    int p = 2;
    double tmax = 40;
    double alfa = 5;

    double t = 0.0;
    double dt = dt0;
    double xn = x0;
    double vn = v0;

    double xn12, vn12, xn22, vn22, xn21, vn21;
    double Ex, Ev, maxE;
    do{
        fun(xn, vn, dt, alfa, &xn12, &vn12);
        fun(xn12, vn12, dt, alfa, &xn22, &vn22);

        fun(xn, vn, 2.0*dt, alfa, &xn21, &vn21);

        Ex = (xn22 - xn21)/(pow(2.0 ,p) - 1.0);
        Ev = (vn22 - vn21)/(pow(2.0 ,p) - 1.0);
        maxE = MAX(fabs(Ex),fabs(Ev));
        if(maxE < TOL){
            t = t + 2.0*dt;
            xn = xn22;
            vn = vn22;
            fprintf(file,"%g\t%g\t%g\t%g\n",t, dt, xn,vn);
        }
        dt = pow( ((S*TOL) / maxE), 1.0/((double)p + 1) ) * dt;
    }while(t < tmax);

}


int main()
{

    double TOL1 = pow(10, -2);
    double TOL2 = pow(10, -5);

    FILE *trapez1;
	trapez1 = fopen("trapez1.dat", "w");
    FILE *trapez2;
    trapez2 = fopen("trapez2.dat", "w");

    step_control(trapez, TOL1, trapez1);
    step_control(trapez, TOL2, trapez2);

    FILE *rk2_1;
	rk2_1 = fopen("rk2_1.dat", "w");
    FILE *rk2_2;
    rk2_2 = fopen("rk2_2.dat", "w");

    step_control(rk2, TOL1, rk2_1);
    step_control(rk2, TOL2, rk2_2);

    fclose(trapez1);
    fclose(trapez2);
    fclose(rk2_1);
    fclose(rk2_2);
    return 0;
}
