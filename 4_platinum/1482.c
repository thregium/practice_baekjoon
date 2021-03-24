#include <stdio.h>
#include <string.h>

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