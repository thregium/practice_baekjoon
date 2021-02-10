#include <stdio.h>
#include <string.h>

/*
문제 : 미리 주어진 출력과 동일한 출력이 나오도록 코드를 만든다. 단, 코드의 길이는 10만 바이트 이하여야 한다.

해결 방법 : 여기에 다 쓰기에는 여백이 부족하므로 아래 주석들을 참고한다.

주요 알고리즘 : 구현, 문자열, 수학, 정수론, 다이나믹 프로그래밍 등등
*/

#define DEBUG 0
#define FOUT 0
#define DIR "C:\\1_공부\\PS\\백준\\문제 관련\\genzaw\\"
#define CONST1 9099099909999099999

char triangle[1280][1280], sieve[409600], board7[512][1024], spiral[1024][1024], board9[1024][1024], ot10_a[7680], ot10_a_1[5120], ot10_a_n[7680], ot10_x[80][80];

int comparefile(int x) {
    char d[256], d2[256];
    char xc[3] = { x + '0', 0, 0 };
    if (x == 10) {
        xc[0] = '1';
        xc[1] = '0';
    }
    char c1, c2;
    int p = 0, r = 0;

    strcpy(d, DIR);
    strcat(d, "gen");
    strcat(d, xc);
    strcat(d, ".out");
    strcpy(d2, DIR);
    strcat(d2, "ngen");
    strcat(d2, xc);
    strcat(d2, ".out");

    FILE* src = fopen(d, "r");
    FILE* cmp = fopen(d2, "r");
    if (!src || !cmp) {
        printf("file open error!");
        return -1;
    }
    
    while (!feof(src) || !feof(cmp)) {
        c1 = fgetc(src);
        c2 = fgetc(cmp);
        if (c1 != c2) {
            printf("c1 : %c(%d), c2 : %c(%d) at %d\n", c1, c1, c2, c2, p);
            r++;
            //return p;
        }
        p++;
    }

    if (!r) {
        printf("Looking Good!");
    }
    return r;
}

//ONTAK 2010 출력, 참 쉽죠?
void ot0(void) {
    char d0[256];
    if (FOUT) {
        strcpy(d0, DIR);
        strcat(d0, "ngen0.out");
        FILE* f0 = fopen(d0, "w");
        fprintf(f0, "ONTAK 2010\n");
        fclose(f0);
    }
    else {
        fprintf(stdout, "ONTAK 2010\n");
    }
}

//Godzilla 어쩌구 문자 출력, 각 문자는 2932 - n ^ 2 % 2932(양수) 번씩 반복된다. (n = 문자의 위치 번호)
void ot1(void) {
    char d1[256];
    FILE* f1;
    if (FOUT) {
        strcpy(d1, DIR);
        strcat(d1, "ngen1.out");
        f1 = fopen(d1, "w");
    }
    int x = 0, y = 0;
    char c[] = "Godzilla terrorizes Bajtoly lower again. Every day a monster comes out of the ocean, slow movement of marching through the city to some of the skyscrapers and eats it with people who are in it. Eating one skyscraper takes the whole day, at dusk, it returns to its hiding place hidden in the depths. To make matters worse, going through the city, Godzilla wags its tail and destroys towers, near the passes. The prospect of becoming a meal for an underwater monster, to discourage some residents spent in uncomfort- tion in the city. During the night of each tower is derived as a resident and flees to the countryside. In Bajtogrodzie skyscrapers were built only at street crossings. At each intersection there is exactly one building. Junctions are connected by two-way streets. In addition, a the junction is just above the ocean, this is where Godzilla begins its destructive journey through the city. During the investigation, the monster moves only in the streets. Godzilla noted that he must hurry up with the consumption of residents and carefully choose the skyscrapers devouring and streets, which reaches them. Of course, choosing never previously consumed or destroyed- wanego skyscraper. What is the maximum number of people who can eat before the city completely desolate? Entrance The first line of standard input contains two integers him (1 n 100 000, 0 500 000 m) respectively denoting the number of intersections in the city and the number of connecting streets. Crossroads numbers are numbered from 1 to n, junction 1 is located on the shores of the ocean. Next row contains a sequence of integers n s (0 s 100 000) to describe population skyscrapers at various intersections. In each of the next m rows are the two integers ai and bi (1 ai, bi n, ai = bi), which means that there is a road junction connecting ai and bi. The crossing number One can reach any other intersection in the city. Exit Write to stdout the number of people who eat Godzilla for the optimum choice of meals and roads through the city every day. Example For input: the result is correct: 5 5 11 1 3 2 4 7 1 2 1 3 2 3 2 4 3 5";
    for (int cc = 0; cc < strlen(c); cc++) {
        y = (2932 - x * x) % 2932;
        if (y <= 0) y += 2932; // x ^ 2이 2932 이상이 되는 경우 문자의 반복횟수가 0보다 작아지지 않도록 2932를 더한다.
        for (int i = 0; i < y; i++) {
            fputc(c[x], FOUT ? f1 : stdout);
        }
        x++;
    }

    fprintf(FOUT ? f1 : stdout, "\n");
    if (FOUT) {
        fclose(f1);
    }
}

//피보나치 수열 (mod 9099099909999099999)을 10000번째까지 출력하고, 마지막에는 0을 출력한다.
void ot2(void) {
    char d2[256];
    FILE* f2;
    if (FOUT) {
        strcpy(d2, DIR);
        strcat(d2, "ngen2.out");
        f2 = fopen(d2, "w");
    }

    unsigned long long fibo1 = 1, fibo2 = 0, t; // 나눗수가 2 ^ 62보다 크므로 unsigned형을 사용한다.
    for (int i = 0; i < 10000; i++) {
        fprintf(FOUT ? f2 : stdout, "%lld, ", (fibo1 + fibo2) % CONST1);
        t = fibo1;
        fibo1 = fibo2;
        fibo2 = (t + fibo1) % CONST1;
    }

    fprintf(FOUT ? f2 : stdout, "0.\n");

    if(FOUT) {
        fclose(f2);
    }
}

/*
시어핀스키 삼각형을 역순으로 출력한다. (n = 10)
506~510번째 줄에 ONTAK 2010 문자에 주의해야 한다.
*/
void ot3(void) {
    char d3[256];
    FILE* f3;
    if (FOUT) {
        strcpy(d3, DIR);
        strcat(d3, "ngen3.out");
        f3 = fopen(d3, "w");
    }
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j <= i; j++) {
            //시어핀스키 삼각형은 비트 연산을 통해 간단히 만들 수 있다.
            if ((i & j) == j) {
                triangle[1023 - i][j] = '#';
            }
            else {
                triangle[1023 - i][j] = '.';
            }
        }
    }

    //비트마스킹을 통해 ONTAK 2010 문자 형태를 압축해서 출력할 수 있다.
    long long otx[5] = { 1097158404873378206, 1851883661379705779, 1851879948939369907, 1851877476661402035, 1094911140585216414 };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 61; j++) {
            if ((otx[i] >> j) % 2) {
                triangle[506 + i][449 + j] = '#';
            }
        }
    }


    for (int i = 0; i < 1024; i++) {
        fprintf(FOUT ? f3 : stdout, "%s\n", triangle[i]);
    }
    if (FOUT) {
        fclose(f3);
    }
}

/*
2에서 400001까지 수들의 소수 여부를 담은 소수표를 출력한다. 한 줄에 숫자는 80개씩 들어가고, 총 5천 줄로 이루어져 있다. 소수인 경우 0, 소수가 아닌 경우 1을 출력한다.
단, 266650부터 266668 사이 수는 소수 여부와 상관없이 9099099909999099999를 출력해야 한다.
*/
void ot4(void) {
    char d4[256];
    FILE* f4;
    if (FOUT) {
        strcpy(d4, DIR);
        strcat(d4, "ngen4.out");
        f4 = fopen(d4, "w");
    }

    int primes[256];
    int isp, pp = 0;
    //미리 1000 이하의 소수들을 확인한다.
    for (int i = 2; i < 1000; i++) {
        isp = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isp = 0;
                break;
            }
        }
        if (isp) {
            primes[pp++] = i;
        }
    }
    //에라토스테네스의 체를 사용한다.
    for (int i = 0; i < pp; i++) {
        for (int j = primes[i] * primes[i]; j < 401200; j++) {
            if (sieve[j]) continue;
            if (j % primes[i] == 0) sieve[j] = 1;
        }
    }

    //266650 ~ 266668번째 수에 대한 처리
    char thatnum[] = "9099099909999099999";
    for (int i = 0; i < 19; i++) {
        sieve[i + 266650] = thatnum[i] - '0';
    }

    for (int i = 0; i < 5000; i++) {
        for (int j = 0; j < 80; j++) {
            fprintf(FOUT ? f4 : stdout, "%d", sieve[i * 80 + j + 2]);
        }
        fprintf(FOUT ? f4 : stdout, "\n");
    }

    if (FOUT) {
        fclose(f4);
    }
}

