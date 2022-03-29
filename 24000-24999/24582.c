#include <stdio.h>
#include <string.h>
#define DIV 100000

/*
���� : ���� 20 ������ '(', '{', '[', '<', '>', ']', '}', ')', '?'�� �̷���� ���ڿ��� �־�����.
�� ���ڿ��� '?'�� �ٸ� ���ڷ� �ٲپ� ��ȣ ���ڿ��� �̷絵�� �ϴ� ����� �������� ���Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� �̿��Ѵ�. �� ���������� �������� �迭�� �����ذ���
������ �������鼭 �������� �� ������. �� ������ �������� ��� �������� �� �κ� �������� �������� ��
�� �κ� ������ ������ ���� �հ� ������, ���� �� �ִ� ������ ���� ���� ���ų� ������ '?'�� ����̴�.
���� �� �������� ���� ���� �ٸ����� �߿��� ���� ���� ��ʷ� 1�� ������ �Ѵ�.
�̸� �ݺ��ϸ� ���� ã�Ƴ����� �ȴ�.

�ֿ� �˰��� : DP

��ó : MidAtl 2021 F��
*/

char sr[256];
long long mem[256][256];
char* pr = "({[<)}]>";
int n, d = 0;

long long find(int s, int e) {
    if (s > e) return 1;
    if (mem[s][e] >= 0) return mem[s][e];

    mem[s][e] = 0;
    for (int m = s + 1; m <= e; m += 2) {
        for (int i = 0; i < 4; i++) {
            if ((sr[s] == pr[i] || sr[s] == '?') && (sr[m] == pr[i + 4] || sr[m] == '?')) {
                mem[s][e] = mem[s][e] + find(s + 1, m - 1) * find(m + 1, e);
                if (mem[0][n - 1] >= DIV) d = 1;
                //mem[s][e] %= DIV;
            }
        }
    }
    return mem[s][e];
}

int main(void) {
    long long r;
    //scanf("%d", &n);
    scanf("%s", sr);
    memset(mem, -1, sizeof(mem));
    r = find(0, strlen(sr) - 1);
    //if (d) printf("%05lld", r);
    //else printf("%lld", r);
    printf("%lld", r);
    return 0;
}