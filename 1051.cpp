/*
 * 复数可以写成 (A+Bi) 的常规形式，其中 A 是实部，B 是虚部，i 是虚数单位，满足 i
​2
​​ =−1；也可以写成极坐标下的指数形式 (R×e
​(Pi)
​​ )，其中 R 是复数模，P 是辐角，i 是虚数单位，其等价于三角形式 (R(cos(P)+isin(P))。

现给定两个复数的 R 和 P，要求输出两数乘积的常规形式。

输入格式：
输入在一行中依次给出两个复数的 R
​1
​​ , P
​1
​​ , R
​2
​​ , P
​2
​​ ，数字间以空格分隔。

输出格式：
在一行中按照 A+Bi 的格式输出两数乘积的常规形式，实部和虚部均保留 2 位小数。注意：如果 B 是负数，则应该写成 A-|B|i 的形式。

输入样例：
2.3 3.5 5.2 0.4
输出样例：
-8.68-8.23i
 */

#include<iostream>
#include <cmath>

using namespace std;

int main() {
    double r1, p1, r2, p2;
    cin >> r1 >> p1 >> r2 >> p2;
    double a1, b1, a2, b2;
    a1 = cos(p1);
    b1 = sin(p1);
    a2 = cos(p2);
    b2 = sin(p2);
    double a, b;
    a = (a1 * a2 - b1 * b2) * r1 * r2;
    b = (a1 * b2 + b1 * a2) * r1 * r2;

    //以下两个if很重要！！！由于实部、虚部都保留两位小数，
    // 所以当A、B的值介于0与-0.01之间时就必须要把它们设置为零，否则会有用例无法通过。
    if (abs(a) < 0.01) {
        a = 0;
    }
    if (abs(b) < 0.01) {
        b = 0;
    }

    if (b< 0) {
        printf("%.2lf-%.2lfi", a,abs(b));
    } else{
        printf("%.2lf+%.2lfi", a,b);
    }
}