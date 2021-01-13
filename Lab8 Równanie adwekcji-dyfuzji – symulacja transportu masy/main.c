#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define nx 400
#define ny 90
#define i1 200
#define i2 210
#define j1 50
#define delta 0.01
#define sigma 10*delta
#define xa 0.45
#define ya 0.45
#define IT_MAX 10000

void ad(double D,   FILE *file3, FILE *file4){
    double u0 [nx+1][ny+1];
    double u1 [nx+1][ny+1];
    double vx [nx+1][ny+1];
    double vy [nx+1][ny+1];
    double psi[nx+1][ny+1];
    FILE *file1;
    file1 = fopen("vx.dat","w");
    FILE *file2;
    file2 = fopen("vy.dat","w");

    FILE *file;
    file = fopen("psi.dat","r");
    if(!file){
        perror("Error opening file");
        return;
    }
    int i, j;
    double ps;
    while(fscanf(file, "%d%d%lf", &i, &j, &ps) == 3) {
        psi[i][j]=ps;
    }

    printf("start v");
    //Pole predkosci
    for(int i = 1; i<=nx-1; i++){
        for(int j = 1; j<=ny-1; j++){
            vx[i][j] = (psi[i][j+1] - psi[i][j-1])/(2.0*delta);
            vy[i][j] = - (psi[i+1][j] - psi[i-1][j])/(2.0*delta);
        }
    }

    for(int i = i1; i <= i2; i++){
        for(int j = 0; j <= j1; j++){
            vx[i][j] = 0.0;
            vy[i][j] = 0.0;
        }
    }

    for(int i = 1; i <= nx-1; i++){
        vx[i][0] = 0.0;
        vy[i][ny] = 0.0;
    }
    for(int j = 0; j <=ny; j++){
        vx[0][j] = vx[1][j];
        vx[nx][j] = vx[nx-1][j];
    }

    for(int i = 0; i<=nx; i++){
        for(int j = 0; j<=ny; j++){
            fprintf(file1,"%g\t",vx[i][j]);
            fprintf(file2,"%g\t",vy[i][j]);
        }
         fprintf(file1,"\n");
         fprintf(file2,"\n");
    }
    printf("start vmax\n");

    //v max
    double v_max = 0.0;
    for(int i = 0; i <= nx; i++){
        for(int j = 0; j <= ny; j++){

            if(sqrt(pow(vx[i][j], 2) + pow(vy[i][j], 2)) > v_max)
                v_max = sqrt(pow(vx[i][j], 2) + pow(vy[i][j], 2));
        }
    }

    double delta_t = delta/(4.0*v_max);
    printf("%g\t%g\n",v_max,delta_t);

    //u0

    for(int i = 0; i <= nx; i++){
        for(int j = 0; j <= ny; j++)
            u0[i][j] = 1.0/(2.0*M_PI*pow(sigma, 2)) * exp( -(pow((delta*i) - xa, 2) + pow((delta*j) - ya, 2))/(2.0*pow(sigma, 2)));
    }


    //
    printf("start it");
    for(int it = 0; it <= IT_MAX; it++){
        for(int i = 0; i <= nx; i++){
            for(int j = 0; j <= ny; j++){
                u1[i][j] = u0[i][j];
            }
        }


        for(int k = 1; k <= 20; k++){
            for(int i = 0; i <= nx; i++){
                for(int j = 1; j <= ny-1; j++){
                    if(i<i1 || i>i2 || j>j1){
                        if(i==0){
                            u1[i][j] = (1.0/(1.0+((2.0*D*delta_t) / pow(delta, 2)))) * (u0[i][j] - (delta_t/2.0) * vx[i][j] *
                            (((u0[i+1][j] - u0[nx][j])/(2.0*delta)) + (u1[i+1][j] - u1[nx][j])/(2.0*delta)) - (delta_t / 2.0) * vy[i][j] *
                             ((u0[i][j+1] - u0[i][j-1])/(2.0*delta) + (u1[i][j+1] - u1[i][j-1])/(2.0*delta)) + (delta_t/2.0) * D *
                             ((u0[i+1][j] + u0[nx][j] + u0[i][j+1] + u0[i][j-1] - 4.0*u0[i][j])/pow(delta,2) + (u1[i+1][j] + u1[nx][j] + u1[i][j+1] + u1[i][j-1] )/pow(delta,2)));
                        }
                        else if(i==nx){
                            u1[i][j] = (1.0/(1.0+( (2.0*D*delta_t) / pow(delta, 2)))) * (u0[i][j] - (delta_t/2.0) * vx[i][j] *
                            (((u0[0][j] - u0[i-1][j])/(2.0*delta)) + (u1[0][j] - u1[i-1][j])/(2.0*delta)) - (delta_t / 2.0) * vy[i][j] *
                             ((u0[i][j+1] - u0[i][j-1])/(2.0*delta) + (u1[i][j+1] - u1[i][j-1])/(2.0*delta)) + (delta_t/2.0) * D *
                             ((u0[0][j] + u0[i-1][j] + u0[i][j+1] + u0[i][j-1] - 4.0*u0[i][j])/pow(delta,2) + (u1[0][j] + u1[i-1][j] + u1[i][j+1] + u1[i][j-1])/pow(delta,2)));
                        }
                        else{
                            u1[i][j] = (1.0/(1.0+((2.0*D*delta_t )/ pow(delta, 2)))) * (u0[i][j] - (delta_t/2.0) * vx[i][j] *
                            (((u0[i+1][j] - u0[i-1][j])/(2.0*delta)) + (u1[i+1][j] - u1[i-1][j])/(2.0*delta)) - (delta_t / 2.0) * vy[i][j] *
                            ((u0[i][j+1] - u0[i][j-1] )/(2.0*delta) + (u1[i][j+1] - u1[i][j-1])/(2.0*delta)) + (delta_t/2.0) * D *
                            ((u0[i+1][j] + u0[i-1][j] + u0[i][j+1] + u0[i][j-1] - 4.0*u0[i][j])/pow(delta,2) + (u1[i+1][j] + u1[i-1][j] + u1[i][j+1] + u1[i][j-1])/pow(delta,2)));
                        }
                    }
                }
            }

        }

        for(int i = 0; i <= nx; i++){
            for(int j = 0; j <= ny; j++){
                u0[i][j] = u1[i][j];
            }
        }

        double c=0.0;
        double x_sr=0.0;
        for(int i = 0; i <= nx; i++){
            for(int j = 0; j <=ny; j++){
                c += u0[i][j];
                x_sr += (i*delta) * u0[i][j];
            }
        }
        c *= pow(delta, 2);
		x_sr *= pow(delta, 2);
        fprintf(file3, "%g\t%g\t%g\n",delta_t*it, c, x_sr);

        if(it%700==0 && it<=3500){
             for (int l = 0; l <= nx; l++) {
                for (int m = 0;m <= ny; m++) {
                    fprintf(file4,"%g\t",u1[l][m]);
                }
                fprintf(file4,"\n");
            }
             fprintf(file4,"\n\n\n");
          }
    }
     printf("end it");

    fclose(file1);
    fclose(file2);
    fclose(file);

}

int main()
{
    FILE *file3;
    file3 = fopen("c_xsr.dat","w");
    FILE *file4;
    file4 = fopen("map.dat","w");
    FILE *file5;
    file5 = fopen("c_xsr_2.dat","w");
    FILE *file6;
    file6 = fopen("map2.dat","w");
    ad(0.0, file3, file4);
    ad(0.1, file5, file6);

    fclose(file3);
    fclose(file4);
    fclose(file5);
    fclose(file6);
    printf("Hello world!\n");
    return 0;
}
