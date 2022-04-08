#include <stdio.h>

/*
문제 : C(C <= 100000)개의 데이터 가운데 N(N <= 1000)개의 잘못된 데이터 목록이 주어지면,
잘못된 데이터와 정확한 데이터를 연속한 대로 묶어 출력한다.

해결 방법 : 데이터 개수가 직접 배열로 저장할 수 있는 정도이므로 데이터들을 배열로 옮긴 뒤,
연속한 데이터들을 직접 묶어나가며 구간들을 저장한 다음, 형식에 맞게 출력하면 된다.

주요 알고리즘 : 구현

출처 : NAQ 2021 G번
*/

int ec[103000], err[103000][2], corr[103000][2];

int main(void) {
    int c, n, x, stt = 1, ep = 0, cp = 0;
    scanf("%d %d", &c, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        ec[x] = 1;
    }
    for (int i = 2; i <= c; i++) {
        if (ec[i] != ec[i - 1]) {
            if (!ec[i]) {
                err[ep][0] = stt;
                err[ep][1] = i - 1;
                ep++;
            }
            else {
                corr[cp][0] = stt;
                corr[cp][1] = i - 1;
                cp++;
            }
            stt = i;
        }
    }
    if (ec[c]) {
        err[ep][0] = stt;
        err[ep][1] = c;
        ep++;
    }
    else {
        corr[cp][0] = stt;
        corr[cp][1] = c;
        cp++;
    }
    printf("Errors: ");
    for (int i = 0; i < ep; i++) {
        if (err[i][0] == err[i][1]) printf("%d", err[i][0]);
        else printf("%d-%d", err[i][0], err[i][1]);
        if (i < ep - 2) printf(", ");
        else if (i == ep - 2) printf(" and ");
    }
    printf("\nCorrect: ");
    for (int i = 0; i < cp; i++) {
        if (corr[i][0] == corr[i][1]) printf("%d", corr[i][0]);
        else printf("%d-%d", corr[i][0], corr[i][1]);
        if (i < cp - 2) printf(", ");
        else if (i == cp - 2) printf(" and ");
    }
    return 0;
}