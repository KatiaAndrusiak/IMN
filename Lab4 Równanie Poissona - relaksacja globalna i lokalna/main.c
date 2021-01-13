#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Ro(double i, double j, double delta, double xmax, double sigmax, double ymax, double sigmay){
    double ro_1 =     exp( - (pow((i * delta - 0.35 * xmax), 2.0)/ pow(sigmax, 2.0)) - (pow((j * delta - 0.5 * ymax), 2.0)/ pow(sigmay, 2.0)));
    double ro_2 =(-1.0)*exp( - (pow((i * delta - 0.65 * xmax), 2.0)/ pow(sigmax, 2.0)) - (pow((j * delta - 0.5 * ymax), 2.0)/ pow(sigmay, 2.0)));
    return ro_1 + ro_2;
}

void rel_gl(double wg, FILE *file){
    double eps = 1.0;
    double delta = 0.1;
    int nx =150;
    int ny = 100;
    double V1 = 10.0;
    double V2 = 0.0;
    double xmax = delta * nx;
    double ymax = delta * ny;
    double sigmax = 0.1 * xmax;
    double sigmay = 0.1 * ymax;
    double Vn[nx+1][ny+1];
    double Vs[nx+1][ny+1];
    double ro =0.0;
    double S=0.0;
    double S_1=0.0;
    int it =0;
    double TOL = pow(10,-8);

      for(int i = 0; i <= nx; i++){
        for(int j = 0; j <= ny; j++) {
            Vn[i][j] = 0.0;
            Vs[i][j] = 0.0;
        }
      }
      for(int i = 0; i <= nx; i++){
            Vn[i][0] = V1;
            Vs[i][0] = V1;
            Vn[i][ny] = V2;
            Vs[i][ny] = V2;
      }


      do{
        for(int i = 1; i < nx; i++){
            for(int j = 1; j < ny; j++) {
                ro = Ro( i,  j,  delta,  xmax,  sigmax,  ymax,  sigmay);
                Vn[i][j] = (1.0/4.0) * (Vs[i+1][j] + Vs[i-1][j] + Vs[i][j+1] + Vs[i][j-1] + (pow(delta,2.0)/eps)* ro);
            }
        }
        for(int j = 1; j < ny; j++) {
            Vn[0][j] =  Vn[1][j];
            Vn[nx][j] = Vn[nx-1][j];
        }

        for(int i = 0; i <= nx; i++){
            for(int j = 1; j < ny; j++) {
                Vs[i][j] = (1.0 - wg) * Vs[i][j] + wg * Vn[i][j];
            }
        }

        S_1 = S;
        S=0.0;
        ro = 0.0;
        for(int i =0; i < nx; i++){
            for(int j = 0; j < ny; j++){
                ro = Ro( i,  j,  delta,  xmax,  sigmax,  ymax,  sigmay);
                S += pow(delta,2.0) * ( (1.0/2.0) * pow(((Vs[i+1][j] - Vs[i][j])/delta), 2.0) + (1.0/2.0) * pow(((Vs[i][j+1] - Vs[i][j])/delta), 2.0) - ro * Vs[i][j] );
            }
        }

        //fprintf(file, "%d\t%g\n",it,S);
        it++;
    }while(fabs((S - S_1)/S_1) > TOL);
    printf("dfrgty\n");
    double bled[nx+1][ny+1];
    for(int i = 0; i <= nx; i++){
        for(int j = 0; j <= ny; j++) {
            bled[i][j] = 0.0;
        }
    }
    for(int i=1; i<nx; i++){
        for(int j=1; j<ny; j++){
            ro = Ro( i,  j,  delta,  xmax,  sigmax,  ymax,  sigmay);
            bled[i][j]= ((Vn[i+1][j] - 2*Vn[i][j] + Vn[i-1][j])/(pow(delta,2)) + (Vn[i][j+1] - 2*Vn[i][j] + Vn[i][j-1])/(pow(delta,2)) ) + (ro/eps);
            printf( "%g\t",bled[i][j]);
            fprintf(file, "%g\t",bled[i][j]);
        }
         fprintf(file, "\n");
         printf( "\n");
    }
}

void rel_lok(double wl, FILE *file){
    double eps = 1.0;
    double delta = 0.1;
    int nx =150;
    int ny = 100;
    double V1 = 10.0;
    double V2 = 0.0;
    double xmax = delta * nx;
    double ymax = delta * ny;
    double sigmax = 0.1 * xmax;
    double sigmay = 0.1 * ymax;
    double V[nx+1][ny+1];
    double ro =0.0;
    double S=0.0;
    double S_1=0.0;
        int it =0;
    double TOL = pow(10,-8);
      for(int i = 0; i <= nx; i++){
        for(int j = 0; j <= ny; j++) {
            V[i][j] = 0.0;
        }
      }
      for(int i = 0; i <= nx; i++){
            V[i][0] = V1;
            V[i][ny] = V2;
      }
    do{

        for(int i = 1; i < nx; i++){
            for(int j = 1; j < ny; j++) {
                ro = Ro( i,  j,  delta,  xmax,  sigmax,  ymax,  sigmay);
                V[i][j] = (1 - wl) * V[i][j] + (wl/4.0) * (V[i+1][j] + V[i-1][j] + V[i][j+1] + V[i][j-1] + (pow(delta,2)/eps) * ro);
            }
        }
            for(int j = 1; j < ny; j++) {
                V[0][j] =  V[1][j];
                V[nx][j] = V[nx-1][j];
            }

        S_1 = S;
        S=0.0;
        ro = 0.0;
        for(int i =0; i < nx; i++){
            for(int j = 0; j < ny; j++){
                ro = Ro( i,  j,  delta,  xmax,  sigmax,  ymax,  sigmay);
                S += pow(delta,2.0) * ( (1.0/2.0) * pow(((V[i+1][j] - V[i][j])/delta), 2.0) + (1.0/2.0) * pow(((V[i][j+1] - V[i][j])/delta), 2.0) - ro * V[i][j] );
            }
        }

        fprintf(file, "%d\t%g\n",it,S);
        it++;
    }while(fabs((S - S_1)/S_1) > TOL);
}

int main()
{
    //FILE *glob1;
    FILE *glob2;
   // glob1 = fopen("glob1_matrix.dat", "w");
	glob2 = fopen("glob2_matrix.dat", "w");
	//glob1 = fopen("glob1.dat", "w");
	//glob2 = fopen("glob2.dat", "w");
    //rel_gl(0.6, glob1);
   rel_gl(1.0, glob2);

   /* FILE *lok1;
    FILE *lok2;
    FILE *lok3;
    FILE *lok4;
    lok1 = fopen("lok1.dat", "w");
    lok2 = fopen("lok2.dat", "w");
    lok3 = fopen("lok3.dat", "w");
    lok4 = fopen("lok4.dat", "w");
    rel_lok(1.0, lok1);
    rel_lok(1.4, lok2);
    rel_lok(1.8, lok3);
    rel_lok(1.9, lok4); */

    return 0;
}
