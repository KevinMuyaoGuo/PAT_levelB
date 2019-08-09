/**
 * 让我们用字母 B 来表示“百”、字母 S 表示“十”，用 12...n 来表示不为零的个位数字 n（<10），换个格式来输出任一个不超过 3 位的正整数。例如 234 应该被输出为 BBSSS1234，因为它有 2 个“百”、3 个“十”、以及个位的 4。

输入格式：
每个测试输入包含 1 个测试用例，给出正整数 n（<1000）。

输出格式：
每个测试用例的输出占一行，用规定的格式输出 n。

输入样例 1：
234
输出样例 1：
BBSSS1234
输入样例 2：
23
输出样例 2：
SS123
 */

#include <iostream>

using namespace std;

string Bai(int n){
    n/=100;
    char s[n+1];
    for (int i = 0; i < n+1; ++i) {
        s[i]='B';
    }
    s[n]='\0';
    return s;
}

string Shi(int n){
    n/=10;
    n%=10;
    char s[n+1];
    for (int i = 0; i < n+1; ++i) {
        s[i]='S';
    }
    s[n]='\0';
    return s;
}

string Ge(int n){
    n%=10;
    int m=n;
    char s[n+1];
    for (int i = n-1; i >= 0; --i) {
        s[i]=n+'0';
        n--;
    }
    s[m]='\0';
    return s;
}

int main() {
    int n;
    cin>>n;
    cout<<Bai(n)+Shi(n)+Ge(n);
    return 0;
}

/** 指针版
#include <iostream>

using namespace std;

char *Bai(int bai) {
    int n = bai;
    char *s=new char;
    for (int i = 0; i < n + 1; ++i) {
        *(s + i) = 'B';
    }
    *(s + n) = '\0';
    return s;
}

char *Shi(int shi) {
    int n = shi;
    char *s=new char;
    for (int i = 0; i < n + 1; ++i) {
        *(s + i) = 'S';
    }
    *(s + n) = '\0';
    return s;
}

char *Ge(int ge) {
    int n = ge, m = n;
    char *s=new char;
    for (int i = n - 1; i >= 0; --i) {
        *(s + i) = n + '0';
        n--;
    }
    *(s + m) = '\0';
    return s;
}

int main() {
    int n, bai, shi, ge;
    cin >> n;
    bai = n / 100;
    shi = n / 10 % 10;
    ge = n % 10;
    char *b, *s, *g;
    b = Bai(bai);
    s = Shi(shi);
    g = Ge(ge);
    for (int i = 0; i < bai; ++i) {
        cout << *(b + i);
    }
    for (int i = 0; i < shi; ++i) {
        cout << *(s + i);
    }
    for (int i = 0; i < ge; ++i) {
        cout << *(g + i);
    }
    return 0;
}
*/