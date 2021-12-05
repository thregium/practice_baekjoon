#include <stdio.h>
#include <stdlib.h>

/*
���� : 20�� ������ �����ڷ� �̷���� ������ �ϳ��� ����ϴ� ������ ����Ѵ�. �� ������ ����, ����, ����, �������̰�,
������ �� �׻� ���� ������ �ֵ��� �־�����. ������ ������ ������ ���� �� �ִ�.

�ذ� ��� : ���� ������ ���� �����ڵ��� �Ľ��� ����, �տ������� ������ �������� ����� ������.
�� �� �ٽ� ������ ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����, �Ľ�

��ó : MidC 1996 E��
*/

char op[32], s[16];
int num[32], level[32];

void print(int cnt) {
	for (int i = 0; i < cnt; i++) {
		printf("%d ", num[i]);
		printf("%c ", op[i]);
	}
	printf("%d ", num[cnt]);
	printf("= %s\n", s);
}

int main(void) {
	int cnt, cur;
	char equal;

	//freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM6\\ALGEBRA.IN", "r", stdin);
	//freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM6\\ALGEBRA_T.OUT", "w", stdout);

	while (1) {
		cnt = 0;
		while (1) {
			if (scanf("%d ", &num[cnt]) == EOF) return 0;
			scanf("%c ", &op[cnt]);
			cnt++;
			if (op[cnt - 1] == '=') break;
		}
		cnt--;
		scanf("%s", s);
		print(cnt);

		cur = 0;
		for (int i = 0; i < cnt; i++) {
			if (op[i] == '*' || op[i] == '/') level[i] = cur++;
		}
		for (int i = 0; i < cnt; i++) {
			if (op[i] == '+' || op[i] == '-') level[i] = cur++;
		}

		for (int i = 0; i < cnt; i++) {
			for (cur = 0; level[cur] != i; cur++);
			switch (op[cur]) {
			case '+': num[cur] += num[cur + 1]; break;
			case '-': num[cur] -= num[cur + 1]; break;
			case '*': num[cur] *= num[cur + 1]; break;
			case '/': num[cur] /= num[cur + 1]; break;
			}
			for (int i = cur + 1; i < cnt; i++) {
				num[i] = num[i + 1];
				op[i - 1] = op[i];
				level[i - 1] = level[i];
			}
			print(cnt - i - 1);
		}
		printf("\n");
	}
}