/*
폴란드어로 되어있는 달력이다.
( a월 b일은 x일입니다. y년의 ) 형태로 되어있으며, 각각의 숫자는 전부 폴란드어식으로 쓰여있다. 숫자 문법은 영어와 비슷하고, 각각의 달마다 고유한 이름이 있다.
10 + n일은 nasty가 붙고, n * 10일은 ziesty가 붙는 식이고, n * 100과 n * 100 + m 의 표기 방식에 차이가 있으므로 주의한다.
또한, 2007년 4월 1일과 2013년 6월 1일은 다른 문장을 출력해야 한다.
*/
void ot5(void) {
    char d5[256];
    FILE* f5;
    if (FOUT) {
        strcpy(d5, DIR);
        strcat(d5, "ngen5.out");
        f5 = fopen(d5, "w");
    }

    // 한 달의 일 수 (평년 기준)
    int daysofmonths[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // 각 달, 한 자릿수, 2 자릿수의 이름을 저장
    char* monthnames[12] = {"stycznia", "lutego", "marca", "kwietnia", "maja", "czerwca", "lipca", "sierpnia", "wrzesnia", "pazdziernika", "listopada", "grudnia"};
    char* numbers_od[10] = {"pierwszy", "drugi", "trzeci", "czwarty", "piaty", "szosty", "siodmy", "osmy", "dziewiaty", "dziesiaty"};
    char* numbers_tn[9] = {"jede", "dwu", "trzy", "czter", "piet", "szes", "siedem", "osiem", "dziewiet"}; // + nasty
    char* numbers_td[9] = {"jed", "dwud", "trzyd", "czterd", "piecd", "szescd", "siedemd", "osiemd", "dziewiecd"};
    // n * 10 : + ziesty, 100 : senty, 100 + n : sto, 200 : dwusenty, 200 + n : dwiescie, 300 : trzysenty, 300 + n : trzysta
    // 2000ed : dwutysiecznego, 2000 + n : dwa tysiace, ed : ego(-y)

    // 일 월 to x번째 dzien roku 연도.

    char year[64], month[16], day[32], date[64];
    int dt;

    for (int y = 2000; y <= 2020; y++) {
        // 윤년인 경우
        if (y % 4 == 0) {
            daysofmonths[2] = 29;
        }
        else {
            daysofmonths[2] = 28;
        }

        // 연
        if (y == 2000) {
            strcpy(year, "dwutysiecznego.");
        }
        else {
            strcpy(year, "dwa tysiace ");
            if (y <= 2010) {
                strcat(year, numbers_od[y - 2001]);
                if (year[strlen(year) - 1] == 'y') {
                    year[strlen(year) - 1] = '\0';
                }
                strcat(year, "ego.");
            }
            else if (y == 2020) {
                strcat(year, "dwudziestego.");
            }
            else {
                strcat(year, numbers_tn[y - 2011]);
                strcat(year, "nastego.");
            }
        }

        for (int m = 1; m <= 12; m++) {
            // 월
            strcpy(month, monthnames[m - 1]);

            dt = 0;
            for (int dtt = 1; dtt < m; dtt++) {
                dt += daysofmonths[dtt];
            }

            for (int d = 1; d <= daysofmonths[m]; d++) {
                // 일
                if (d <= 10) {
                    strcpy(day, numbers_od[d - 1]);
                }
                else if (d <= 19) {
                    strcpy(day, numbers_tn[d - 11]);
                    strcat(day, "nasty");
                }
                else {
                    strcpy(day, numbers_td[d / 10 - 1]);
                    strcat(day, "ziesty");
                    if (d % 10 > 0) {
                        strcat(day, " ");
                        strcat(day, numbers_od[d % 10 - 1]);
                    }
                }
                day[0] += 'A' - 'a';

                dt++;
                // 날짜
                if (dt >= 100) {
                    // 100 단위는 하드코딩으로 처리한다.
                    if (dt > 300) {
                        strcpy(date, "trzysta ");
                    }
                    else if (dt == 300) {
                        strcpy(date, "trzysetny");
                    }
                    else if (dt > 200) {
                        strcpy(date, "dwiescie ");
                    }
                    else if (dt == 200) {
                        strcpy(date, "dwusetny");
                    }
                    else if (dt == 100) {
                        strcpy(date, "setny");
                    }
                    else {
                        strcpy(date, "sto ");
                    }
                }
                if (dt % 100 == 0) {
                    // 생략
                }
                else if (dt % 100 <= 10) {
                    if(dt < 100) strcpy(date, numbers_od[dt % 100 - 1]);
                    else strcat(date, numbers_od[dt % 100 - 1]);
                }
                else if (dt % 100 <= 19) {
                    if (dt < 100) strcpy(date, numbers_tn[dt % 100 - 11]);
                    else strcat(date, numbers_tn[dt % 100 - 11]);
                    strcat(date, "nasty");
                }
                else {
                    if(dt < 100) strcpy(date, numbers_td[(dt % 100) / 10 - 1]);
                    else strcat(date, numbers_td[(dt % 100) / 10 - 1]);

                    if ((dt % 100) / 10 >= 5) {
                        strcat(date, "ziesiaty");
                    }
                    else strcat(date, "ziesty");
                    if (dt % 10 > 0) {
                        strcat(date, " ");
                        strcat(date, numbers_od[dt % 10 - 1]);
                    }
                }

                if (y == 2007 && m == 4 && d == 1) {
                    // 너는 정말로 바보구나!
                    fprintf(FOUT ? f5 : stdout, "Pierwszego kwietnia jest prima aprilis.\n");
                }
                else if (y == 2013 && m == 6 && d == 1) {
                    // 어린이날
                    fprintf(FOUT ? f5 : stdout, "Pierwszego czerwca jest dzien dziecka.\n");
                }
                else {
                    fprintf(FOUT ? f5 : stdout, "%s %s to %s dzien roku %s\n", day, month, date, year);
                }
            }
        }
    }

    // 끗
    fprintf(FOUT ? f5 : stdout, "Koniec.\n");
    if (FOUT) {
        fclose(f5);
    }
}

/*
a, b, c ... 를 배치해서 만들 수 있는 i ^ 4번째 순열을 출력한다.
먼저 순열의 길이를 확인한 다음(n개의 알파벳으로 만들 수 있는 순열은 n!개다.) 순열에서 이번 글자가 무엇인지 앞에서부터 차례로 확인한다.
남은 글자로 만들 수 있는 수열의 갯수와 비교하면 알 수 있다.
*/
void ot6(void) {
    char d6[256];
    FILE* f6;
    if (FOUT) {
        strcpy(d6, DIR);
        strcat(d6, "ngen6.out");
        f6 = fopen(d6, "w");
    }

    long long cb[32] = { 1, 0, }; // 20 이하 수의 팩토리얼을 저장한다.
    long long cbs[32] = { 0, }; // 20 이하 팩토리얼의 누적합을 저장한다.(쓰이지 않음)
    for (int i = 1; i <= 20; i++) {
        cb[i] = 1;
        for (long long j = 1; j <= i; j++) {
            cb[i] *= j;
        }
        cbs[i] = cbs[i - 1] + cb[i];
    }

    char l[32] = { 0, }; // 남은 알파벳을 저장하는 배열
    int x, lsz = 0; // 남은 알파벳의 수
    long long iq; // i의 네제곱
    for (long long i = 1; i <= 20000; i++) {
        iq = i * i * i * i;
        lsz = 0;
        for (int j = 1; iq > cb[j]; j++) {
            iq -= cb[j];
            l[lsz++] = 'a' + j - 1;
        }
        l[lsz++] = 'a' + lsz;

        fprintf(FOUT ? f6 : stdout, "T[%lld]=\"", i * i * i * i);

        x = lsz;

        // 1만일 때의 처리(9099099909999099999)
        if (i == 10000) {
            fprintf(FOUT ? f6 : stdout, "%lld", CONST1);
        }
        else {
            while (lsz) {
                for (int j = 0; j < x; j++) {
                    if (!l[j]) continue; // 이미 사용한 알파벳일 때
                    if (iq > cb[lsz - 1]) {
                        // 이번 알파벳 내에는 해당 번째가 오지 않을 때
                        iq -= cb[lsz - 1];
                    }
                    else {
                        fprintf(FOUT ? f6 : stdout, "%c", l[j]);

                        l[j] = '\0';
                        lsz--;
                        break;
                    }
                }
            }
        }
        

        fprintf(FOUT ? f6 : stdout, "\"\n");
    }

    if (FOUT) {
        fclose(f6);
    }
}

/*
3진수로 된 글자들이 적혀있다.
각 글자들은 1부터 시작해서 이전 수의 2배를 한 것을 (3진수 단위로) 뒤집은 것이다. 수가 각 줄의 맨 끝을 넘기는 경우 다음 줄로 넘긴다.
이 때 1의 넓이가 다른 숫자들과 다르다는 점에 유의한다.
마지막 4줄의 경우는 정확한 의미를 모르겠으므로 하드코딩을 한다.
*/
void ot7(void) {
    char d7[256];
    FILE* f7;
    if (FOUT) {
        strcpy(d7, DIR);
        strcat(d7, "ngen7.out");
        f7 = fopen(d7, "w");
    }

    int lwidth[10] = { 6, 3, 6, 2, 2, 0, 0, 0, 0, 6 }; // 각 글자들의 넓이
    int letter[10] = { 516898014, 28087, 1058639070, 704, 0, 0, 0, 0, 0, 516156638}; // 글자들의 형태는 위에서 했던것처럼 비트마스킹을 사용한다.

    for (int i = 0; i < 492; i++) {
        for (int j = 0; j < 1000; j++) {
            board7[i][j] = '.';
        }
    }

    char base3[256] = { 1, 0, };
    char rbase3[256] = { 0, };
    int line = 0, col = 0, blen = 1;
    int tcol;

    // 171회 반복
    for (int i = 0; i < 171; i++) {
        // 줄바꿈 검사
        tcol = col;
        for (int j = 0; j < blen; j++) {
            tcol += lwidth[base3[j]] + 1;
        }
        if (tcol >= 1000) {
            line += 6;
            col = 0;
        }
        // 각 글자들 저장
        for (int j = 0; j < blen; j++) {
            for (int lp = 0; lp < 5; lp++) {
                for (int cp = 0; cp < lwidth[base3[j]]; cp++) {
                    if ((letter[base3[j]] >> (lp * lwidth[base3[j]] + cp)) % 2) {
                        board7[line + lp][col + cp] = '#';
                    }
                }
            }
            col += lwidth[base3[j]] + 1;
        }
        for (int lp = 0; lp < 5; lp++) {
            for (int cp = 0; cp < lwidth[3]; cp++) {
                if ((letter[3] >> (lp * lwidth[3] + cp)) % 2) {
                    board7[line + lp][col + cp] = '#';
                }
            }
        }
        col += lwidth[3] + lwidth[4] + 1 + 1;

        // 각 단계의 수들은 이전 단계의 삼진수를 2배 한 것을 뒤집은 것이다.
        rbase3[0] = 0;
        for (int j = 0; j < blen; j++) {
            rbase3[j] += base3[j] * 2;
            if (rbase3[j] > 2) {
                rbase3[j] -= 3;
                rbase3[j + 1] = 1;
                if (j + 1 == blen) {
                    blen++;
                    break;
                }
            }
            else {
                rbase3[j + 1] = 0;
            }
        }
        for (int j = 0; j < blen; j++) {
            base3[j] = rbase3[j];
        }
    }

    // 0과 마침표를 찍는다.
    for (int lp = 0; lp < 5; lp++) {
        for (int cp = 0; cp < lwidth[0]; cp++) {
            if ((letter[0] >> (lp * lwidth[0] + cp)) % 2) {
                board7[line + lp][col + cp] = '#';
            }
        }
    }
    col += lwidth[base3[0]] + 1;
    board7[line + 3][col + 0] = '#';
    board7[line + 3][col + 1] = '#';
    board7[line + 4][col + 0] = '#';
    board7[line + 4][col + 1] = '#';
    line += 7;
    col = 0;

    // 마지막 4줄은 하드코딩을 한다. 압축이 가능하겠지만 난 귀찮음
    char* lastletters[4] = { "01020102001020021020001020010200120000120001200102010200120120012001200102012001020102012001020102010102010201200120012012001220100200012002010201020102010200",
        "120012012001200120012001200120012001200120012012001201002000102001201200020020010020102001200001020102000120002010200102020000102001202002102001200202010201",
        "0201020010020201020201020200120010001200201200102012001200120102012002100002010200010200012022020012020102020102020102010909909990999909999902010200120012",
        "0012010201020102012001201201020120102012002001020012001200120012000120012001200210200120000120012001201200120102001001001001010100101000020102010200102001020001" };
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < strlen(lastletters[i]); j++) {
            for (int lp = 0; lp < 5; lp++) {
                for (int cp = 0; cp < lwidth[lastletters[i][j] - '0']; cp++) {
                    if ((letter[lastletters[i][j] - '0'] >> (lp * lwidth[lastletters[i][j] - '0'] + cp)) % 2) {
                        board7[line + lp][col + cp] = '#';
                    }
                }
            }
            col += lwidth[lastletters[i][j] - '0'] + 1;
        }
        line += 6;
        col = 0;
    }

    // 최종 출력
    for (int i = 0; i < 492; i++) {
        for (int j = 0; j < 1000; j++) {
            fprintf(FOUT ? f7 : stdout, "%c", board7[i][j]);
        }
        fprintf(FOUT ? f7 : stdout, "\n");
    }

    if (FOUT) {
        fclose(f7);
    }
}

