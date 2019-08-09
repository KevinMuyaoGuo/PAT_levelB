/**
 * 令 P
​i
​​  表示第 i 个素数。现任给两个正整数 M≤N≤10
​4
​​ ，请输出 P
​M
​​  到 P
​N
​​  的所有素数。

输入格式：
输入在一行中给出 M 和 N，其间以空格分隔。

输出格式：
输出从 P
​M
​​  到 P
​N
​​  的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
 */

#include<iostream>
#include <cmath>

using namespace std;

int IsPrime(int n){
    for (int i = 2; i <= sqrt(n); ++i) {
        if(n%i==0){
            return 0;
        }
    }
    return n;
}

int main() {
    int m,n,a[1000],cnt=0;
    cin>>m>>n;
    int p;
    for (int i = 2; cnt < n; ++i) {
        p=IsPrime(i);
        if(p!=0){
            a[cnt++]=p;
        }
    }

    int c=0;
    for (int j = m-1; j < cnt-1; ++j) {
        c++;
        if(c!=10){
            cout << a[j]<<" ";
        } else{
            cout<<a[j]<<endl;
            c=0;
        }
    }
    cout<<a[cnt-1];
    return 0;
}