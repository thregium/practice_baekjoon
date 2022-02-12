#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10000)명의 사원의 이름(7자)과 봉급(<= 100000, 자연수)이 주어질 때, K(K <= N)명 이하를
해고하여 D(D <= 10^9) 이상을 절약하는 방법이 있는 지 구하고, 있다면 그러한 방법을 출력한다.
없다면 impossible을 출력한다.

해결 방법 : 가장 봉급이 많은 K명의 직원을 해고하는 것이 가장 돈을 많이 절약하는 방법이다.
그러한 방법으로 절약할 수 있는 봉급과 D를 비교하여 D가 더 큰 경우 impossible을 출력하고,
그 외에는 가장 봉급이 많은 K명을 해고하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : GCPC 2017 K번
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