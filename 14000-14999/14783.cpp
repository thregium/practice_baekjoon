#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 2300)명이 원형으로 앉아있다. 이때, 길이 L(L <= 10)의 수열이 주어지면, 해당 수열을 순서대로 적용하며
남아있는 사람 가운데 해당 수열의 수만큼 이동한 사람을 제거한다. 수열이 끝나면 다시 첫 원소를 적용한다.
마지막에 남는 사람의 번호를 구한다.

해결 방법 : 1부터 N까지 큐에 순서대로 저장한 다음, L_i - 1번은 큐의 맨 앞 수를 맨 뒤로 보내고, 그 다음 오는 수를
큐에서 삭제한다. 이를 큐의 크기가 1이 될 때 까지 반복한 다음 큐에 남은 수를 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 큐

출처 : USACO 2006O B2번
*/

int seq[16];
queue<int> q;

int main(void) {
    int n, l, x;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < l; i++) {
        scanf("%d", &seq[i]);
    }
    for (int i = 0; i < n; i++) q.push(i + 1);
    for (int i = 0; q.size() > 1; i++) {
        for (int j = seq[i % l]; j > 0; j--) {
            x = q.front();
            q.pop();
            if (j > 1) q.push(x);
        }
    }
    printf("%d", q.front());
    return 0;
}