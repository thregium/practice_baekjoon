#include <stdio.h>

/*
문제 : 2019년부터 N(N <= 100000)년까지 누적되는 13일의 금요일의 개수를 구한다.

해결 방법 : 각 연도와 달마다 13일이 무슨 요일인지 확인하고 금요일인 것의 개수를 세면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 수학

출처 : 한양대 5회B E번
*/

int days[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

int isleap(int x) {
    if (x & 3) return 0;
    else if (x % 400 == 0) return 1;
    else if (x % 100 == 0) return 0;
    else return 1;
}

int main(void) {
    int n, r = 0, stt = 2;
    scanf("%d", &n);
    for (int i = 2019; i <= n; i++) {
        if (isleap(i)) {
            for (int j = 1; j <= 12; j++) {
                if ((days[j] + (j > 2) + stt + 12) % 7 == 5) r++;
            }
            stt = (stt + 2) % 7;
        }
        else {
            for (int j = 1; j <= 12; j++) {
                if ((days[j] + stt + 12) % 7 == 5) r++;
            }
            stt = (stt + 1) % 7;
        }
    }
    printf("%d", r);
    return 0;
}