/*
불규칙한 스파이럴을 출력해야 한다.
수식을 통해 스파이럴을 출력하기는 어려우므로 하드코딩을 한다. 자세히 보면 스파이럴은 극히 일부 예외를 제외하고는 왼쪽으로 45도 회전, 직진, 오른쪽으로 45도 회전
이 3 가지 경우만 사용하므로 3진법을 통해 데이터 양을 줄일 수 있고, 컴퓨터 상에서는 81가지 문자를 이용하여 Base81을 구현하는 방식으로 용량을 줄일 수 있다.
위 규칙에 들어맞지 않는 경우는 직접 처리한다.
*/
void ot8(void) {
    char d8[256];
    FILE* f8;
    if (FOUT) {
        strcpy(d8, DIR);
        if (FOUT < 0) {
            strcat(d8, "gen8.out");
            f8 = fopen(d8, "r");
        }
        else {
            strcat(d8, "ngen8.out");
            f8 = fopen(d8, "w");
        }
    }

    int c = 0, r; // 현재까지의 칸수, (이전에 대한) 상대 방향
    char bs = 0; // 최근 4칸의 글자 변환값
    char rbs[4] = { 0, }; // 글자 -> 3진수 변환값

    int x = 717, y = 48, d = 4; // 세로, 가로, 방향 (12시부터 시계방향으로)
    int dirxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} }; // 각 방향별 xy좌표 변화
    char base81[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz<[{()}]>!@#$^&*-=_+"; // base81 지정 (인코딩)
    char rbase81[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 70, -1, 72, 73, -1, 75, -1, 65, 66, 76, 80, -1, 77, -1, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, 62, 78, 69, -1,
    71, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 63, -1, 68, 74, 79,
    -1, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 5, 58, 59, 60, 61, 64, -1, 67, -1, -1 }; // base81 지정 (디코딩)

    // 전체 경로 하드코딩
    char* track = "BX(KXyyyyylJxJxEEEEDkeeeeeeeceeced}d}d}d}d}d}d}ceYd}MYYYYML(X(Ly(KKKFyxJxJxFkkwwwwwwkgfDwgfDkfDgewgekfDgewgekfDgekewewegeekeeeeeeeeeed}eYeMcd}MYYMML(YL(YKYKX(Ly(KXzKLy(KXzKKXzKLyzKKLyyyyyyyylFxJxFkkkkfDeeeeYeceYccccccYML(cYL(YML(YL(cYL(YL(L(L(KXzKKKKKJyxJxFkxFgkkggewkewfDekeekeeekeeeeegeeeeeefDeeeeeefDeeeeeeeeYeeeceeMd}cd}MMYML)(YKYKXzKKKKKKKKFyxKFylFylFxKFxKFxJylJxJykxFkxEFgfDweeeeeYeYccccYL(X(LzKKXyzKKKKKLyyyyyyzKKKKKKKKKKJyylJylFxFkxEFggfDwkfDfDegeeeeeeeeeeeceeeYeeYeeYeeMeeMed}ed}eYed}eYeYeMceMYcd)))(YYKYLzKKXyyylJylFkxFkkwwxEDwwwwwwkkkkkgggfEDwgeweeeeeed}cd))(YL(Ly(KKKKJyylFxJylFlFxFlFlFlFlFkykykxJxFkxFkxFgkkkkgfDwgegeeweeeeeeeeYeeMeMd}cd}Ycd}MYcd)}MYccd}MYYcd)}MMYYYYYYYML(cL(X(Xy(KKKJyxFxEFgggewgeeweeekeeeeeeeeeeeeeeeeeMed}cd)))(YLzKXyyyyxJylFkxFkxEFggggkggggggfEEEEDwwwwwwkkkgfEDwgfDgekegeeeweeeeYeeced}Yd}MYYYYYML(cYL(YL(YL(YKYL(YL(YL(L(YLzL(LzKXzKKKKKKFykxFkkkgeeeeeeed}d}Yd}Ycd}MYcd}Mcd}MYcccd)(cYL(X(LyzKJyyxJxJxEFkkkkggewkfDgekekegegefDewekegegefDewegeekeeeweeeeeed}ed}d}cd}MMYML(YL(X(LzKLyy(KKKKLyyyyyyyzKKKKKKKKKKKKFylJxJxFgggeweeeYed}YccccYL(YL(L(L(L(LzLzLzLzLzKYKXzKLyy(KJyyxJykxFkwwwwwkfDkekeeweeeegeeeeeeeeeceeeeeeeeeeeeeeeeeed}eed}ececeMcd))))(YL(X(KXyyyyyxKFxJykxJxFlFkxJxFlFkxJxFkxFkkwwwkgeeeeed}cd))(YL(Ly(KKKXxKKKKJyyylKKFyyylKKJyyxKJyxJylFkxFkwxEDwwgeweweekeeeeed}eeceeYececeYeYeYeMeMeMd}d}d}ceYeMceMYcd))))(YL(X(LyyyyyxJxJxEFgggfDwkfDkfDkfDkfDkgewfDgeeeeeeMeYd))(YL(KXyyyyxKFxJxJxFkxFkxFkwxFkxFkxFkwxFkxFgkwxEEEEDwkfDkegeeegeeYeeeYeceYd}MYcd)))))))))))(cccccccccccYYYML)(YL(YKX(KLyyxKFxFkwwwkfDeeeeeeYeeed}eed}eeeceeeMeYeMYcccYL(LyzKKFyxJxFwxFkkkkkkggfDwkgewkgfDwgfDwkgfDwkfDwgekeweweekeeeeeeMed}d}Ycd)))(cYL(YKYLzKYKX(LzKYKX(L(LzLzKX(Ly(KLyyyyxKFlFkkkgeeeeeeceYd)}MMMMML))(cccccYYYYYML)(YLzLzKKKKKKFxJxFkwwwwkgfDkekekeeweekeefDeegeeeweekeefDeefDeeeeeeeeeYed}d}Yccd(cYL(YKX(KLyyyyyylKKFyylKKFyyylKKJyyxKFylFkxFkkkgeeeececeMML(YL(LzKXzKKXy(KXy(KXzKLy(KLyyzKKKFyylFxFkxEFfEDwgekegeeeeeeeeeeeeeceeeeMeeed}eeeeYeeeeMeed}eYeYeMcd))))(YL(XzKKKKKJyxFxFkxEFkkwxEFgkwxFgkwxFggkkgfDkeeeYeeMYYYL(X(KLyyylKJyxKFxKFxJylJylJylJylJylFxFxFkxFkkkkkgewfDegeeeeeed}ed}d}ceYd}Yd}Mcd}Yd}YceMceMceMYd}MYYccYYML(X(Ly(KKFylFkxEEDwkewekefDefDegeewekeeeeeeeed}cd))(X(LyyyyyxJykxFkxEFkkwwxEEFggkkkwxEFgkkwwxEEDwwkgfDgegeeeej}eeececeYcd}MMMML)(cYL)(YML(cYML(cYML)(YML(X(YKX(KLyylJykxFgfDeeeeeed}eMd}ceYeMeMeMeMeMd}YccccYX(X(KKKKFxJxFkwxEEDwkgewgewfDgekewfDkewgewfDkewfDfDeweegeeeed}ed}d}YccccYYL(L(LzKXzKKXy(KLyzKKXzKLy(KLyzKKKKKJyxFxEFgeweeYeeYcd))(cYL(YL(YL(YL(cYL(YYL(X(X(LyzKKFyxJxFkwwwwwgewewegeeefDeeeeeeeefDeeeeeegeeeeeeeeeeeeeYed}d}MYccYYL(X(KXyyyyylJyxJylFlFxJyxJyxJyxJylFkygkwwkeeeeeeMYYYL(YKXy(KKKKKKKKKKKKLyyyyyy(KKKJyyylFxJxFgkkkgfDgeeweeeeeeeeYeeceeYeceeMed}eceeYeeYeeMeYeYeMcd}MMML(YLzKKXylKFxFkwxEEEDwwkggfEEDwwwwwwkkfDkeeeeYeYccYL(LyyyyyylFxJxJxFxFkxJxFxFlFlFlFlFkykxFgkkwkkgewfDeeweeeMeeYeYeMcd}MYYccd))}MMYccd}MYYcd}MMMMMML(cL(X(KKKKJykxEEDwgeefDeeeeeeeeeeeeeeeeceeeMcd))(X(KXyxKJxJxFkkwwwwwwwkkggfEDwwwwkkkkkkkggfDwkfDgeeweeeeeeMeceMccd)(cYYL(YKYL(L(YKYL(YLzL(YL(YL(LzKXzKKKJylFkkkgeeeYeeMd}MYccd)}MMYceMYcd}MYYYYL(X(LyyylJykxEFggfDwgekekegeewegeewegegefDfDewekeeweeeeeeeeced}YccccYYKYKXzKKLyyyyyyyyyyyyyyyy(KKKKKKJyxJxJkwkeeeeeYcd)(YL(X(X(LzKX(LzKYKYKYLzKX(LyyyyyxJykxFggfDwgefDeeeweeeeceeeeeeeeeeeeeeeeeceeeeeeeMececd}MMML(YKXzKKKFylFxFkxFkxFkxFlFkykxJxFkxFgkgeeeeeeYccYL(LyyzJyyyxKJyylKFyylKKJyyyylKJyxJxFwxFggfDkeweegeeYeeeYececeYeMd}YeMd}d}d}d}d}d}ceYd}MYYYML(X(LyyylJxFkkkkgewfDfDgekfDkgewkfDeeeeeed}MML(LyyyyylFxFkxFkwxFgkwxFkxEFkxFkxFkxFgkkkkgfDgefDeeeed}eYeMcd))))))(ccYYMMML))))))))))))(YYLzLy(KKKFxFkkkeeeeeeeceeYeeMeeeYeeeeced}YYYMKX(KKKFxFxEFggggfDwgfDkfDkgewkgfDwkgfDwkfDkewekeeeeeeeMeMcd))(cYL(L(LzKXzKXzKX(LzLzLzLzKX(LyzKKFylFkwweeeeeYd))))(cYML)(cYYYYYYYYYYL(YLy(KKJylFkwxDwkgekegeeeweeeeweeegeeeweekeekeeegeeeeMeeYeMYcccYL(Ly(KKKKFyxKJyxKFyylKKKKFyyylJylFkkkeeeeeMccYL(LzKLyyzKKKLyy(KXzKXzKLyzKKJyxJykwxEDwgekeeegeYeeeeceeeMeeceeeeMeeeeeYeeeceeYeMccd)(YLzKLyxKFxFkxEFgggggkkkxEFkxEFkkwwkeeeed}YYL(XzKKJyxKFxJxJykylFxKFxKFylJyxJxJxFgkkgfDgeefDeYeed}d}Yd}MYcd}MYd}MceMceMceYceMYcccYYLzKXyyylFkwwkfDegeeeegeefDeweweeeeeeYd}L(X(KKKJykxFkwxEEEEEEEEEEFgkkwxEFkkwwwwwkgekefDeeeced}cd}ML)(cYL(YL(YL(cYML(cYYYL)(YL(X(LyyyxJxEEDeeed}d}Yd}MceMd}d}eMeYeMcccYL(KLlKFxFkkwkkfDkfDfDfDewfDfDgewgewgewgegefDeeeeed}d}YccYMKYKX(KKXyyyzKKKXy(KX(KXzKLyyyyxJxFgeeeeeMccYYL(L(X(X(YL(YML(cYL(YLzKKKKJykxEEEDkeweeweeeeeeeeeeeeeeegeeeefDeeeeeeceeMd}MML(YKXyyyylFxJxFlFlFlFylJyxKFykykxEEDeeeMcccYKXyy(FyyyylKKKKKKKLyyy(KKKFyxFxFgggeweweeeeeeYeeMeMeMeMeMeceeceeeMeeYeceYd}MML(X(KXlKFkxEEDwkfDwgfDwwwwwxEEDweeeeeYYYLzKKKJylFkykwxFkxFkykxJylFlFxFlFgkkkkgegeeeeeeMeMcd}MMMMMMMMMMYYcceMYcd}MYYYYYL(Ly(JyxFkkeeeeeeeeeeeeeeweeeeeYed}ML(XyyyxJxFggggfEDwgfDwkkggggggggggggfDkeweeeeeeceMYccYMKYLzLzKX(X(X(YL(cYL(YL(LzKLylJxFgeeed}cd)))))(cd)}MceMceMYYMLzKKKJykxEEDwgekeeweegeefDegefDfDgegegeekeeeeYeceMMML(LzKKKKKJyyylKKKKKLyy(KKKKKJylEEDeed}YYL(X(KXzKKXzKX(X(YL(L(XzKKKKFxFgggewekeeeeeeceeeeMeeeeeeeeeeeeeeeed}eMcd)(YLyzJyxJxFkwxEFgkxFlFlFxFxFkxEDeeeYccYKXyyylJyxJylFylKKFyyyyyyylJykxEEDwgeeeeeeeMeMceMcd}Yd}YeMeYeceeMeMd}MYYYLzKKKKFkkkgegeefDewfDkggfDweeeeeYYL(LylJykxFgkkkwwxEFgkxFkykxFkxFkkkgekeeeeeeMceMMML(cYL(cYMML)}MMMYYYcYYL(YKKKKFkkeeeeeMd}YeMeceeeeeeeceYYL(KKKFxFgggfDkewfDgekfDkgfEDwwwkgfDgeegeceeYd)))(L(Ly(KKXyzKLzLzLzL(YKX(KXylJwweeeeMMML(YLzL(cYYYYccd))(YLyyyxJxEEDkekeeeekeeeeeeefDefDewefDeeeeeed}YcYYKX(KJyxJylFlFylKKKKKKKKFyxFkkeed}YMKX(KKKKKKKKKKXzKX(X(KXyyxJygkkfDeweeeYeeYeced}eceeeeeeeceeeeceYd))(X(KKFxFggfDwkgggkkxFlFkwxEDeeYd)(LyyxJykykxFkxJxKFylKJyylJykwwwwgeeeeeceYd}MMMMMYYcd}Yd}ceceYd}MYML(KXxJxEDeeeeeeeweekewgeeeeecccLyyxJxFgggfDwwkggggkkxFkwxFgkkgekeeeed}YccYYLzLzLzL(YL(ccYYYYYML(LzKFygked}eMYccccceMeMeeeMeMYYKXyxJxEDwkekefDeewegekfDkgfDwgewefDeMecd)(cLzKKKKFyyyyy(KX(L(LzKKXlJxDeeeMML(Ly(KX(LzL)(ccccYLzKKJykkkfDegeed}eeeeeYfDeeefDeeweeeeMeMYYL(KWKFxFkkxEFxFxKKFyyylFkweeecYL(KKFylJylKFyy(KLy(KLyxKFkkkfDeeeececeMceMceceeYeeeed}eceYcYX(KKJxEDwekefDggggkwxFgeeeeMLzKJylFgkkwxEFklFlFxKFylFkxEDwekeced}MMML(cYML))}MceMceMYccYL(KJygeeed}ceeeeeefDeeeecd(LyxJxEDwkfDgekfDwkkkwxFgkkgfDfDeYecccYL(KXyzKLzKYL(cYYYL(YKKKJweeeYYYL(YL(cceMeYeYd)(LylFkkkeweeeeeeweeewewgewgekeeeeecd)(X(KJylFxJyxKLyzKXzKKKKFeeed)(Lyyyyyyy(LzML(cYLy(FxFkgefDeYeeYeceeYeeeekeeeeeeed}YYLyyykwwwkggggxFylKFxJweeecYKKJylFkxFlFxKKKLyyyyylFgfDeeeeMcd)))}MMceYeeYeed}d}MMKXyxEDweeeeeegfEFggeeeeYLyykxEEEDwkgggkxFxJylFkwwwfDeYeYYYL(L(L(YL))}MYd}MYMLzKJweeecd(cd}eeeeeeeeML(KFkwwgefDeewekfDwwwxEEDwgeeeYd)(XyyyyyyyyzL(YL)(YKXyxDeeccX(KXzKYL}Mcecd(YKKFggegeeeMeeeeeeekewfDgeeeed}L(XyxFkwxFkylKLy(KKKJweecYKKKJylFyyyzL(YL(XyxJkgeeeeYeMYd}YeeMegeeeeed}YYLyykwgeefDkkxJyxJxDeecXyylEFgggkxFxKKKKXlJxFeweeMcd(cYL(ccd}ceed}eMYYLyxDeed}YeegewkwweeYYKJygfDkewewkgkxFxJxFkgeeeeYYL(KKXyzL(YYcd}MYL(KJeeeL(YKYMMeeeeeeL(KFkkekeeeeeeewggggggfDeed}L(KJykxJyyzL(YL(X(Jwed)zKJyyyy(YYd}YcXyxFfDeeYeYeYeeeekeweweeeYYXyxFfDkgglKKKLyyxDeYXyykxFglFyy(L)zKWJxDeeeccccccceeMeweeeYeL(KFeeeeeewxFxJyeed(KFggfDkgggxKKKKKFkkeed)(YKXzL(ceMed}eMMKKDecccYMeewkkeed(KFkeweeegekkkylFkwkeeYYLyxJyyy(YYcd}L(XkeYYKKKLzMeeeeYYKJkeeeeeMeeewgggkgeeeYXyyggfFlKL(YL(XkedzJykxJyy)}Md)yykgeYeMMMYeeeekeweed)yygeeeexKKKXywecXxFgfDwxKKYL(LxFeed)(X(YMMeeeeeeYcXeeeL}eexJyxDeLywweweewkxKKXxJkeeL(KKJzKceYeeYcXweYLyzMeekweeKJweeeeeeekxJykweecXxFfFlX)}YccXwYYJykyy}eeecXwwecd}McewkkwweecXkfDegy(YYLyeYJxEDwym(ed)yged)(L(ceewgeeeYDed}eglX(KDdywkeewgyzYLywj}LyyyzMeegeccJccKL}fJyyecJked}eggy(LkwccJwwyzeYeeYJcXxJy}fFeeWDeeMMeexKJxDcWDeglMMeMLeKJkggzkeeLkd)(L(ewykkeJecefKcd(DbwkeexMeeJwYKKF}eggeeDdyzey(cDcDeeYkm}cVucEDy}ekedd{xF}lLwdkcccelYXwdwee(fDeDbkfEfKJYDcKL}mzJeDL}heeYCweefkweDXkxezJwCyxe}eXXecehweDJnYcXyxDd)(KFgeeeeL(KDed(KEDwd}YKJed(JwweccKDd(Jwed(VeKJeeLeLgcVXe";
    int lastpoints[7][2] = { {500, 500}, {501, 501}, {502, 502}, {503, 501}, {504, 501}, {505, 500}, {570, 509} };

    if (FOUT < 0) {
        for (int i = 0; i < 1000; i++) {
            fgets(spiral[i], 1001, f8);
            fgetc(f8);
        }
        
        while (1) {
            r = 0;
            // 직진
            // 29772번째에는 90도 회전이 포함되어 있지만 이전 단계를 직진으로 처리해 무시한다.
            if (c == 29771 || spiral[x + dirxy[d][0]][y + dirxy[d][1]] == '#') {
                r = 2;
            }
            // 좌회전
            else if (spiral[x + dirxy[(d + 7) % 8][0]][y + dirxy[(d + 7) % 8][1]] == '#') {
                r = 1;
                d = (d + 7) % 8;
            }
            // 우회전
            else if (spiral[x + dirxy[(d + 1) % 8][0]][y + dirxy[(d + 1) % 8][1]] == '#') {
                r = 3;
                d = (d + 1) % 8;
            }

            if (r) {
                x += dirxy[d][0];
                y += dirxy[d][1];
                c++;
                if (c % 4 == 0) {
                    // base81로 출력한다.
                    printf("%c", base81[bs]);
                    bs = r - 1;
                }
                else {
                    bs *= 3;
                    bs += r - 1;
                }
            }
            else {
                // 끝난 위치를 출력한다.
                printf("%d %d\n", x, y);
                break;
            }
        }

        fprintf(stdout, "%d", c);
        return;
    }
    
    x = 716;
    d = 5;
    for (int i = 0; i < 7625; i++) {
        // base81 디코딩
        rbs[0] = rbase81[track[i]] / 27;
        rbs[1] = rbase81[track[i]] / 9 % 3;
        rbs[2] = rbase81[track[i]] / 3 % 3;
        rbs[3] = rbase81[track[i]] % 3;
        for (int j = 0; j < 4; j++) {
            //if(x >= 0 && x < 1000 && y >= 0 && y < 1000) 오류 회피용
            if (c == 29771 || rbs[j] == 1) {
                // 생략
            }
            else if (rbs[j] == 0) {
                d = (d + 7) % 8;
            }
            else {
                d = (d + 1) % 8;
            }
            
            x += dirxy[d][0];
            y += dirxy[d][1];
            spiral[x][y] = '#';
            c++;
        }
    }

    // 남은 지점들은 직접 처리한다.
    for (int i = 0; i < 7; i++) {
        spiral[lastpoints[i][0]][lastpoints[i][1]] = '#';
    }
    spiral[571][509] = '\0';

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            fprintf(FOUT ? f8 : stdout, "%c", spiral[i][j] ? '#' : '.');
        }
        fprintf(FOUT ? f8 : stdout, "\n");
    }

    if (FOUT) {
        fclose(f8);
    }
}

