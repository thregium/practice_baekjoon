#include <stdio.h>

/*
���� : �� �ڿ��� A, B�� ���� �� A^2 - B^2 = G�� �ڿ��� G(G <= 100000)�� �־��� ��, A�� ������ ���� ��� ���Ѵ�.

�ذ� ��� : 0���� G������ ��� �������� ������ ����, �� ������ �˰����� �̿��ϸ� �ȴ�.

�ֿ� �˰��� : ����, �� ������
*/

long long sq[103000];
int res[103000];

int main(void) {
	int g, p = 0;
	scanf("%d", &g);
	for (long long i = 0; i <= g; i++) {
		sq[i] = i * i;
	}
	int s = 1, e = 1;
	while (1) {
		if (e == g + 1) break;
		else if (sq[e] - sq[s] > g) s++;
		else if (sq[e] - sq[s] < g) e++;
		else if (sq[e] - sq[s] == g) {
			res[p++] = e;
			s++;
		}
	}
	if (p == 0) {
		printf("-1");
		return 0;
	}
	for (int i = 0; i < p; i++) {
		printf("%d\n", res[i]);
	}
}