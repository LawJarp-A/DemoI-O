#include "a.h"
#include <time.h>

void main()
{
    FILE *t1, *t2, *t3, *t4;
    FILE *c1, *c2, *c3, *c4;

    //Create output files
    t1 = fopen("bs1.dat", "w");
    t2 = fopen("ss1.dat", "w");
    t3 = fopen("ms1.dat", "w");
    t4 = fopen("qs1.dat", "w");
    c1 = fopen("bs2.dat", "w");
    c2 = fopen("ss2.dat", "w");
    c3 = fopen("ms2.dat", "w");
    c4 = fopen("qs2.dat", "w");
    
    //Add color option - to differentiate when graphing with Xgraph
    fprintf(t1,"color = 2\n");
    fprintf(c1,"color = 2\n");

    fprintf(t2,"color = 4\n");
    fprintf(c2,"color = 4\n");

    fprintf(t3,"color = 7\n");
    fprintf(c3,"color = 7\n");

    fprintf(t4,"color = 3\n");
    fprintf(c4,"color = 3\n");    

    //Initi n to 100k
    long int n = 100000;
    //Init variable to store number of comparisions
    long int cmp;

    // 1050000

    while (n != 1050000)
    {
        //Allocate required memory
        long int *a = malloc (sizeof (long int) * n);
        long int *b = malloc (sizeof (long int) * n);
        long int *c = malloc (sizeof (long int) * n);
        long int *d = malloc (sizeof (long int) * n);

        //Generate random values for the allocated array
        long int rand_num = 0;
        for (long int i = 0; i < n; i++)
        {
            rand_num = rand() % n + 1;
            a[i] = rand_num;
            b[i] = rand_num;
            c[i] = rand_num;
            d[i] = rand_num;
        }
        printf("%li\n", n);

        //Using clock_t to keep time
        clock_t start, end;

        //Bubble sort
        cmp = 0;
        start = clock();
        bubbleSort(a, n - 1, &cmp);
        end = clock();
        //Print data acquired in the respective file
        fprintf(t1, "%li\t%lf\n", n, ((double)(end - start)));
        fprintf(c1, "%li\t%li\n", n, cmp);
        printf("*\n");

        //Selection sort
        cmp = 0;
        start = clock();
        selectionSort(b, n - 1, &cmp);
        end = clock();
        fprintf(t2, "%li\t%lf\n", n, ((double)(end - start)));
        fprintf(c2, "%li\t%li\n", n, cmp);
        printf("*\n");

        //Merge Sort
        cmp = 0;
        start = clock();
        mergeSort(c, 0, n - 1, &cmp);
        end = clock();
        fprintf(t3, "%li\t%lf\n", n, ((double)(end - start)));
        fprintf(c3, "%li\t%li\n", n, cmp);
        printf("*\n");

        //Quick Sort
        cmp = 0;
        start = clock();
        quickSort(d, 0, n - 1, &cmp);
        end = clock();
        fprintf(t4, "%li\t%lf\n", n, ((double)(end - start)));
        fprintf(c4, "%li\t%li\n", n, cmp);
        printf("*\n");

        //Append by 50k each time
        n += 50000;

        //Free allocated memory
        free(a);
        free(b);
        free(c);
        free(d);
    }

    //Cleaning up after
    //Close and save the output files associated with each function
    fclose(t1);
    fclose(t2);
    fclose(t3);
    fclose(t4);
    fclose(c1);
    fclose(c2);
    fclose(c3);
    fclose(c4);
}
