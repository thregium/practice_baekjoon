#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
문제 : N(N <= 500000)개의 자연수(< 2^31)가 주어질 때, 사이에 더 큰 수가 없는 쌍의 개수를 구한다.

해결 방법 : 스택 2개을 사용한다. 한 개는 단조 감소하도록 스택을 설정하고, 다른 한 개는 연속한 같은 수의 개수를 센다.
이때, 맨 밑에 있는 수의 경우에는 그 값에서 1을 뺀 값을 설정해야 한다.
매번 스택에서 원소를 뺄 때마다 결괏값에 1을 더하고, 원소를 넣을 때 마다 두 번째 스택의 맨 위에 있는 값을 더해나가면
답이 된다.

주요 알고리즘 : 자료 구조, 스택

출처 : COI 2007 1번
*/

int d[524288], st[524288], st2[524288];
int top = 0;

int main(void) {
    int n, t, c = 0;
    long long r = 0;
    //srand(time(NULL));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
        //d[i] = rand() % 10;
    }
    for (int i = 0; i < n; i++) {
        while (top > 0 && st[top - 1] < d[i]) {
            top--;
            r++;
        }
        st[top] = d[i];
        st2[top] = (top <= 0 ? 0 : st[top] != st[top - 1] ? 1 : st2[top - 1] + 1);
        top++;
        if (top > 1) r += st2[top - 1];
    }
    printf("%lld\n", r);
    /*
    r = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            c = 1;
            for (int k = i + 1; k < j; k++) {
                if (d[k] > d[i] || d[k] > d[j]) c = 0;
            }
            r += c;
        }
    }
    printf("%lld", r);
    */
    return 0;
}