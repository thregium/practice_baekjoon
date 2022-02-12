#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 10000)���� ����� �̸�(7��)�� ����(<= 100000, �ڿ���)�� �־��� ��, K(K <= N)�� ���ϸ�
�ذ��Ͽ� D(D <= 10^9) �̻��� �����ϴ� ����� �ִ� �� ���ϰ�, �ִٸ� �׷��� ����� ����Ѵ�.
���ٸ� impossible�� ����Ѵ�.

�ذ� ��� : ���� ������ ���� K���� ������ �ذ��ϴ� ���� ���� ���� ���� �����ϴ� ����̴�.
�׷��� ������� ������ �� �ִ� ���ް� D�� ���Ͽ� D�� �� ū ��� impossible�� ����ϰ�,
�� �ܿ��� ���� ������ ���� K���� �ذ��ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : GCPC 2017 K��
*/

typedef struct employee {
    char name[16];
    int salary;
} employee;

employee emp[10240];

int cmp1(const void* a, const void* b) {
    employee ai = *(employee*)a;
    employee bi = *(employee*)b;
    return ai.salary < bi.salary ? 1 : ai.salary == bi.salary ? 0 : -1;
}

int main(void) {
    int n, d, k;
    long long save = 0;
    scanf("%d %d %d", &n, &d, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", &emp[i].name, &emp[i].salary);
    }
    qsort(emp, n, sizeof(employee), cmp1);
    for (int i = 0; i < k; i++) {
        save += emp[i].salary;
    }
    if (save < d) printf("impossible");
    else {
        printf("%d\n", k);
        for (int i = 0; i < k; i++) {
            printf("%s, YOU ARE FIRED!\n", emp[i].name);
        }
    }
    return 0;
}