/*
불규칙한 선들을 출력해야 한다.
선들의 시작점과 각각의 길이, 방향을 알아낸 다음 비트마스킹을 통해 선들의 구조를 하드코딩하여 저장한다.
이후 각 선들을 정보에 맞춰 출력하면 된다.
*/
void ot9(void) {
    char d9[256];
    FILE* f9;
    if (FOUT) {
        strcpy(d9, DIR);
        if (FOUT < 0) {
            strcat(d9, "gen9.out");
            f9 = fopen(d9, "r");
        }
        else {
            strcat(d9, "ngen9.out");
            f9 = fopen(d9, "w");
        }
    }

    int dirxy[4][2] = { {0, 1}, {1, 1}, {1, 0}, {1, -1} }; // 각 방향별 xy좌표 변화, 위쪽으로 올라가는 경우는 신경쓸 필요 없다.
    int cnt = 0, dir = 0, len = 0, x, y; // 카운트, 방향, 길이, 시작하는 x좌표와 y좌표
    unsigned int rin; // 선들을 담은 정보

    if (FOUT < 0) {
        for (int i = 0; i < 1003; i++) {
            fgets(board9[i], 1004, f9);
            fgetc(f9);
        }

        for (int i = 0; i < 1003; i++) {
            for (int j = 0; j < 1003; j++) {
                // 아직 탐색하지 않은 선의 지점
                if (board9[i][j] == '#') {
                    for (int d = 0; d < 4; d++) {
                        if (board9[i + dirxy[d][0]][j + dirxy[d][1]] != '.') {
                            dir = d;
                            break;
                        }
                    }
                    len = 0;
                    x = i + dirxy[dir][0] * len;
                    y = j + dirxy[dir][1] * len;
                    // 보드를 벗어나지 않았고 계속 탐색 가능한 경우
                    while (x >= 0 && x < 1003 && y >= 0 && y < 1003 && board9[x][y] != '.') {
                        // 탐색했음을 표시
                        board9[x][y] = '@';
                        len++;
                        x = i + dirxy[dir][0] * len;
                        y = j + dirxy[dir][1] * len;
                    }
                    // printf("a line starts fron %d %d directing %d, length : %d\n", i, j, dir, len);
                    rin = i << 22;
                    rin += j << 12;
                    rin += len << 2;
                    rin += dir;
                    cnt++;
                    // 16개마다 개행을 해준다.
                    if (cnt % 16) {
                        printf("%d, ", rin);
                    }
                    else {
                        printf("%d,\n", rin);
                    }
                }

            }
        }
    }

    // 선의 정보를 하드코딩한다. Base64를 활용하면 훨씬 용량을 줄일 수 있...겠지만 귀찮음
    int lines[] = { 7520265, 10618604, 15901191, 56524992, 65523118, 88531167, 94350322, 101264694, 114835924, 119386291, 160596802, 167020946, 176473386, 177832550, 193995014, 200368980,
        201326672, 213289031, 228122874, 233567132, 248419243, 260440766, 267739732, 268436644, 271127723, 274385854, 277832798, 287821861, 292783294, 293809409, 304698379, 326470478,
        335834496, 348637162, 379109550, 384191690, 388510725, 411387341, 417312788, 418640647, 435028466, 445423794, 447014517, 456372929, 459923830, 472525386, 511190670, 522872084,
        524291652, 538730524, 543050514, 547213955, 552350077, 569016844, 573432862, 594969044, 600404579, 601269016, 628295642, 631685933, 649675101, 660264952, 663512754, 685016098,
        688713851, 702952668, 729620581, 738009188, 738198764, 745243834, 754699230, 755477598, 764785724, 790061868, 802639891, 815297383, 817989786, 837092551, 844982097, 847250745,
        862974500, 870534130, 873383838, 891961465, 905441579, 917554858, 948138211, 953344944, 961922202, 966969085, 995739255, 998589072, 1015997161, 1027604665, 1062401219, 1076838409,
        1080902748, 1082131320, 1085228294, 1089819627, 1091402197, 1094468815, 1096173928, 1110409446, 1127653536, 1167430068, 1185128457, 1188850126, 1189254504, 1193519106, 1195286532, 1199477915,
        1207961185, 1213798013, 1224022311, 1241423876, 1245614089, 1246458307, 1246495470, 1249804297, 1252648244, 1254097628, 1258184713, 1258193543, 1262374921, 1263870545, 1266565129, 1267804394,
        1270755337, 1274945545, 1279135753, 1280461025, 1283325961, 1284735485, 1285833305, 1286779363, 1287516169, 1288070950, 1291706377, 1295896585, 1300086793, 1304277001, 1308467209, 1309959686,
        1312657417, 1316847625, 1317818380, 1321037833, 1325228041, 1329418249, 1333608457, 1337798665, 1341988873, 1345204771, 1346179081, 1347733686, 1350369289, 1354559501, 1358749705, 1361885343,
        1362588112, 1363150160, 1364994490, 1365922699, 1367130121, 1371320329, 1375510537, 1379700745, 1383890953, 1388081161, 1392271369, 1396461577, 1400651785, 1404841993, 1409032201, 1413222409,
        1417412617, 1421602825, 1425793033, 1429983241, 1438363660, 1442553869, 1446744073, 1450354894, 1450934281, 1455124489, 1459314697, 1463504905, 1467695113, 1471885321, 1476075529, 1479831560,
        1480265737, 1484455945, 1488228861, 1488646153, 1492836361, 1497026569, 1501216777, 1505406985, 1508155486, 1509597193, 1513787401, 1517977609, 1522167817, 1522200816, 1522535372, 1526358025,
        1530548233, 1534738441, 1538928649, 1543118857, 1547309065, 1549750924, 1551134728, 1551499273, 1555326759, 1555689481, 1559879689, 1564069897, 1568260105, 1572450313, 1576640521, 1578344922,
        1580830729, 1585020937, 1589211145, 1593401353, 1597591561, 1601192671, 1601781769, 1605971977, 1610162185, 1613504920, 1614352393, 1614914246, 1618542601, 1622732809, 1626923017, 1631113225,
        1635303433, 1639493641, 1639634703, 1643683849, 1647874057, 1652064265, 1656254473, 1660444681, 1663911005, 1664634889, 1667482805, 1668825097, 1673015305, 1680777970, 1681395724, 1685585933,
        1689776137, 1693966345, 1698156553, 1705476104, 1706536969, 1710727180, 1713865598, 1714917385, 1719107593, 1723297801, 1727488009, 1731678217, 1734587735, 1735868425, 1740058633, 1741042067,
        1744248841, 1748439049, 1749913895, 1752629257, 1756819465, 1761009673, 1765199881, 1765564564, 1765802804, 1767870472, 1769390089, 1772061999, 1773580297, 1776666330, 1777770505, 1781960713,
        1786150921, 1789408527, 1790341129, 1794245422, 1794531337, 1798721545, 1800210201, 1802911753, 1807101961, 1811292169, 1815482377, 1819672585, 1823862793, 1824194754, 1828053001, 1829881012,
        1832243209, 1836433417, 1838679079, 1840623625, 1844813833, 1849004041, 1857384460, 1859395903, 1861574669, 1865764873, 1869955081, 1874145289, 1878335497, 1882525705, 1886715913, 1890906121,
        1895096329, 1899286537, 1901257437, 1903476745, 1907666953, 1911857161, 1914438429, 1916047369, 1924427788, 1928618311, 1957356788, 1958740348, 1965699292, 1975247078, 1987092804, 1989169660,
        1991651873, 2016211243, 2038638292, 2059891147, 2107506697, 2111696905, 2115887113, 2120077321, 2124267529, 2128457737, 2132647945, 2136838153, 2141028361, 2145218569, -2145558519, -2143408120,
        -2141368311, -2141331408, -2139217629, -2137178100, -2132987895, -2128797687, -2124647939, -2124607479, -2122407932, -2120417271, -2120112310, -2118217720, -2117442110, -2116227063, -2114027329, -2112036855,
        -2107846647, -2101345871, -2099466231, -2095276023, -2094848883, -2091085811, -2089557324, -2088762536, -2086895607, -2085166604, -2084567240, -2074324980, -2074071032, -2070134771, -2069872632, -2065944567,
        -2065674232, -2061475832, -2057564148, -2057277432, -2053373939, -2053079032, -2049183735, -2048880632, -2044993527, -2044682232, -2040803319, -2040483832, -2036613111, -2036285432, -2032422903, -2032087032,
        -2028232695, -2027888632, -2024042487, -2023690232, -2019852279, -2019491832, -2019237529, -2015662071, -2015293432, -2011725815, -2011471863, -2011095032, -2007531512, -2007281655, -2006896632, -2003091447,
        -2002698232, -1999142006, -1998901239, -1998499832, -1994711031, -1994301432, -1990520823, -1990103032, -1986330615, -1985904628, -1982140407, -1981706232, -1977950199, -1977768394, -1973759991, -1973309432,
        -1969111032, -1967062355, -1965379572, -1964912632, -1961189363, -1960714232, -1956999159, -1956515832, -1952808951, -1952317432, -1948119032, -1946247164, -1943920632, -1942056353, -1941678988, -1939722232,
        -1935523832, -1931325432, -1928461767, -1927560351, -1927127032, -1922928632, -1918730232, -1914531832, -1910333432, -1906135032, -1904798553, -1901936632, -1897738232, -1893539828, -1885143032, -1883488122,
        -1880944632, -1877907676, -1872748428, -1872321074, -1864151032, -1862950331, -1859952632, -1855754232, -1851555828, -1847357432, -1843010850, -1838960632, -1834762232, -1830563832, -1829388150, -1826365432,
        -1822167032, -1817968632, -1813770232, -1809571832, -1809451472, -1807744880, -1805373432, -1801175032, -1796976632, -1792778232, -1788579832, -1784381432, -1780183032, -1775984632, -1771786232, -1767587832,
        -1763389432, -1759191032, -1754992632, -1752217040, -1746595832, -1742397432, -1738199032, -1734000628, -1725603832, -1721405432, -1719664279, -1717207032, -1713008632, -1708810228, -1704611832, -1696865248,
        -1691089906, -1688624228, -1684103071, -1683619832, -1679421432, -1675223028, -1674231203, -1671024632, -1663712639, -1662627832, -1658429432, -1654231032, -1650032628, -1645834232, -1637437432, -1633239032,
        -1629040632, -1624842232, -1620643832, -1616445432, -1612247032, -1608048632, -1603850232, -1599651832, -1595453432, -1591255032, -1587056632, -1582858232, -1578659832, -1574461428, -1570263032, -1561866232,
        -1560432576, -1560279016, -1557667832, -1556176892, -1553469432, -1551986253, -1550801850, -1549914104, -1549271032, -1545072632, -1541517243, -1540874232, -1537252575, -1536675832, -1532477432, -1528279032,
        -1524080632, -1519882232, -1515683832, -1511485432, -1507287032, -1503088632, -1498890232, -1494691832, -1490493432, -1486295032, -1482096632, -1477898232, -1447034179, -1442840456, -1438645867, -1424064276,
        -1395273407, -1374121969, -1372601582, -1365696458, -1365200372, -1314512738, -1311272581, -1286740536, -1281014933, -1241513259, -1205472355, -1181588955, -1165859568, -1147010439, -1142783454, -1134835524,
        -1132461744, -1127530226, -1055509993, -1052994689, -1027604015, -1011007395, -1007578915, -960634706, -901774659, -888880931, -802131380, -797433294, -796082148, -787189475, -703166648, -698306496,
        -695045460, -559869569, -549031587, -544915448, -540717048, -536518648, -532320248, -528121848, -523923448, -519725048, -515526648, -513580979, -511328248, -507129848, -502931448, -498733048,
        -494534648, -490336248, -486137848, -481939448, -477741048, -473542648, -469344248, -465145848, -460947448, -456749048, -452550648, -448352248, -445971720, -444153848, -439955448, -437641121,
        -435757048, -431558648, -428187372, -427817808, -423161848, -418963448, -414765048, -410566648, -409145105, -406368248, -402169848, -397971448, -393773044, -389574648, -381177848, -376979448,
        -372781048, -371772324, -368582648, -364384248, -360185848, -358149907, -355987448, -351789048, -347590648, -343392248, -343219991, -339193848, -334995448, -330797048, -304533467, -278871986,
        -265972780, -235376593, -133407828, -123439472, -121634632 };

    for (int i = 0; i < 677; i++) {
        rin = lines[i];
        x = rin >> 22;
        y = (rin >> 12) % 1024;
        len = (rin >> 2) % 1024;
        dir = rin % 4;
        // 각각의 선들을 보드에 출력한다.
        for (int j = 0; j < len; j++) {
            board9[x + dirxy[dir][0] * j][y + dirxy[dir][1] * j] = '#';
        }
    }

    for (int i = 0; i < 1003; i++) {
        for (int j = 0; j < 1003; j++) {
            fprintf(FOUT ? f9 : stdout, "%c", board9[i][j] ? '#' : '.');
        }
        fprintf(FOUT ? f9 : stdout, "\n");
    }

    if (FOUT) {
        fclose(f9);
    }
}

