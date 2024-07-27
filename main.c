#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
clock_t t;
double time_taken;
int o;
double timetime;
extern double a[250][250];
extern double b[250][250];
extern double c[250][250];
int when_record(){
    int ans;
    printf("Would you like to record individual tests or the average?[0]Each/[1]Average/[2]None\n");
    printf(">>");
    scanf("%d", &ans);
    return ans;
}
void core() {
    PROCESSOR_NUMBER ProcNumber;
    GetCurrentProcessorNumberEx(&ProcNumber);
    printf("Running on processor group %d, number %d.\n", ProcNumber.Group, ProcNumber.Number);
}
void reset() {
    timetime = 0;
    o = 0;
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
    int abc;
    printf("How many passes? (10 will take around 20-120 seconds depending on test)\n");
    printf(">>");
    scanf("%d", &abc);
    return abc;
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
    else if (test == 9){
        FILE *f = fopen("scores9.txt", "a");
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
    int x,y;
    int run = run_times();
    int record = when_record();
    for (o = 0; o < run; o++) {
        printf("Pass %d\n", o + 1);

        startc();
        int z;
        for (z = 0; z < not; z++) {
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    c[x][y] = (a[x][y] * b[x][y]);
                }
            }
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    c[x][y] = 0;
                }
            }
        }
        endc();
        if (record == 0){
            write_scores(1);
        }
    }
    printf("%.10f\n", timetime / o);
    if (record == 1){
        write_scores(1);
    }
}
void check_mat(int not){
    reset();
    int x, y;
    int run = run_times();
    int record = when_record();
    for (o = 0; o < run; o++) {
        printf("Pass %d\n", o + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    if (a[x][y] == b[x][y]) {
                        c[x][y] = 2;
                    } else {
                        c[x][y] = 1;
                    }
                }
            }
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    c[x][y] = 0;
                }
            }
        }
        endc();
        if (record == 1){
            write_scores(2);
        }
    }
    printf("%.10f\n", timetime / o);
    if (record == 1){
        write_scores(2);
    }
}
void print_speed(int not){
    reset();
    int run = run_times();
    int record = when_record();
    for (o = 0; o < run; o++) {
        startc();
        int z;
        for (z = 0; z < not; z++) {
            printf("qwertyuiopasdfghjklzxcvbnm1234567890!@#$^&*()-=_+[]{};':\",./<>?\n");
        }
        endc();
        if (record == 1){
            write_scores(3);
        }
    }
    printf("%.10f\n", timetime / o);
    if (record == 1){
        write_scores(3);
    }
}
void string(long long int not){
    reset();
    char string[2000000] = "c";
    char bb = 'c';
    int run = run_times();
    int record = when_record();
    for (o = 0; o < run; o++) {
        printf("Pass %d\n", o + 1);
        startc();
        for (int z = 0; z < not && strlen(string) < sizeof(string) - 1; z++) {
            strncat(string, &bb, 1);
        }
        endc();
        string[0] = '\0';
        if (record == 0){
            write_scores(4);
        }
    }
    printf("%.10f\n", timetime / o);
    if (record == 1){
        write_scores(4);
    }
}
void pi(int not){
    reset();
    double p = 0;
    double cir = 68.65838503937458;
    double rad = 10.9273213637231;
    int run = run_times();
    int record = when_record();
    for (o = 0; o < run; o++) {
        printf("Pass %d\n", o + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            p = cir/(rad*2);
        }
        endc();
        p = 0;
        if (record == 0){
            write_scores(5);
        }
    }
    printf("%.10f\n", timetime / o);
    if (record == 1){
        write_scores(5);
    }
}
float fib(float n) {
    if (n <= 1){
        return n;
    }
    return fib(n-1) + fib(n-2);
}
void fib1(int not){
    reset();
    int run = run_times();
    int record = when_record();
    for (o = 0; o < run; o++) {
        printf("Pass %d\n", o + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            fib(36);
        }
        endc();
        if (record == 0){
            write_scores(6);
        }
    }
    if (record == 1){
        write_scores(6);
    }
    printf("%.10f\n", timetime / o);
}
void division(int not){
    reset();
    int x, y;
    int run = run_times();
    int record = when_record();
    for (o = 0; o < run; o++) {
        printf("Pass %d\n", o + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    c[x][y] = (a[x][y] / b[x][y]);
                }
            }
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    c[x][y] = 0;
                }
            }
        }
        endc();
        if (record == 0){
            write_scores(7);
        }
    }
    printf("%.10f\n", timetime / o);
    if (record == 1){
        write_scores(7);
    }
}
void doubles(int not){
    reset();
    long int aa = 1;
    int run = run_times();
    int record = when_record();
    for (o = 0; o < run; o++) {
        printf("Pass %d\n", o + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            aa = aa * 2;
        }
        endc();
        if (record == 0){
            write_scores(8);
        }
    }
    printf("%.10f\n", timetime / o);
    if (record == 1){
        write_scores(8);
    }
}
void file_write(int not){
    reset();
    FILE *test = fopen("test.txt", "a");
    if (test == NULL) {
        printf("Error writing to test file.\n");
        return;
    }
    int x, y;
    int run = run_times();
    int record = when_record();
    for (o = 0; o < run; o++) {
        printf("Pass %d\n", o + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    fprintf(test, "%.10f\n", a[x][y]);
                }
            }
        }
        endc();
        if (record == 0){
            write_scores(9);
        }
        test = fopen("test.txt", "w");
        fprintf(test, "");
    }
    printf("%.10f\n", timetime / o);
    fclose(test);
    if (record == 1){
        write_scores(9);
    }
}
int main() {
    int ans;
    while (1) {
        printf("---------------------------------------------------------------\n");
        printf("                  Welcome to benchmark.\n          ");
        core();
        printf("                [1]- Float Matrix Multiplication\n");
        printf("                [2]- Float Matrix Verification\n");
        printf("                [3]- Console Print Speed\n");
        printf("                [4]- String Concatenation\n");
        printf("                [5]- Pi\n");
        printf("                [6]- Fibonacci\n");
        printf("                [7]- Matrix Division\n");
        printf("                [8]- Doubling\n");
        printf("                [9]- File Writing\n");
        printf("                [0]- Quit\n");
        printf("---------------------------------------------------------------\n");
        printf(">>");
        scanf("%d", &ans);
        if (ans == 1) {
            mult_mat(50000);
        }
        else if (ans == 2) {
            check_mat(50000);
        }
        else if (ans == 3) {
            print_speed(2000);
        }
        else if (ans == 4) {
            string(300000);
        }
        else if (ans == 5) {
            pi(1783793664);
        }
        else if (ans == 6) {
            fib1(150);
        }
        else if (ans == 7) {
            division(70000);
        }
        else if (ans == 8) {
            doubles(900000000);
        }
        else if (ans == 9) {
            file_write(100);
        }
        else if (ans == 0) {
            return 0;
        }
        else {
            printf("Not a valid option.\n");
        }
        system("pause");
    }
}