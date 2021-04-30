#include <stdio.h>
#include <math.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100)마리의 소들의 나이 관계가 소 X의 다음 Y 띠 / 이전 Y 띠로 주어진다고 할 때, Bessie와 Elsie의 나이 차를 구한다.

해결 방법 : Bessie를 기준으로 각 소들의 나이를 저장해 놓는다. 비교 대상의 나이를 아직 알 수 없다면 다음 소로 넘어간다.
N이 100 이하이므로 N^2으로도 충분히 돌아가는 것이 가능하다. 띠를 비교할 때에는 비교 대상의 띠는 나이 차이에서 12로 나눈 나머지가 띠 번호가 되고,
찾을 소의 띠는 브루트 포스로 확인해보면 된다. 두 띠의 나이 차이는 비교문을 쓰거나 나머지 연산을 통해 얻을 수 있다.

주요 알고리즘 : 구현, 브루트 포스, 수학

출처 : USACO 2020F B1번
*/

char* years[12] = { "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat" };
char rel[128][8][16];
int ages[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("C:\\1_공부\\PS\\olympiad\\USA\\Bronze\\2021_02\\prob1_bronze_feb21\\10.in", "r");
        fo = fopen("C:\\1_공부\\PS\\olympiad\\USA\\Bronze\\2021_02\\prob1_bronze_feb21\\10_p.out", "w");
    }
    int n, repeat = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%s", rel[i][j]);
        }
        ages[i] = 1000000; //나이 초기화
    }
    while (repeat) {
        //탐색할 대상이 있는 경우 계속 반복한다.
        repeat = 0;
        for (int i = 0; i < n; i++) {
            if (ages[i] < 1000000) continue; //이미 설정된 경우
            if (!strcmp(rel[i][7], "Bessie")) {
                //Bessie가 비교 대상인 경우
                for (int j = 0; j < 12; j++) {
                    if (!strcmp(rel[i][4], years[j])) {
                        if (!strcmp(rel[i][3], "next")) {
                            ages[i] = (j + 11) % 12 + 1; //다음 띠
                        }
                        else {
                            ages[i] = j - 12; //이전 띠
                        }
                    }
                }
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (!strcmp(rel[i][7], rel[j][0])) {
                    if (ages[j] >= 1000000) {
                        repeat = 1;
                        break;
                    }

                    for (int k = 0; k < 12; k++) {
                        if (!strcmp(rel[i][4], years[k])) {
                            if (!strcmp(rel[i][3], "next")) {
                                ages[i] = ages[j] + (k + (11 - (ages[j] + 2400) % 12)) % 12 + 1; //다음 띠
                            }
                            else {
                                ages[i] = ages[j] + (k + (12 - (ages[j] + 2400) % 12)) % 12 - 12; //이전 띠
                            }
                        }
                    }
                }
            }
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        printf("%s was born %d years %s Bessie.\n", rel[i][0], abs(ages[i]), ages[i] < 0 ? "before" : "after");
    }
    */
    for (int i = 0; i < n; i++) {
        if (!strcmp(rel[i][0], "Elsie")) {
            printf("%d", abs(ages[i])); //나이 차의 절대값 출력
            return 0;
        }
    }
    return 0;
}