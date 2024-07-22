#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <wbemidl.h>
clock_t t;
double time_taken;
int o;
double timetime;
extern double a[250][250];
extern double b[250][250];
double c[250][250];
void reset() {
    timetime = 0;
    o = 0;
    return;
}
double startc(){
    t = clock();
    return t;
}
double endc(){
    t = clock() - t;
    time_taken = ((double)t)/(double)CLOCKS_PER_SEC;
    timetime+=(double)time_taken;
    return time_taken;
}
int run_times(){
    int a;
    printf("How many passes? (10 will take around 5-30 seconds depending on test)\n");
    printf(">>");
    scanf("%d", &a);
    return a;
}
void write_scores(int test){
    if (o == 0) return;
    if (test == 1){
        FILE *f = fopen("scores1.txt", "a");
        if (f == NULL)
        {
            printf("Error writing to log file.\n");
            return;
        }
        fprintf(f, "%.10f\n", timetime / o);
        fclose(f);
    }
    else if (test == 2){
        FILE *f = fopen("scores2.txt", "a");
        if (f == NULL)
        {
            printf("Error writing to log file.\n");
            return;
        }
        fprintf(f, "%.10f\n", timetime / o);
        fclose(f);
    }
    else if (test == 3){
        FILE *f = fopen("scores3.txt", "a");
        if (f == NULL)
        {
            printf("Error writing to log file.\n");
            return;
        }
        fprintf(f, "%.10f\n", timetime / o);
        fclose(f);
    }
    else if (test == 4){
        FILE *f = fopen("scores4.txt", "a");
        if (f == NULL)
        {
            printf("Error writing to log file.\n");
            return;
        }
        fprintf(f, "%.10f\n", timetime / o);
        fclose(f);
    }
    else if (test == 5){
        FILE *f = fopen("scores5.txt", "a");
        if (f == NULL)
        {
            printf("Error writing to log file.\n");
            return;
        }
        fprintf(f, "%.10f\n", timetime / o);
        fclose(f);
    }
    else if (test == 6){
        FILE *f = fopen("scores6.txt", "a");
        if (f == NULL)
        {
            printf("Error writing to log file.\n");
            return;
        }
        fprintf(f, "%.10f\n", timetime / o);
        fclose(f);
    }
    else if (test == 7){
        FILE *f = fopen("scores7.txt", "a");
        if (f == NULL)
        {
            printf("Error writing to log file.\n");
            return;
        }
        fprintf(f, "%.10f\n", timetime / o);
        fclose(f);
    }
    else if (test == 8){
        FILE *f = fopen("scores8.txt", "a");
        if (f == NULL)
        {
            printf("Error writing to log file.\n");
            return;
        }
        fprintf(f, "%.10f\n", timetime / o);
        fclose(f);
    }

}
void mult_mat(int not){
    reset();
    int i = 250, j = 250;
    int x = i, y = j;
    double a[i][j];
    double b[i][j];
    double c[i][j];
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
    printf("%.10f\n", timetime / o);
    write_scores(1);
}
void check_mat(int not){
    reset();
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
    printf("%.10f\n", timetime / o);
    write_scores(2);
}
void print_speed(int not){
    reset();
    int run = run_times();
    for (o = 0; o < run; o++) {
        startc();
        int z;
        for (z = 0; z < not; z++) {
            printf("qwertyuiopasdfghjklzxcvbnm1234567890!@#$^&*()-=_+[]{};':\",./<>?\n");
        }
        endc();
    }
    printf("%.10f\n", timetime / o);
    write_scores(3);
}
void string(long long int not){
    reset();
    char a[100000] = "c";
    char b = 'c';
    int run = run_times();
    for (o = 0; o < run; o++) {
        printf("Pass %d\n", o + 1);
        startc();
        for (int z = 0; z < not && strlen(a) < sizeof(a) - 1; z++) {
            strncat(a, &b, 1);
        }
        endc();
        a[0] = '\0';
    }
    printf("%.10f\n", timetime / o);
    write_scores(4);
}
void pi(int not){
    reset();
    double p;
    double cir = 68.65838503937458;
    double rad = 10.9273213637231;
    int run = run_times();
    for (o = 0; o < run; o++) {
        printf("Pass %d\n", o + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            p = cir/(rad*2);
        }
        endc();
        p = 0;
    }
    printf("%.10f\n", timetime / o);
    write_scores(5);
}
float fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
void fib1(int not){
    reset();
    int run = run_times();
    for (o = 0; o < run; o++) {
        printf("Pass %d\n", o + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            fib(36);
        }
        endc();
    }
    write_scores(6);
    printf("%.10f\n", timetime / o);
}
void division(int not){
    reset();
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
                    c[x][y] = (a[x][y] / b[x][y]);
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
    printf("%.10f\n", timetime / o);
    write_scores(7);
}
void doubles(int not){
    reset();
    long int a = 1.0;
    int run = run_times();
    for (o = 0; o < run; o++) {
        printf("Pass %d\n", o + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            a = a * 2;
        }
        endc();
    }
    printf("%.10f\n", timetime / o);
    write_scores(8);
}
int main(void) {
    int ans;
    while (1) {
        printf("---------------------------------------------------------------\n");
        printf("                  Welcome to benchmark.\n");
        printf("                  [1]- Float Matrix Multiplication\n");
        printf("                  [2]- Float Matrix Verification\n");
        printf("                  [3]- Console Print Speed\n");
        printf("                  [4]- String Concatenation\n");
        printf("                  [5]- Pi\n");
        printf("                  [6]- Fibonacci\n");
        printf("                  [7]- Matrix Division\n");
        printf("                  [8]- Doubling\n");
        printf("                  [9]- Quit\n");
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
            string(10000000000);
        }
        else if (ans == 5) {
            pi(1000000000);
        }
        else if (ans == 6) {
            fib1(100);
        }
        else if (ans == 7) {
            division(100000);
        }
        else if (ans == 8) {
            doubles(700000000);
        }
        else if (ans == 9) {
            return 0;
        }
        else {
            printf("Not a valid option.\n");
        }
        system("pause");
    }
}