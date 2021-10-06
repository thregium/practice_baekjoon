#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 50000)개의 샘플의 무게와 분류(2가지 중 하나)가 주어질 때, A 이상 B 이하의 무게에 대해
가장 가까운 무게의 샘플의 분류가 1인 것의 개수를 구한다. 가까운 무게의 샘플이 여러 개 있다면 그 중 하나라도 1이 있으면
1로 생각하고, 없으면 2로 생각한다. 각 샘플의 무게는 10^9 이하의 자연수이다.

해결 방법 : 각 샘플의 무게를 정렬한 후, 가장 작은 것 부터 순서대로 올라가며 주위의 샘플 분류에 맞춰
해당 구간의 샘플 개수를 구한다. (생략)

주요 알고리즘 : 수학, 스위핑, 케이스 워크

출처 : USACO 2014D B4번
*/

char buff[8];
int data[51200][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("learning.in", "r");
        fo = fopen("learning.out", "w");
    }
    //freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2014_12\\learning_bronze\\12.in", "r", stdin);
    int n, a, b, w, r = 0;
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", buff, &data[i][0]);
        if (buff[0] == 'S') data[i][1] = 1;
    }
    qsort(data, n, sizeof(int) * 2, cmp1);
    if (data[0][0] > b) {
        printf("%d", data[0][1] ? b - a + 1 : 0);
        return 0;
    }
    else if (data[n - 1][0] < a) {
        printf("%d", data[n - 1][1] ? b - a + 1 : 0);
        return 0;
    }
    if (data[0][1] == 1 && data[0][0] >= a) r += data[0][0] - a + 1;
    if (data[n - 1][1] == 1 && data[n - 1][0] <= b) r += b - data[n - 1][0];

    for (int i = 1; i < n; i++) {
        if (data[i][0] < a) continue;
        else if (data[i - 1][0] < a) {
            if (data[i][0] > b) {
                if (data[i][1] + data[i - 1][1] == 2) r += b - a + 1;
                else return 1;
            }
            if (data[i][1] + data[i - 1][1] == 2) r += data[i][0] - a + 1;
            else if (data[i][1] == 0 && data[i - 1][1] == 1) {
                if (a <= ((data[i][0] + data[i - 1][0]) >> 1)) r += ((data[i][0] + data[i - 1][0]) >> 1) - a + 1;
            }
            else if (data[i][1] == 1 && data[i - 1][1] == 0) {
                if (a >= ((data[i][0] + data[i - 1][0] + 1) >> 1)) r += data[i][0] - a + 1;
                else r += ((data[i][0] - data[i - 1][0]) >> 1) + 1;
            }
            continue;
        }

        if (data[i][0] > b) {
            if (data[i][1] + data[i - 1][1] == 2) r += b - data[i - 1][0];
            else if (data[i][1] == 0 && data[i - 1][1] == 1) {
                if (b <= ((data[i][0] + data[i - 1][0]) >> 1)) r += b - data[i - 1][0];
                else r += ((data[i][0] - data[i - 1][0]) >> 1);
            }
            else if (data[i][1] == 1 && data[i - 1][1] == 0) {
                if (b >= ((data[i][0] + data[i - 1][0] + 1) >> 1)) r += b - ((data[i][0] + data[i - 1][0] + 1) >> 1) + 1;
            }
            break;
        }
        if (data[i][0] == data[i - 1][0]) return 1;

        if (data[i][1] + data[i - 1][1] == 2) r += data[i][0] - data[i - 1][0];
        else if (data[i][1] == 0 && data[i - 1][1] == 1) r += ((data[i][0] - data[i - 1][0]) >> 1);
        else if (data[i][1] == 1 && data[i - 1][1] == 0) r += ((data[i][0] - data[i - 1][0]) >> 1) + 1;
    }
    printf("%d", r);
    return 0;
}