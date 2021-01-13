#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int delta_Kroneckera(double x, double x_F){
    return (fabs(x-x_F) < pow(10, -8)) ? 1 : 0;
}


void struna( double alfa, double beta, FILE* file1, FILE* file2){
    int nx = 150;
    int nt = 1000;

    double delta = 0.1;
    double delta_t = 0.05;
    double x_A = 7.5;
    double sigma = 0.5;



    double x_F = 2.5;
    double tmax = delta_t*nt;

    double u0[nx+1];
    double u [nx+1];
    double v [nx+1];
    double vp[nx+1];
    double a [nx+1];

    for(int i = 0; i < nx+1; i++){
        u0[i] = 0.0;
        u[i] = 0.0;
        v[i] = 0.0;
        vp[i] = 0.0;
        a[i] = 0.0;
    }

    if(alfa != 1.0){
     for(int i = 1; i <= nx-1; i++){
        u[i] = exp( -pow((delta*i)-x_A, 2) / (2.0*pow(sigma, 2)));
     }
    }

     for(int i = 0; i < nx+1; i++){
        u0[i] = u[i];
     }

     for(int i=1; i<=nx-1; i++){
        a[i] = ((u[i+1] - 2.0*u[i] + u[i-1]) / pow(delta, 2)) - (beta * ((u[i] - u0[i]) / delta_t)) + alfa*(cos( (50*0.0)/tmax) * delta_Kroneckera((delta*i), x_F));
    }

    for(int n=1; n<=nt; n++){
        for(int i=0; i<nx+1; i++){
            vp[i]=v[i] + (delta_t/2.0)*a[i];
        }
        for(int i = 0; i < nx+1; i++){
            u0[i] = u[i];
            u[i] = u[i] + delta_t * vp[i];
        }
        for(int i=1; i<=nx-1; i++){
            a[i] = ((u[i+1] - 2.0*u[i] + u[i-1]) / pow(delta, 2)) - (beta * ((u[i] - u0[i]) / delta_t)) + alfa*(cos(50.0*(delta_t*n) / tmax) * delta_Kroneckera((delta*i), x_F));
        }

        for(int i=0; i<nx+1; i++){
            v[i]=vp[i] + (delta_t/2.0)*a[i];
        }
        double E = 0.0;
        E = delta/4.0 * (pow((u[1] - u[0])/delta , 2) + pow((u[nx] - u[nx-1])/delta, 2));
        for(int i = 1; i <= nx-1; i++){
            E += delta/2.0 * (pow(v[i], 2) + pow(((u[i+1] - u[i-1])/(2*delta)) , 2));
        }

        for(int i = 0; i < nx+1; i++){
            fprintf(file1, "%g\t%g\n", delta_t*n, E);
        }
        for(int i = 0; i < nx+1; i++){
            fprintf(file2, "%g\t", u[i]);
        }
         fprintf(file2, "\n");
    }
}
int main()
{
    FILE* file1;
    file1 = fopen("E1.dat", "w");
    FILE* file2;
    file2 = fopen("u1.dat", "w");

    struna(0.0,0.0,file1, file2);

    FILE* file3;
    file3 = fopen("E2.dat", "w");
    FILE* file4;
    file4 = fopen("u2.dat", "w");

    struna(0.0,0.1,file3, file4);

    FILE* file5;
    file5 = fopen("E3.dat", "w");
    FILE* file6;
    file6 = fopen("u3.dat", "w");

    struna(0.0,1.0,file5, file6);

    FILE* file7;
    file7 = fopen("E4.dat", "w");
    FILE* file8;
    file8 = fopen("u4.dat", "w");

    struna(1.0,1.0,file7, file8);

    printf("Hello world!\n");
    return 0;
}
