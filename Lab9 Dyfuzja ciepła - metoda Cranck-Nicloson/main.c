#include </usr/include/gsl/gsl_math.h>
#include </usr/include/gsl/gsl_linalg.h>
#include </usr/include/gsl/gsl_blas.h>
#include <stdio.h>
#include <math.h>


void dyf()
{

     int nx = 40;
     int ny = 40;
     int N = (nx + 1) * (ny + 1);
     double delta = 1.0;
     double delta_t = 1.0;
     int T_A = 40;
     int T_B = 0;
     int T_C = 30;
     int T_D = 0;
     double k_B = 0.1;
     double k_D = 0.6;
     int IT_MAX = 2000;

    gsl_matrix *A = gsl_matrix_calloc(N, N);
    gsl_matrix *B = gsl_matrix_calloc(N, N);
    gsl_vector *c = gsl_vector_calloc(N);
    gsl_vector *d = gsl_vector_calloc(N);
    gsl_vector *T = gsl_vector_calloc(N);
    
    
    gsl_permutation *p = gsl_permutation_alloc(N);
    int signum = 0;

    int l = 0;
    for(int i = 1; i <= nx - 1; i++){
      for(int j = 1; j <=ny - 1; j++){
          l = i + j*(nx+1);
          gsl_matrix_set(A, l, l-nx-1, delta_t / (2*pow(delta, 2)));
          gsl_matrix_set(A, l, l-1,    delta_t / (2*pow(delta, 2)));
          gsl_matrix_set(A, l, l+1,    delta_t / (2*pow(delta, 2)));
          gsl_matrix_set(A, l, l+nx+1, delta_t / (2*pow(delta, 2)));
          gsl_matrix_set(A, l, l,      -(2*delta_t)/pow(delta,2) - 1);
          
          gsl_matrix_set(B, l, l-nx-1, -delta_t / (2*pow(delta, 2)));
          gsl_matrix_set(B, l, l-1,    -delta_t / (2*pow(delta, 2)));
          gsl_matrix_set(B, l, l+1,    -delta_t / (2*pow(delta, 2)));
          gsl_matrix_set(B, l, l+nx+1, -delta_t / (2*pow(delta, 2)));
          gsl_matrix_set(B, l, l,      (2*delta_t)/pow(delta,2) - 1);
        
      }
    }
    for(int i=0; i<=nx; i+=nx){
      for(int j=0; j<=ny; j++){
        l = i + j*(nx+1);
        gsl_matrix_set(A, l, l, 1); 
        gsl_matrix_set(B, l, l, 1);
        gsl_vector_set(c, l, 0);
        }
    }
    
   for(int i=1; i<=nx-1; i++){
        l = i + ny*(nx+1);
          gsl_matrix_set(A, l, l-nx-1, - 1.0/(k_B*delta)); 
          gsl_matrix_set(A, l, l, 1 + 1.0/(k_B*delta)); 
          gsl_vector_set(c, l, T_B);
          for( int k=0; k<N; k++ ){
            gsl_matrix_set(B, l, k, 0);
            }
    }
    
   for(int i=1; i<=nx-1; i++){
        l = i + 0*(nx+1);
          gsl_matrix_set(A, l, l+nx+1, - 1.0/(k_D*delta)); 
          gsl_matrix_set(A, l, l, 1 + 1.0/(k_D*delta)); 
          gsl_vector_set(c, l, T_D);
          for( int k=0; k<N; k++ ){
            gsl_matrix_set(B, l, k, 0);
          }

    }
    
    
    
    for(int j=0; j<=ny; j++){
        l = 0 + j*(nx+1);
        gsl_vector_set(T, l, T_A);
        }
   

   for(int j=0; j<=ny; j++){
        l = nx + j*(nx+1);
        gsl_vector_set(T, l, T_C);
        }

    for(int i=1; i<=nx-1; i++){
        for(int j=0; j<=ny; j++){
        l = i + j*(nx+1);
        gsl_vector_set(T, l, 0);
      }
    }
    FILE* file1;
    file1 = fopen("T.dat", "w");
    FILE* file2;
    file2 = fopen("nT.dat", "w");
     gsl_linalg_LU_decomp(A, p, &signum);
     for(int it=0; it<=IT_MAX; it++){
       gsl_blas_dgemv( CblasNoTrans, 1, B, T, 0, d );
       gsl_blas_daxpy( 1, c, d );
       gsl_linalg_LU_solve( A, p, d, T );
       if( it == 100 || it == 200 || it == 500 || it == 1000 || it == 2000 ){
         for( int i=0; i<N; i++ ){
           fprintf(file1, "%g\t", gsl_vector_get(T, i));
           
            if((i+1)%(nx+1)==0){
                    fprintf(file1, "\n");
                    }
                  
           
         }
         
       for(int i=1; i<=nx-1; i++){
        for(int j=1; j<=ny-1; j++){
            l = i + j*(nx+1);
            fprintf(file2, "%g\t",(( gsl_vector_get(T, l+1) - 2 * gsl_vector_get(T, l) + gsl_vector_get(T, l-1))/pow(delta, 2))
                                      + (( gsl_vector_get(T, l+nx+1) - 2*gsl_vector_get(T, l) + gsl_vector_get(T, l-nx-1))/pow(delta, 2) )); 
             }
             fprintf(file2, "\n");
          }
          
           fprintf(file2, "\n");
          
          
          
       }
       
     }
    
    
    gsl_matrix_free(A);
     gsl_matrix_free(B);
    gsl_vector_free(c);
    gsl_vector_free(T);
    gsl_permutation_free(p);   
}


int main()
{
  dyf();
}
