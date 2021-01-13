#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void rel_w( FILE *file, FILE *file2, FILE *file3, FILE *file4, FILE *file5, FILE *file6 ){
    double delta = 0.2;
    int nx =128;
    int ny = 128;
    double xmax = delta * nx;
    double ymax = delta * ny;

    double V[nx+1][ny+1];

    double S=0.0;
    double S_1=0.0;
        int it =0;
    double TOL = pow(10,-8);
    int k;



      for(int i = 0; i <= ny; i++){
            V[0][i] = sin(M_PI * (i * delta / ymax));
            V[nx][i] = sin(M_PI * (i * delta / ymax));
      }
      for(int i = 0; i <= nx; i++){
            V[i][0] = sin(2.0* M_PI * (i * delta / xmax));
            V[i][ny] = -sin(2.0* M_PI * (i * delta / xmax));
      }
      for( int i=1; i<nx; i++ ){
        for( int j=1; j<ny; j++ ){
            V[i][j] = 0.0;
        }
    }

    for(k = 16; k>=1; k/=2){
        do{

            for(int i = k; i <= nx-k; i+=k){
                for(int j = k; j<= ny-k; j+=k) {

                    V[i][j] = (1.0/4.0) * (V[i+k][j] + V[i-k][j] + V[i][j+k] + V[i][j-k]);
                }
            }

            S_1 = S;
            S=0.0;

            for(int i =0; i <= nx - k; i+=k){
                for(int j = 0; j <= ny - k; j+=k){
                    S += (pow(k*delta,2.0)/2.0) * (pow(((V[i+k][j]-V[i][j])/(2.0*k*delta) + (V[i+k][j+k] -V[i][j+k])/(2.0*k*delta)) , 2.0) + pow(((V[i][j+k]-V[i][j])/(2.0*k*delta) + (V[i+k][j+k] -V[i+k][j])/(2.0*k*delta)) , 2.0) );
                }
            }

            fprintf(file, "%d\t%g\n",it,S);
            it++;
        }while(fabs((S - S_1)/S_1) > TOL);
        fprintf(file, "\n");

        if( k != 1 ){
            for(int i = 0; i <= nx-k; i+=k){
                for(int j = 0; j <= ny-k; j+=k){
                    V[i+k/2][j+k/2] = 1.0/4.0 * (V[i][j]   + V[i+k][j] + V[i][j+k] + V[i+k][j+k]);
                    if( i+k != nx )
                        V[i+k][j+k/2] = 1.0/2.0 * (V[i+k][j] + V[i+k][j+k]);
                    if( j+k != ny )
                        V[i+k/2][j+k]   = 1.0/2.0 * (V[i][j+k] + V[i+k][j+k]);
                    if (j != 0)
                        V[i+k/2][j] = 1.0/2.0  * (V[i][j] + V[i+k][j]);
                    if (i != 0)
                        V[i][j+k/2] = 1.0/2.0  * (V[i][j] + V[i][j+k]);
                }
            }
        }
        for(int i=0; i <=nx; i+=k){
            for(int j=0; j<=ny; j+=k){
                if(k==16)
                    fprintf(file2, "%g\t",V[i][j]);
                if(k==8)
                    fprintf(file3, "%g\t",V[i][j]);
                if(k==4)
                    fprintf(file4, "%g\t",V[i][j]);
                if(k==2)
                    fprintf(file5, "%g\t",V[i][j]);
                if(k==1)
                    fprintf(file6, "%g\t",V[i][j]);

            }
            if(k==16)
                    fprintf(file2, "\n");
                if(k==8)
                    fprintf(file3, "\n");
                if(k==4)
                    fprintf(file4, "\n");
                if(k==2)
                    fprintf(file5, "\n");
                if(k==1)
                    fprintf(file6, "\n");
        }

    }
}

int main()
{
    FILE *file;
    file = fopen("rel_w.dat", "w");
    FILE *file2;
    file2 = fopen("rel_w_16.dat", "w");
    FILE *file3;
    file3 = fopen("rel_w_8.dat", "w");
    FILE *file4;
    file4 = fopen("rel_w_4.dat", "w");
    FILE *file5;
    file5 = fopen("rel_w_2.dat", "w");
    FILE *file6;
    file6 = fopen("rel_w_1.dat", "w");
    rel_w(file, file2, file3, file4, file5, file6);

    return 0;
}
