# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include "mgmres.c"

void pois( int nx, int ny,double eps1, double eps2, double v1, double v2, double v3, double v4, double ro1, double ro2, FILE* file1,FILE* file2,FILE* file3){
    double delta = 0.1;
    int N = (nx + 1) * (ny + 1);
    int i = 0;
    int j = 0;

    int nz_num = 0;

    int ia [N+1];
    int ja [5*N];
    double a [5*N];
    double V [N];
    double b [N];

    int itr_max=500;
    int mr=500;
    double tol_abs = pow(10,-8);
    double tol_rel = pow(10,-8);

    double epsL[N];

    double sigma = (delta*nx)/10;

    for(int c=0; c<N; c++){
        V[c]=0.0;
        b[c] =0.0;

    }

    for(int c = 0; c < N+1; c++){
        ia[c] = -1;
    }

    int k = -1;

     for(int l = 0; l < N; l++){
        j = l/(nx+1);
        i = l-j*(nx+1);

        if (i <= nx / 2)
            epsL[l] = eps1;
        else
            epsL[l] = eps2;
     }

    for(int l = 0; l < N; l++){
        j = (int)(l/(nx+1));
        i = l-j*(nx+1);

        int brzeg = 0;
        double vb = 0;
        if(i == 0){
            brzeg = 1;
            vb = v1;
        }
        if(j == ny){
            brzeg = 1;
            vb = v2;
        }

        if(i == nx){
            brzeg = 1;
            vb = v3;
        }

        if(j == 0){
            brzeg = 1;
            vb = v4;
        }
        double ro=0.0;
       if( ro1 == -1.0 && ro2 ==-1.0){
          ro = exp(-(pow(delta*i - 0.25*delta*nx, 2)/pow(sigma,2))- (pow(delta*j - 0.5*delta*ny, 2)/pow(sigma,2)))+
          (-exp(-(pow(delta*i - 0.75*delta*nx, 2)/pow(sigma,2))- (pow(delta*j - 0.5*delta*ny, 2)/pow(sigma,2)))) ;
        }
        else{
            ro=ro1+ro2;
        }

        b[l]= -ro;


        if(brzeg == 1){
            b[l] =  vb;
        }

        ia[l] = -1;

        if(l - nx - 1 >=0 && brzeg ==0){
            k++;
            if(ia[l]<0) ia[l] =k;
            a[k]= epsL[l]/pow(delta,2);
            ja[k] = l - nx - 1;
        }

        if(l-1 >= 0 && brzeg == 0){
            k++;
            if(ia[l]<0) ia[l]=k;
            a[k]= epsL[l]/pow(delta,2);
            ja[k] = l - 1;
        }

        k++;
        if(ia[l]<0) ia[l]=k;
        if(brzeg ==0){
            a[k] = -(2*epsL[l] + epsL[l+1]+ epsL[l+nx+1])/pow(delta,2);
        }
        else{
            a[k]=1;
        }

        ja[k] = l;

        if(l < N && brzeg == 0){
            k++;
            a[k] = epsL[l+1]/pow(delta,2);
            ja[k] = l+1;
        }


        if(l< N -nx -1 && brzeg ==0){
            k++;
            a[k] = epsL[l+nx+1]/pow(delta,2);
            ja[k] = l + nx +1;
        }
        if(fabs(a[l]) > pow(10,-10))
        fprintf(file1, "%d\t%d\t%d\t%g\n",l,i,j,a[l]);
        if(fabs(b[l]) > pow(10,-10))
        fprintf(file2, "%d\t%d\t%d\t%g\n",l,i,j,b[l]);
    }
    fprintf(file2, "\n\n\n");
    fprintf(file1, "\n\n\n");

    nz_num = k+1;
    ia[N] = nz_num;


    pmgmres_ilu_cr(N, nz_num, ia, ja, a, V, b, itr_max, mr, tol_abs, tol_rel);

    for(int l = 0; l < N; l++){

        fprintf(file3, "%g\t", V[l]);
        if((l+1)%(nx+1) == 0){
            fprintf(file3, "\n");
        }
     }
}

int main()
{

    FILE* file_A;
    file_A = fopen("macierzA_4.dat", "w");
    FILE* file_b;
    file_b = fopen("vektorb_4.dat", "w");
    FILE* file_V;
    file_V = fopen("v_4.dat", "w");

    pois(4,4,1.0,1.0,10,-10,10,-10,0.0,0.0, file_A, file_b, file_V );
    fclose(file_V);

    FILE* file_V50;
    file_V50= fopen("V_50.dat", "w");
    pois(50,50,1.0,1.0,10,-10,10,-10,0,0, file_A, file_b, file_V50);
    fclose(file_V50);

    FILE* file_V100;
    file_V100= fopen("V_100.dat", "w");
    pois(100,100,1.0,1.0,10,-10,10,-10,0,0, file_A, file_b, file_V100);
    fclose(file_V100);
    FILE* file_V200;
    file_V200= fopen("V_200.dat", "w");
    pois(200,200,1.0,1.0,10,-10,10,-10,0,0, file_A, file_b, file_V200);
    fclose(file_V200);


    FILE* file_V11;
    file_V11= fopen("V_eps1.dat", "w");
    pois(100,100,1.0,1.0,0.0,0.0,0.0,0.0,-1.0,-1.0, file_A, file_b, file_V11);
    fclose(file_V11);

    FILE* file_V12;
    file_V12= fopen("V_eps2.dat", "w");
    pois(100,100,1.0,2.0,0,0,0,0,-1.0,-1.0, file_A, file_b, file_V12);
    fclose(file_V12);

    FILE* file_V110;
    file_V110= fopen("V_eps3.dat", "w");
    pois(100,100,1.0,10.0,0,0,0,0,-1.0,-1.0, file_A, file_b, file_V110);
    fclose(file_V110);

    fclose(file_A);
    fclose(file_b);




    return 0;
}
