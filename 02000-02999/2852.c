#include <stdio.h>
#include <stdlib.h>

/*
���� : 48���� �� ���ӿ��� �� ���� ������ N(N <= 100)ȸ �־�����.
��� ������ ���� ������� �� ���� �̱�� �ִ� �ð��� ���� ����Ѵ�.

�ذ� ��� : �� ���� ������ �ð��� �������� ������������ ������ ����, ���� �� ���� �������� �̱�� �ִ� ����
�ð��� �ֱ� ���������� �ð���ŭ �߰��Ѵ�. �� ���� ���� �߰��Ѵ�. �̸� �ݺ��� ���� �� ���� �¸� �ð��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : COCI 10/11#5 2��
*/

int goal[128][2];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, h, m, x, l = 0, ag = 0, bg = 0, aw = 0, bw = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d:%d", &goal[i][0], &h, &m);
        goal[i][1] = h * 60 + m;
    }
    qsort(goal, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (ag > bg) aw += goal[i][1] - l;
        else if (ag < bg) bw += goal[i][1] - l;
        if (goal[i][0] == 1) ag++;
        else if (goal[i][0] == 2) bg++;
        l = goal[i][1];
    }
    if (ag > bg) aw += 2880 - l;
    else if (ag < bg) bw += 2880 - l;
    printf("%02d:%02d\n%02d:%02d", aw / 60, aw % 60, bw / 60, bw % 60);
    return 0;
}