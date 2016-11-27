#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <omp.h>


void fib_n(int n)//nerec
{
    int i;
    int x = 1; //F(n-2)
    int y = 0; //F(n-1)
    int ans;//F(n)
  	double time1, time2, time;
  	FILE *file;
  	file = fopen("data1.txt","w");
  	time1 = omp_get_wtime(); 
  	for (i = 1; i <= n; i++)
  	{
  		ans = x + y;
  		time2 = omp_get_wtime(); 
     		x = y;
     		y = ans;
  		time = time2-time1; 
  		// printf("%d %f\n",i, time); 
  		fprintf(file,"%d %f\n",i, time); 
     		// printf("  %d ", ans);
      }
    fclose(file); 
}

unsigned long int calcFibRecur(int value) 
{
  if (value == 0)
  {
    return 0;
  }
  else if (value == 1)
  {
    return 1;
  }
  else
  {
    return calcFibRecur(value - 1) + calcFibRecur(value - 2);
  }
}

void fibo (int n)//rec
{	
  double time1, time2, time;
  int i;
  unsigned long int val;
  FILE *file;


  file = fopen("data2.txt","w") ;
  time1 = omp_get_wtime(); 
  
  for(i = 0; i <= n; i++)
  {
    val = calcFibRecur(i);
    time2 = omp_get_wtime(); 
    fprintf(file, "%d %f\n", i, time2 - time1);
  }
 
  fclose(file); 
}




int fib100(int n)
{
    int i;
    mpz_t f_1;
    mpz_t f_2;
   	 
    mpz_init(f_1);
    mpz_init(f_2);
    mpz_set_ui(f_1,0);
    mpz_set_ui(f_2, 1);
	double time1, time2, time;
	FILE *file;


	file = fopen("data3.txt","w");
	fprintf(file,"\n"); 
	time1 = omp_get_wtime(); 
    for(i = 1; i<=n; i++)
    {
   		mpz_add (f_1, f_2, f_1);
   		mpz_swap(f_1, f_2);
		char *f_1_as_string = mpz_get_str(NULL, 10, f_1);
		time2 = omp_get_wtime(); 
		time = time2-time1; 
		fprintf(file,"%d %f\n",i, time); 
    }
	fclose(file); 
	//~ free(f_1_as_string );
   /* for(i = 1; i<=n; i++)
    {
   	// printf("%d %s\n", i, f_1_as_string);
 }*/
	mpz_clear(f_1);
	mpz_clear(f_2);
}


int main(void)
{
    // int i;
    printf("Fibon without recur\n");
    fib_n(40);

    printf("Fibon recur\n");
    fibo(40);

    printf("Fibon without recur 100\n\n");
    fib100(100);

    return 0;
}

