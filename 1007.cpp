/**
 * 让我们定义d
​n
​​ 为：d
​n
​​ =p
​n+1
​​ −p
​n
​​ ，其中p
​i
​​ 是第i个素数。显然有d
​1
​​ =1，且对于n>1有d
​n
​​ 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N(<10
​5
​​ )，请计算不超过N的满足猜想的素数对的个数。

输入格式:
输入在一行给出正整数N。

输出格式:
在一行中输出不超过N的满足猜想的素数对的个数。

输入样例:
20
输出样例:
4
 */

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a[100000];
    int n,i,t,j,k;
    cin>>n;
    k=0;
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
                break;
        }
        if(j>sqrt(i))
        {
            a[k++]=i;
        }
    }
    t=0;
    for(i=1;i<=n;i++)
    {
        if(a[i+1]-a[i]==2){
            t++;
        }
    }
    cout<<t;
    return 0;
}
