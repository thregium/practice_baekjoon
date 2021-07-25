#include <stdio.h>

/*
문제 : 각 명령들의 사용 기록이 주어질 때, 이전 명령 버튼을 몇 회 눌러야 해당 순서로 명령들을 사용할 수 있는지 구한다.
단, 주어지는 기록의 수들은 처음 상태에서 해당 명령을 실행하기 위해 이전 명령 버튼을 눌러야 하는 횟수다.

해결 방법 : 주어진 명령들을 순서대로 배열에 저장해 놓는다. 명령을 입력받으면 배열을 역순으로 따라가며
사용한 명령들 중에 있는지 확인한다. 있다면 해당 위치에서 탐색을 종료하고 명령을 다시 받는다.
없는 경우에는 해당 명령의 번호만큼 수를 추가한 다음 다시 명령을 받아야 한다.

주요 알고리즘 : 구현

출처 : Brasil 2007 E번
*/

int hist[1024];

int main(void) {
    int n, r, found;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2007\\hist.in", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &hist[i]);
            found = 0;
            for (int j = i - 1; j >= 0; j--) {
                r++;
                if (hist[j] == hist[i]) {
                    found = 1;
                    break;
                }
            }
            if (!found) r += hist[i];
        }
        printf("%d\n", r);
    }
    return 0;
}