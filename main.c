#include <stdio.h>
#include <time.h>

int main(void) {
    int i = 100, j = 100;
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
            b[x][y] = 2;
        }
    }

    for (x=0;x<i;x++){
        for (y=0;y<j;y++){
            c[x][y] = a[x][y] * b[x][y];
//            printf("%f", c[x][y]);
        }
    }
    float d = clock();
    printf("%f", d);

}