typedef struct mat {
    char m[80][80];
} mat;

mat mati;

unsigned long long int mul2[64] = { 1, };
mat sqrx[80];
int sqrxchk[80];

mat matmul(int n, mat x, mat y) {
    mat t = { 0, };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) t.m[i][j] = (t.m[i][j] + x.m[i][k] * y.m[k][j]) % 2;
        }
    }
    return t;
}

mat matsqr(int n, mat x, int c) {
    if (sqrxchk[c]) {
        return sqrx[c];
    }
    if (c == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) x.m[i][j] %= 2;
        }
        sqrx[0] = x;
        sqrxchk[0] = 1;
        return x;
    }
    else {
        mat y = matsqr(n, x, c - 1);
        sqrxchk[c] = 1;
        return sqrx[c] = matmul(n, y, y);
    }
}

mat matbigmul(int n, mat x, long long int c) {
    for (int i = 0; i < 80; i++) {
        sqrxchk[i] = 0;
    }
    for (int i = 1; i < 64; i++) {
        if((c >> i) % 2) x = matmul(n, matsqr(n, x, i), x);
    }
    return x;
}

/*
행렬을 이용한 두 가지 형태의 수식이 존재한다.
첫 번째는 피보나치 수열과 유사하게 앞쪽 배열의 뒤에 뒤쪽 배열을 붙여 만드는 점화식 형태의 배열이고,
두 번째는 위에서 만든 배열을 통해 만든 행렬을 9099099909999099999 제곱하여 만드는 행렬이다.
제곱수가 크기 때문에 분할 정복을 이용해 행렬의 제곱을 구한다. 또한 출력 형식이 복잡하기 때문에 출력 형식을 맞추는 것에 신경을 써야 한다.
*/
void ot10(void) {
    char d10[256];
    FILE* f10;
    if (FOUT) {
        strcpy(d10, DIR);
        strcat(d10, "ngen10.out");
        f10 = fopen(d10, "w");
    }
    // 첫 식은 미리 작성해놓는다.
    fprintf(FOUT ? f10 : stdout, "a_i = a_{i-1} . a_{i-2}\n\na_1 = 0\n\n");

    int alen = 2, a_1len = 1, a_nlen = 0;
    ot10_a[1] = 1;

    for (int i = 2; i <= 18; i++) {
        // 15까지만 출력한다.
        if (i <= 15) {
            fprintf(FOUT ? f10 : stdout, "a_%d = ", i);
        
            for (int j = 0; j < alen; j++) {
                fprintf(FOUT ? f10 : stdout, "%d", ot10_a[j]);
                if (j < alen - 1) fprintf(FOUT ? f10 : stdout, " ");
                if ((j + 1) % 40 == 0) {
                    fprintf(FOUT ? f10 : stdout, "\n      ");
                    if (i >= 10) fprintf(FOUT ? f10 : stdout, " ");
                }
            }
            fprintf(FOUT ? f10 : stdout, "\n\n");
        }

        // 이전 두 배열을 더한다.
        a_nlen = 0;
        for (int j = 0; j < alen; j++) {
            ot10_a_n[a_nlen++] = ot10_a[j];
        }
        for (int j = 0; j < a_1len; j++) {
            ot10_a_n[a_nlen++] = ot10_a_1[j];
        }

        for (int j = 0; j < alen; j++) {
            ot10_a_1[j] = ot10_a[j];
        }
        for (int j = 0; j < a_nlen; j++) {
            ot10_a[j] = ot10_a_n[j];
        }
        a_1len = alen;
        alen = a_nlen;

    }
    fprintf(FOUT ? f10 : stdout, "\n(A_i)^n = B_i (mod 2)\n\n");

    mat x, y; // 행렬을 선언해 놓는다.

    for (int i = 1; i <= 70; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                x.m[j][k] = ot10_a[j * i + k];
            }
        }
        
        y = matbigmul(i, x, CONST1); // 행렬에 제곱 연산을 한다.
        

        for (int j = 0; j < i; j++) {
            if (j == i / 2) {
                fprintf(FOUT ? f10 : stdout, "A_%d = ", i);
            }
            else {
                fprintf(FOUT ? f10 : stdout, "      ");
                if(i >= 10) fprintf(FOUT ? f10 : stdout, " ");
            }

            for (int k = 0; k < i; k++) {
                fprintf(FOUT ? f10 : stdout, "%d ", (int)x.m[j][k]);
            }

            if (j == i / 2) {
                fprintf(FOUT ? f10 : stdout, "  B_%d = ", i);
            }
            else {
                fprintf(FOUT ? f10 : stdout, "        ");
                if (i >= 10) fprintf(FOUT ? f10 : stdout, " ");
            }

            for (int k = 0; k < i; k++) {
                fprintf(FOUT ? f10 : stdout, "%d", (int)y.m[j][k]);
                if (k < i - 1) {
                    fprintf(FOUT ? f10 : stdout, " ");
                }
            }
            fprintf(FOUT ? f10 : stdout, "\n");
        }

        fprintf(FOUT ? f10 : stdout, "\n");
    }

    if (FOUT) {
        fclose(f10);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    if (n < 0) {
        comparefile(-n);
        return 0;
    }
    switch (n) {
    case 0 :
        ot0();
        break;
    case 1 :
        ot1();
        break;
    case 2 :
        ot2();
        break;
    case 3 :
        ot3();
        break;
    case 4 :
        ot4();
        break;
    case 5 :
        ot5();
        break;
    case 6 :
        ot6();
        break;
    case 7 :
        ot7();
        break;
    case 8 :
        ot8();
        break;
    case 9 :
        ot9();
        break;
    case 10 :
        ot10();
        break;
    default :
        // Here is another OT
        break;
    }
    return 0;
}

