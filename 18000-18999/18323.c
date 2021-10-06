#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 1부터 N(N <= 1000)까지의 순열에서 인접한 수의 합을 통해 만들어진 길이 N - 1의 수열이 주어진다.
이때, 원래 순열이 될 수 있는 것 중 사전순으로 가장 빠른 것을 구한다.

해결 방법 : 맨 앞 수가 정해지면 나머지 모든 수를 정할 수 있음을 알 수 있다.
따라서, 맨 앞 수를 1부터 차례로 올려가며 답이 될 수 있는 순열이 나오면 그 순열을 출력하고 프로그램을 종료하면 된다.

주요 알고리즘 : 브루트 포스, 사칙연산

출처 : USACO 2020J B2번
*/

int b[1024], a[1024], vis[1024];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("photo.in", "r");
        fo = fopen("photo.out", "w");
    }
    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) vis[j] = 0;
        a[0] = i;
        vis[i] = 1;
        t = 1;
        for (int j = 1; j < n; j++) {
            a[j] = b[j - 1] - a[j - 1];
            if (a[j] < 1 || a[j] > n || vis[a[j]]) {
                t = 0;
                break;
            }
            vis[a[j]] = 1;
        }
        if (t) {
            for (int j = 0; j < n; j++) {
                printf("%d", a[j]);
                if (j < n - 1) printf("%c", ' ');
            }
            return 0;
        }
    }
    return 1;
}