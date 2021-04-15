#include <stdio.h>
#include <string.h>

/*
문제 : 자연수 N(N <= 10^18)이 주어질 때, N보다 크거나 같으며 모든 숫자의 등장 횟수가 같은 첫 수(같은 자리 수)를 구한다.

해결 방법 : 맨 뒷자리부터 시작해서 (첫 번째 자리부터 현재 자리까지 확인했을 때 이후 자리를 채워서 같은 자리 수를 만들 수 있는지) 를 확인한다.
이것이 가능하다면 뒷 자리로 옮기고, 불가능하다면 현재 자리를 1 올린다. 이때, 자릿수가 넘어간다면 앞 자리로 옮긴다. 가장 뒷자리에서 가능한 것이 확인되었다면 그 때의 수를 출력한다.
같은 자리 수를 만들 수 있는지는 {(가장 많이 등장한 숫자)와 (그보다 적게 등장한 숫자)의 등장 횟수 차}를 전부 합한 것이 남은 뒷 자리보다 클 때는 확실히 불가능하고,
작거나 같더라도 (등장할 수 있는 숫자의 가짓수 * 가장 많이 등장할 수 있는 등장 횟수)가 자릿수와 같은 경우가 없다면 불가능하다. 같은 경우가 있는 경우에만 가능하다고 할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 백트래킹
*/

char a[32];

int ispossible(int l, int x) {
    int cnt[10] = { 0, };
    int lar = 0, rem = 0, nums = 0;
    for (int i = l; i <= x; i++) {
        cnt[a[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (cnt[i] > lar) lar = cnt[i];
    }
    for (int i = 0; i < 10; i++) {
        if (cnt[i]) {
            rem += cnt[i];
            nums++;
        }
    }
    if (lar * nums - rem <= 30 - x) {
        for (int i = nums; i <= 10; i++) {
            for (int j = lar; i * j < 32; j++) {
                if (i * j - rem == 30 - x) return 1;
            }
        }
        return 0;
    }
    else return 0;
}

int main(void) {
    char n[32] = { 0, };
    int d = 30, l, p;
    scanf("%s", &n);
    l = 31 - strlen(n);
    strcpy(a + l, n); 
    while (d < 31) {
        if (ispossible(l, d)) {
            d++;
        }
        else {
            if(a[d] != '9') a[d]++;
            else {
                a[d] = '0';
                for (p = d - 1; a[p] == '9'; p--) {
                    a[p] = '0';
                }
                if(a[p]) a[p]++;
                else {
                    a[p] = '1';
                    l = p;
                }
                d--;
            }
        }
        //printf("%s\n", &a[l]);
    }
    printf("%s", &a[l]);
    return 0;
}