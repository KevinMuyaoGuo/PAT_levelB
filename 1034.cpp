/*
 * 本题要求编写程序，计算 2 个有理数的和、差、积、商。

输入格式：
输入在一行中按照 a1/b1 a2/b2 的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为 0。

输出格式：
分别在 4 行中按照 有理数1 运算符 有理数2 = 结果 的格式顺序输出 2 个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式 k a/b，其中 k 是整数部分，a/b 是最简分数部分；若为负数，则须加括号；若除法分母为 0，则输出 Inf。题目保证正确的输出中没有超过整型范围的整数。

输入样例 1：
2/3 -4/2
输出样例 1：
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
输入样例 2：
5/3 0/6
输出样例 2：
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
 */

#include <iostream>

using namespace std;

long gcd(long a, long b) {//最大公约数
    long l;
    while (b != 0) {
        l = a % b;
        a = b;
        b = l;
    }
    return a;
}
/* 递归法辗转相除求最大公约数
 * long gcd(long long a, long long b){
    return b == 0 ? a : gcd(b, a % b);
}
 */

/*long lcm(long a, long b) {//最小公倍数
    return a * b / gcd(a, b);
}*/

void printFraction(long a, long b) {//打印化简的分数
    if (a == 0) {
        cout << "0";
        return;
    }
    bool minusFlag = false;
    if (a < 0) {
        minusFlag = true;
        cout << "(-";
        a = -a;
    }
    long d = a / b;
    long n = a % b;
    if (d > 0) {
        cout << d;
    }
    long g = gcd(n, b);
    if (d > 0 && n != 0) {
        cout << " ";
        cout << n/g << "/" << b/g;
    }else if(d == 0 && n != 0){
        cout << n/g << "/" << b/g;
    }
    if (minusFlag) {
        cout << ")";
    }
}

int main() {
    long a1, b1, a2, b2;
    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);

    long deno,nume;

    // +
    deno=b1*b2;//分母
    nume = a1 * b2 + a2 * b1;

    printFraction(a1, b1);
    cout << " + ";
    printFraction(a2, b2);
    cout << " = ";
    printFraction(nume, deno);
    cout<<endl;

    // -
    nume = a1 * b2 - a2 * b1;

    printFraction(a1, b1);
    cout << " - ";
    printFraction(a2, b2);
    cout << " = ";
    printFraction(nume, deno);
    cout<<endl;

    // *
    nume = a1 * a2;
    printFraction(a1, b1);
    cout << " * ";
    printFraction(a2, b2);
    cout << " = ";
    printFraction(nume, deno);
    cout<<endl;

    // /
    printFraction(a1, b1);
    cout << " / ";
    printFraction(a2, b2);
    cout << " = ";

    if (a2 == 0) {
        cout << "Inf";
        return 0;
    } else if (a2 < 0) {
        a2=-a2;
        b2=-b2;
    }
    deno=b1*a2;
    nume=a1*b2;

    printFraction(nume, deno);

}