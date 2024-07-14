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
int run_times(){
    int a;
    printf("How many passes? (Higher is more accurate):");
    scanf("%d", &a);
    return a;
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

    int run = run_times();
    for (o = 0; o < run; o++) {
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
    int run = run_times();
    for (o = 0; o < run; o++) {
        printf("Pass %d\n", o + 1);

        startc();
        int z;
        for (z = 0; z < not; z++) {
            for (x = 0; x < i; x++) {
                for (y = 0; y < j; y++) {
                    if (a[x][y] == b[x][y]) {
                        c[x][y] = 2;
                    } else {
                        c[x][y] = 1;
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
void print_speed(int not){
    int run = run_times();
    for (o = 0; o < run; o++) {
        startc();
        int z;
        for (z = 0; z < not; z++) {
            printf("....................................................................................................");

        }
        endc();
    }
    printf("%f\n", timetime / 10);
}
int main(void) {
    int ans;
    while (1) {
        print_speed(1);
        printf("---------------------------------------------------------------\n");
        printf("                  Welcome to benchmark.\n");
        printf("                  [1]- Float Matrix Multiplication\n");
        printf("                  [2]- Float Matrix Verification\n");
        printf("                  [3]- Console Print Speed\n");
        printf("                  [4]- Quit\n");
        printf("---------------------------------------------------------------\n");
        printf(">>");
        scanf("%d", &ans);
        if (ans == 1) {
            mult_mat(10000);
        }
        else if (ans == 2) {
            check_mat(10000);
        }
        else if (ans == 3) {
            print_speed(10000);
        }
        else if (ans == 4) {
            return 0;
        }
        else {
            break;
        }
        system("pause");
        timetime = 0;
    }
}
