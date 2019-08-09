/**
 * 正整数 A 的“D
​A
​​ （为 1 位整数）部分”定义为由 A 中所有 D
​A
​​  组成的新整数 P
​A
​​ 。例如：给定 A=3862767，D
​A
​​ =6，则 A 的“6 部分”P
​A
​​  是 66，因为 A 中有 2 个 6。

现给定 A、D
​A
​​ 、B、D
​B
​​ ，请编写程序计算 P
​A
​​ +P
​B
​​ 。

输入格式：
输入在一行中依次给出 A、D
​A
​​ 、B、D
​B
​​ ，中间以空格分隔，其中 0<A,B<10
​10
​​ 。

输出格式：
在一行中输出 P
​A
​​ +P
​B
​​  的值。

输入样例 1：
3862767 6 13530293 3
输出样例 1：
399
输入样例 2：
3862767 1 13530293 8
输出样例 2：
0
 */

#include<iostream>

using namespace std;

int main() {
    char a[10],b[10],da,db;
    cin>>a>>da>>b>>db;
    int count1=0,count2=0;
    for (int i = 0; a[i]!='\0'; ++i) {
        if(a[i]==da){
            count1++;
        }
    }
    for (int i = 0; b[i]!='\0'; ++i) {
        if(b[i]==db){
            count2++;
        }
    }

    int pa=0,pb=0;
    int c1=count1,c2=count2;
    for (int i = c1-1; i > 0; --i) {
        int m=1;
        for (int j = 0; j < i; ++j) {
            m*=10;
        }
        pa+=m;
    }
    pa++;
    for (int i = c2-1; i > 0; --i) {
        int m=1;
        for (int j = 0; j < i; ++j) {
            m*=10;
        }
        pb+=m;
    }
    pb++;

    pa*=da-'0';
    pb*=db-'0';
    if(c1==0){
        pa=0;
    }
    if(c2==0){
        pb=0;
    }
    cout<<pa+pb;
    return 0;
}