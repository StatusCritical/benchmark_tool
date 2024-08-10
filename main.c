#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
clock_t t;
double time_taken;
int passloop;
double timetime;
extern double m1[250][250];
extern double m2[250][250];
extern double c[250][250];
int when_record(int indicator) {
    if (indicator == 0) {
        int answer;
        printf("Would you like to record individual tests or the average?[0]Each/[1]Average/[2]None\n");
        printf(">>");
        scanf("%d", &answer);
        return answer;
    } else {
        return indicator;
    }
}
void core() {
    PROCESSOR_NUMBER ProcNumber;
    GetCurrentProcessorNumberEx(&ProcNumber);
    printf("Running program on processor group %d, number %d.\n", ProcNumber.Group, ProcNumber.Number);
}
void reset() {
    timetime = 0;
    passloop = 0;
}
double startc() {
    t = clock();
    return t;
}
double endc() {
    t = clock() - t;
    time_taken = ((double)t) / (double)CLOCKS_PER_SEC;
    timetime += (double)time_taken;
    return time_taken;
}
int run_times(int indicator) {
    if (indicator == 0) {
        int answer;
        printf("How many passes? (10 will take around 20-120 seconds depending on test)\n");
        printf(">>");
        scanf("%d", &answer);
        return answer;
    } else {
        return indicator;
    }
}
void write_scores(int test) {
    if (passloop == 0) return;
    FILE *f = NULL;
    switch (test) {
        case 1:
            f = fopen("scores1.txt", "a");
            break;
        case 2:
            f = fopen("scores2.txt", "a");
            break;
        case 3:
            f = fopen("scores3.txt", "a");
            break;
        case 4:
            f = fopen("scores4.txt", "a");
            break;
        case 5:
            f = fopen("scores5.txt", "a");
            break;
        case 6:
            f = fopen("scores6.txt", "a");
            break;
        case 7:
            f = fopen("scores7.txt", "a");
            break;
        case 8:
            f = fopen("scores8.txt", "a");
            break;
        case 9:
            f = fopen("scores9.txt", "a");
            break;
        case 10:
            f = fopen("scores10.txt", "a");
            break;
        default:
            return;
    }
    if (f == NULL) {
        return;
    }
    fprintf(f, "%.10f\n", timetime / passloop);
    fclose(f);
}
void write_all_scores(int test) {
    FILE *f = NULL;
    switch (test) {
        case 1:
            f = fopen("scores1.txt", "a");
            break;
        case 2:
            f = fopen("scores2.txt", "a");
            break;
        case 3:
            f = fopen("scores3.txt", "a");
            break;
        case 4:
            f = fopen("scores4.txt", "a");
            break;
        case 5:
            f = fopen("scores5.txt", "a");
            break;
        case 6:
            f = fopen("scores6.txt", "a");
            break;
        case 7:
            f = fopen("scores7.txt", "a");
            break;
        case 8:
            f = fopen("scores8.txt", "a");
            break;
        case 9:
            f = fopen("scores9.txt", "a");
            break;
        case 10:
            f = fopen("scores10.txt", "a");
            break;
        default:
            return;
    }
    if (f == NULL) {
        return;
    }
    fprintf(f, "%.10f\n", time_taken);
    fclose(f);
}
void mult_mat(int not, int runs, int record){
    reset();
    int x,y;
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);

        startc();
        int z;
        for (z = 0; z < not; z++) {
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    c[x][y] = (m1[x][y] * m2[x][y]);
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
            write_all_scores(1);
        }
    }
    printf("%.10f\n", timetime / passloop);
    if (record == 1){
        write_scores(1);
    }
}
void check_mat(int not, int runs, int record){
    reset();
    int x, y;
    
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    if (m1[x][y] == m2[x][y]) {
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
            write_all_scores(2);
        }
    }
    printf("%.10f\n", timetime / passloop);
    if (record == 1){
        write_scores(2);
    }
}
void print_speed(int not, int runs, int record){
    reset();
    
    
    for (passloop = 0; passloop < runs; passloop++) {
        startc();
        int z;
        for (z = 0; z < not; z++) {
            printf("qwertyuiopasdfghjklzxcvbnm1234567890!@#$^&*()-=_+[]{};':\",./<>?\n");
        }
        endc();
        if (record == 0){
            write_all_scores(3);
        }
    }
    printf("%.10f\n", timetime / passloop);
    if (record == 1){
        write_scores(3);
    }
}
void string(long long int not, int runs, int record){
    reset();
    char string[2000000] = "c";
    char adding = 'c';
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        for (int z = 0; z < not && strlen(string) < sizeof(string) - 1; z++) {
            strncat(string, &adding, 1);
        }
        endc();
        string[0] = '\0';
        if (record == 0){
            write_all_scores(4);
        }
    }
    printf("%.10f\n", timetime / passloop);
    if (record == 1){
        write_scores(4);
    }
}
void pi(long long int not, int runs, int record){
    reset();
    long double p = 0;
    long double cir = 68.65838503937458;
    long double rad = 10.9273213637231;
    
    
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            p = cir/(rad*2);
        }
        endc();
        p = 0;
        if (record == 0){
            write_all_scores(5);
        }
    }
    printf("%.10f\n", timetime / passloop);
    if (record == 1){
        write_scores(5);
    }
}
float fib(float num) {
    if (num <= 1){
        return num;
    }
    return fib(num-1) + fib(num-2);
}
void fib1(int not, int runs, int record){
    reset();
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            fib(36);
        }
        endc();
        if (record == 0){
            write_all_scores(6);
        }
    }
    if (record == 1){
        write_scores(6);
    }
    printf("%.10f\n", timetime / passloop);
}
void division(int not, int runs, int record){
    reset();
    int x, y;
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    c[x][y] = (m1[x][y] / m2[x][y]);
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
            write_all_scores(7);
        }
    }
    printf("%.10f\n", timetime / passloop);
    if (record == 1){
        write_scores(7);
    }
}
void doubles(int not, int runs, int record){
    reset();
    long int number1 = 1;
    
    
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            number1 = number1 * 2;
        }
        endc();
        if (record == 0){
            write_all_scores(8);
        }
    }
    printf("%.10f\n", timetime / passloop);
    if (record == 1){
        write_scores(8);
    }
}
void file_write(int not, int runs, int record){
    reset();
    FILE *test = fopen("test.txt", "a");
    if (test == NULL) {
        printf("Error writing to test file.\n");
        return;
    }
    int x, y;
    
    
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    fprintf(test, "%.10f\n", m1[x][y]);
                }
            }
        }
        endc();
        if (record == 0){
            write_all_scores(9);
        }
        test = fopen("test.txt", "w");
        fprintf(test, "");
    }
    printf("%.10f\n", timetime / passloop);
    fclose(test);
    if (record == 1){
        write_scores(9);
    }
}
int fib3(int not) {
    int n1 = 0, n2 = 1, n3, i;
    for (i = 0; i <= not; i++) {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }
    return n2;
}
void fib4(int not, int runs, int record){
    reset();
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        int z;
        for (z = 0;z<not;z++) {
            fib3(40000);
        }
        endc();
        if (record == 0){
            write_all_scores(10);
        }
    }
    if (record == 1){
        write_scores(10);
    }
    printf("%.10f\n", timetime / passloop);
}
void queue(){
    int tests[50];
    int runs[50];
    int rec;
    int run = 0;
    while (1){
        printf("Enter the test number you would like to run or 0 to finish:");
        scanf("%d", &tests[run]);
        if (tests[run] <= 0 || tests[run] > 10){
            break;
        }
        runs[run] = run_times(0);
        run++;
    }
    rec = when_record(0);
    for (int i = 0; i < run; i++){
        if (tests[i] == 1){
            mult_mat(50000, run_times(runs[i]), rec);
        }
        else if (tests[i] == 2){
            check_mat(50000, run_times(runs[i]), rec);
        }
        else if (tests[i] == 3){
            print_speed(2000, run_times(runs[i]), rec);
        }
        else if (tests[i] == 4){
            string(300000, run_times(runs[i]), rec);
        }
        else if (tests[i] == 5){
            pi(1000000000, run_times(runs[i]), rec);
        }
        else if (tests[i] == 6){
            fib1(150, run_times(runs[i]), rec);
        }
        else if (tests[i] == 7){
            division(70000, run_times(runs[i]), rec);
        }
        else if (tests[i] == 8){
            doubles(900000000, run_times(runs[i]), rec);
        }
        else if (tests[i] == 9){
            file_write(100, run_times(runs[i]), rec);
        }
        else if (tests[i] == 10){
            fib4(100000, run_times(runs[i]), rec);
        }
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
        printf("                [10]- Second Fibonacci\n");
        printf("                [11]- Set up a queue of tests.\n");
        printf("                [0]- Quit\n");
        printf("---------------------------------------------------------------\n");
        printf(">>");
        scanf("%d", &ans);
        if (ans == 1) {
            mult_mat(50000, run_times(0), when_record(0));
        }
        else if (ans == 2) {
            check_mat(50000, run_times(0), when_record(0));
        }
        else if (ans == 3) {
            print_speed(2000, run_times(0), when_record(0));
        }
        else if (ans == 4) {
            string(300000, run_times(0), when_record(0));
        }
        else if (ans == 5) {
            pi(1000000000, run_times(0), when_record(0));
        }
        else if (ans == 6) {
            fib1(150, run_times(0), when_record(0));
        }
        else if (ans == 7) {
            division(70000, run_times(0), when_record(0));
        }
        else if (ans == 8) {
            doubles(900000000, run_times(0), when_record(0));
        }
        else if (ans == 9) {
            file_write(100, run_times(0), when_record(0));
        }
        else if (ans == 10) {
            fib4(100000, run_times(0), when_record(0));
        }
        else if (ans == 11) {
            queue();
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
