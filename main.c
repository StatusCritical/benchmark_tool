#include <stdio.h>
#include <time.h>

int main(void) {
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

    clock_t t;
    t = clock();
    int z;

    for (z=0;z<10000;z++) {
        for (x = 0; x < i; x++) {
            for (y = 0; y < j; y++) {
                c[x][y] = (a[x][y] * b[x][y]);
                //printf("%f", c[x][y]);
                //printf(".");
            }
        }
        for (x = 0; x < i; x++) {
            for (y = 0; y < j; y++) {
                c[x][y] = 0;
            }
        }
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%f", time_taken);

}
