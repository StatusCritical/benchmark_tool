#include <stdio.h>
#include <time.h>
#include <stdlib.h>


clock_t t;
double time_taken;
int o;
float timetime;

void startc(){
    t = clock();
}

double endc(){
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    timetime+=(double)time_taken;
    return time_taken;
}

void mult_mat(int not){
    int i = 250, j = 250;
    int x = i, y = j;
    double a[i][j];
    double b[i][j];
    double c[i][j];
    for (x=0;x<i;x++){
        for (y=0;y<j;y++){
            a[x][y] = ((double) rand() / RAND_MAX) * (double)500;
        }
    }
    for (x=0;x<i;x++){
        for (y=0;y<j;y++){
            b[x][y] = ((double) rand() / RAND_MAX) * (double)500;
        }
    }
    for (o = 0; o < 10; o++) {
        printf("Pass %d\n", o + 1);

        startc();
        int z;
        for (z = 0; z < not; z++) {
            for (x = 0; x < i; x++) {
                for (y = 0; y < j; y++) {
                    c[x][y] = (a[x][y] * b[x][y]);
                }
            }
            for (x = 0; x < i; x++) {
                for (y = 0; y < j; y++) {
                    c[x][y] = 0;
                }
            }
        }
        endc();
    }
    printf("%f\n", timetime / 10);
}

void check_mat(int not){
    int i = 250, j = 250;
    int x = i, y = j;
    double a[i][j];
    double b[i][j];
    double c[i][j];
    for (x=0;x<i;x++){
        for (y=0;y<j;y++){
            a[x][y] = ((double) rand() / RAND_MAX) * (double)500;
        }
    }
    for (x=0;x<i;x++){
        for (y=0;y<j;y++){
            b[x][y] = ((double) rand() / RAND_MAX) * (double)500;
        }
    }

    for (o = 0; o < 10; o++) {
        printf("Pass %d\n", o + 1);

        startc();
        int z;
        for (z = 0; z < not; z++) {
            for (x = 0; x < i; x++) {
                for (y = 0; y < j; y++) {
                    if (a[x][y] == b[x][y]) {
                        c[x][y] = 1;
                    } else {
                        c[x][y] = 0;
                    }
                }
            }
            for (x = 0; x < i; x++) {
                for (y = 0; y < j; y++) {
                    c[x][y] = 0;
                }
            }
        }
        endc();
    }
    printf("%f\n", timetime / 10);
}

int main(void) {
    while (1) {
        mult_mat(100000);
        system("pause");
        timetime = 0;
        check_mat(100000);
        system("pause");
        timetime = 0;
    }
}
