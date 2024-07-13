#include <stdio.h>
#include <time.h>
#include <stdlib.h>


clock_t t;
double time_taken;
float a = 10.0;

void startc(){
    t = clock();
}

double endc(){
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    return time_taken;
}

void gen_mat(int not){
    int i = 300, j = 300;
    int x = i, y = j;
    float a[i][j];
    float b[i][j];
    float c[i][j];

    startc();
    int z;
    for (z=0;z<not;z++) {
        for (x=0;x<i;x++){
            for (y=0;y<j;y++){
                a[x][y] = 2;
            }
        }
        for (x=0;x<i;x++){
            for (y=0;y<j;y++){
                a[x][y] = 0;
            }
        }
    }
    endc();
    printf("%f", time_taken);
}

void mult_mat(int not){
    int i = 300, j = 300;
    int x = i, y = j;
    float a[i][j];
    float b[i][j];
    float c[i][j];
    for (x=0;x<i;x++){
        for (y=0;y<j;y++){
            a[x][y] = 2;
        }
    }
    for (x=0;x<i;x++){
        for (y=0;y<j;y++){
            b[x][y] = 3;
        }
    }

    startc();
    int z;
    for (z=0;z<not;z++) {
        for (x = 0; x < i; x++) {
            for (y = 0; y < j; y++) {
                //c[x][y] = (a[x][y] * b[x][y]);
                c[x][y] = ((float)rand() / RAND_MAX) * 500;
            }
        }
        for (x = 0; x < i; x++) {
            for (y = 0; y < j; y++) {
                c[x][y] = 0;
            }
        }
    }
    endc();
    //printf("%f", time_taken);
}

int main(void) {
    int o;
    float timetime;
    for (o=0;o<10;o++) {
        printf("Pass %d\n", o+1);
        mult_mat(10000);
        timetime += time_taken;
    }
    printf("%f\n", timetime/10);
    system("pause");
}
