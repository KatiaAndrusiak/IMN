#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define delta 0.01
#define nx 200
#define ny 90
#define i1 50
#define j1 55
#define m 1.0
#define ro 1.0
#define IT_MAX 20000


double y(int j){ return j * delta; }

void wb_psi(double psi[nx+1][ny+1], double Qwy, double Qwe){
    //brzeg A (wejście)
    for(int j = j1; j<=ny; j++){
        psi[0][j] = (Qwe/(2.0*m))*((pow(y(j),3)/3.0)-(pow(y(j),2)/2.0)*(y(j1)+y(ny)) + y(j)*y(j1)*y(ny));
    }
    //brzeg C (wyjście)
    for(int j= 0; j<=ny; j++){
        psi[nx][j] = (Qwy/(2.0*m))*((pow(y(j), 3)/3.0) - (pow(y(j), 2)/2.0)* y(ny))+(Qwe*pow(y(j1), 2)*(-y(j1)+3.0*y(ny)) )/(12.0 * m);
    }
    //brzeg B
    for(int i=1; i<=nx-1; i++){
        psi[i][ny]=psi[0][ny];
    }
    //brzeg D
    for(int i=i1; i<=nx-1; i++){
        psi[i][0]=psi[0][j1];
    }
    //brzeg E
    for(int j= 1; j<=j1; j++){
        psi[i1][j]=psi[0][j1];
    }
    //brzeg F
    for(int i=1; i<=i1; i++){
        psi[i][j1]=psi[0][j1];
    }

}

void wb_zeta(double zeta[nx+1][ny+1], double psi[nx+1][ny+1], double Qwy, double Qwe){
    // brzeg A (wejście)
    for(int j=j1; j<=ny; j++){
        zeta[0][j]=(Qwe/(2.0*m))*(2.0*y(j) - y(j1) -y(ny));
    }
    // brzeg C (wyjście)
    for(int j=0; j<=ny; j++){
        zeta[nx][j]=(Qwy/(2.0*m))*(2.0*y(j) - y(ny));
    }
    // brzeg B
    for(int i=1; i<=nx-1; i++){
        zeta[i][ny] = (2.0/pow(delta,2))*(psi[i][ny-1] - psi[i][ny]);
    }
    //brzeg D
    for(int i = i1+1; i<=nx-1; i++){
        zeta[i][0] = (2.0/pow(delta,2))*(psi[i][1] - psi[i][0]);
    }
    //brzeg E
    for(int j=1; j<=j1-1; j++){
        zeta[i1][j] = (2.0/pow(delta,2))*(psi[i1+1][j] - psi[i1][j]);
    }
    //brzeg F
    for(int i=1; i<=i1; i++){
        zeta[i][j1] = (2.0/pow(delta,2))*(psi[i][j1+1] - psi[i][j1]);
    }
    //wierzchołek E/F
    zeta[i1][j1]= (1.0/2.0)*(zeta[i1-1][j1]+zeta[i1][j1-1]);

}

void relaksacjaNS(double Qwe, FILE * file1, FILE * file2, FILE * file3, FILE * file4){

    double zeta[nx+1][ny+1];
    double psi[nx+1][ny+1];
    double u[nx+1][ny+1];
    double v[nx+1][ny+1];

    for(int i=0; i<=nx; i++){
        for(int j=0; j<=ny; j++){
            zeta[i][j]=0.0;
            psi[i][j]=0.0;
            u[i][j]=0.0;
            v[i][j]=0.0;
        }
    }
    double Qwy = Qwe*((pow(y(ny), 3) - pow(y(j1), 3) - 3.0*y(j1)*pow(y(ny),2) + 3.0* pow(y(j1),2)*y(ny))/(pow(y(ny),3)));
    double omega=0.0;
    wb_psi(psi,Qwy,Qwe);

    for(int it=1; it<IT_MAX; it++){
        if(it < 2000){
            omega = 0.0;
        }
        else{
            omega = 1.0;
        }
        for(int i =1; i<=nx-1; i++){
            for(int j=1; j<=ny-1; j++){
                if( i>i1 || j>j1){
                    psi[i][j] = (1.0/4.0)* (psi[i+1][j] + psi[i-1][j] + psi[i][j+1] + psi[i][j-1]- pow(delta,2)*zeta[i][j]);
                    zeta[i][j] = (1.0/4.0) *(zeta[i+1][j] + zeta[i-1][j] + zeta[i][j+1]+zeta[i][j-1]) - omega* (ro/(16.0*m))*((psi[i][j+1] - psi[i][j-1])*(zeta[i+1][j] -zeta[i-1][j]) - (psi[i+1][j] - psi[i-1][j])*(zeta[i][j+1]-zeta[i][j-1]));
                    u[i][j] =(psi[i][j+1] - psi[i][j-1])/(2.0*delta);
                    v[i][j] = -(psi[i+1][j] - psi[i-1][j])/(2.0*delta);
                }
                else{
                    u[i][j] = 0;
                    v[i][j] = 0;
                }
            }
        }
        wb_zeta(zeta,psi,Qwy,Qwe);
        double gama =0.0;
        int j2 =j1+2;

        for(int i =1; i<=nx-1; i++){
            gama += (psi[i+1][j2] + psi[i-1][j2] + psi[i][j2+1] + psi[i][j2-1] - 4.0*psi[i][j2] - pow(delta,2)*zeta[i][j2]);
        }
        if(it%500 == 0){
            printf("Qwe = %g, gamma=%g\n", Qwe, gama);
        }

    }
     for(int i=0; i<=nx; i++){
        for(int j=0; j<=ny; j++){
            fprintf(file1,"%g\t", psi[i][j]);
            fprintf(file2,"%g\t", zeta[i][j]);
            fprintf(file3,"%g\t", u[i][j]);
            fprintf(file4,"%g\t", v[i][j]);
        }
        fprintf(file1,"\n");
        fprintf(file2,"\n");
        fprintf(file3,"\n");
        fprintf(file4,"\n");
    }




}

int main()
{
    FILE * file1 =fopen("rel_psi_1000.dat", "w");
    FILE * file2 =fopen("rel_zeta_1000.dat", "w");
    FILE * file3 =fopen("rel_u_1000.dat", "w");
    FILE * file4 =fopen("rel_v_1000.dat", "w");
    relaksacjaNS(-1000.0, file1, file2, file3, file4);

    FILE * file12 =fopen("rel_psi_4000.dat", "w");
    FILE * file22 =fopen("rel_zeta_4000.dat", "w");
    FILE * file32 =fopen("rel_u_4000.dat", "w");
    FILE * file42 =fopen("rel_v_4000.dat", "w");
    relaksacjaNS(-4000.0, file12, file22, file32, file42);

    FILE * file13 =fopen("rel_psi_p4000.dat", "w");
    FILE * file23 =fopen("rel_zeta_p4000.dat", "w");
    FILE * file33 =fopen("rel_u_p4000.dat", "w");
    FILE * file43 =fopen("rel_v_p4000.dat", "w");
    relaksacjaNS(4000.0, file13, file23, file33, file43);
    printf("Hello world!\n");
    return 0;
}