/*
gen0 - 00:40 00:40
gen1 - 00:36 01:16
gen2 - 00:22 01:38
gen3 - 00:42 02:20
gen4 - 00:23 02:43
gen5 - 01:50 04:33
gen6 - 00:53 05:26
gen7 - 01:29 06:55
gen8 - 01:17 08:12
gen9 - 00:41 08:53
gen10 - 01:19 10:12
*/

/*
A certain daily life is a parallel world within thousands of timelines.
Let’s go to space-time woven by the unique masterpiece.
Scribbling on the white paper, the pen’s tip freezes on the scenario.
Aim for originality! because you’ll go along this road anyhow.

Run through and kick off the ground!

The sensation of living for a reason will certainly
Become power that won’t lose to anyone.
This moment is probably when one knows what happiness is;
I carve this passion into a new page.

This world follows an invisible mesh of cobwebs;
After all, we’re going to a future connected by this network without isolation.
Confess before you get buried in the overcrowding of this world.
Draw your identity! because you can’t do without yourself.

Jump over
And soar through the heavens!

The presence of living by looking up and broadening the sky is only
Small, fleeting… but it won’t lose.
Sadness is probably the power to move on to tomorrow.
I carve this emotion into a new page.

…a certain daily life is a parallel world within thousands of timelines…
…let’s go to space-time woven by the unique masterpiece…
Yes, because I can go on!

No matter how many times in my life I lose my bearings, always,
I must grab onto the answer.
Unexpectedly, happiness lies in a simple place.
Advance with your own will.

The sensation of living for a reason will certainly
Become power that won’t lose to anyone.
This moment is probably when one knows what happiness is;
I carve this passion into a new page.


　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
*/