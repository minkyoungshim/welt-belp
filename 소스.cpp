#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    float rfp[10000];
    char row[1000];
    char* t;

    int num = 0;
    FILE* f = NULL;
    f = fopen("belt12.csv", "r");       //파일의 오픈을 통하여 blep데이터 획득
    if (f != NULL) {
        while (!feof(f)) {
            int column = 0;
            fgets(row, 1000, f);
            t = strtok(row, ",");

            while (t != NULL) {
                if (column == 4) {
                    if (atof(t) != 0) {
                        rfp[num++] = atof(t);
                    }
                }
                t = strtok(NULL, ",");
                column++;
            }
        }
    }

    int i, j;
    for (i = 1; i < num; i++) {
        float key = rfp[i];

        for (j = i - 1; j >= 0 && rfp[j] > key; j--) {
            rfp[j + 1] = rfp[j];
        }
        rfp[j + 1] = key;       //삽입정렬 수행 및 결과 출력
    }

    for (int i = 0; i < num; i++) {
        // 배열값 출력
    }
    printf("\n");

    return 0;
}