/*
 * 对于计算机而言，颜色不过是像素点对应的一个 24 位的数值。现给定一幅分辨率为 M×N 的画，要求你找出万绿丛中的一点红，即有独一无二颜色的那个像素点，并且该点的颜色与其周围 8 个相邻像素的颜色差充分大。

输入格式：
输入第一行给出三个正整数，分别是 M 和 N（≤ 1000），即图像的分辨率；以及 TOL，是所求像素点与相邻点的颜色差阈值，色差超过 TOL 的点才被考虑。随后 N 行，每行给出 M 个像素的颜色值，范围在 [0,2
​24
​​ ) 内。所有同行数字间用空格或 TAB 分开。

输出格式：
在一行中按照 (x, y): color 的格式输出所求像素点的位置以及颜色值，其中位置 x 和 y 分别是该像素在图像矩阵中的列、行编号（从 1 开始编号）。如果这样的点不唯一，则输出 Not Unique；如果这样的点不存在，则输出 Not Exist。

输入样例 1：
8 6 200
0 	 0 	  0 	   0	    0 	     0 	      0        0
65280 	 65280    65280    16711479 65280    65280    65280    65280
16711479 65280    65280    65280    16711680 65280    65280    65280
65280 	 65280    65280    65280    65280    65280    165280   165280
65280 	 65280 	  16777015 65280    65280    165280   65480    165280
16777215 16777215 16777215 16777215 16777215 16777215 16777215 16777215
输出样例 1：
(5, 3): 16711680
输入样例 2：
4 5 2
0 0 0 0
0 0 3 0
0 0 0 0
0 5 0 0
0 0 0 0
输出样例 2：
Not Unique
输入样例 3：
3 3 5
1 2 3
3 4 5
5 6 7
输出样例 3：
Not Exist
 */

#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#include<cmath>
using namespace std;

map<int, int> vis;
int s[1001][1001];
int n, m ,tol;
int dir[8][2] = {1,0, -1,0, 0,1, 0,-1, 1,1, 1,-1, -1,1, -1,-1};
//判断是否大于阈值 
bool check(int x, int y)
{
    for(int i=0 ;i<8 ;i++){
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(xx>=0 && xx<n && yy<m && yy>=0 && abs(s[xx][yy]-s[x][y])<=tol ) return false;
    }
    return true;
}

int main(){
    cin>>m>>n>>tol;

    for(int i=0 ;i<n ;i++){
        for(int j=0 ;j<m ;j++){
            cin>>s[i][j];
            vis[s[i][j]] ++;
        }
    }
    //cnt记录只出现一次的数字的个数
    //x y记录坐标 
    int cnt = 0;
    int x, y;
    for(int i=0 ;i<n ;i++){
        for(int j=0 ;j<m ;j++){
            if(vis[s[i][j]]==1 && check(i,j)){
                cnt++;
                x = i;
                y = j;
            }
        }
    }

    if(cnt==1){
        printf("(%d, %d): %d\n",y+1, x+1, s[x][y]);
    }
    else if(cnt>1){
        puts("Not Unique");
    }
    else{
        puts("Not Exist");
    }

    return 0;
}


/* 自己写的，有问题
#include <iostream>
#include <map>
using namespace std;

int main() {
    int m, n, tol;
    cin >> m >> n >> tol;
    long a[n][m];
    map<long,int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            mp[a[i][j]]++;
        }
    }


    long t1, t2, t3, t4, t5, t6, t7, t8, t9;
    int cnt = 0;
    int x, y;
    long value;
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            t1 = a[i - 1][j - 1];
            t2 = a[i - 1][j];
            t3 = a[i - 1][j + 1];
            t4 = a[i][j - 1];
            t5 = a[i][j];
            t6 = a[i][j + 1];
            t7 = a[i + 1][j - 1];
            t8 = a[i + 1][j];
            t9 = a[i + 1][j + 1];
            if(mp[t5]==1){
                if (abs(t1 - t5) > tol && abs(t2 - t5) > tol && abs(t3 - t5) > tol
                    && abs(t4 - t5) > tol && abs(t6 - t5) > tol && abs(t7 - t5) > tol
                    && abs(t8 - t5) > tol && abs(t9 - t5) > tol) {
                    x = j + 1;
                    y = i + 1;
                    cnt++;
                    if (cnt == 2) {
                        break;
                    }
                }
            }
        }
        if (cnt == 2) {
            break;
        }
    }
    if (cnt == 0) {
        cout << "Not Exist";
    } else if (cnt > 1) {
        cout << "Not Unique";
    } else {
        printf("(%d: %d): %ld", x, y, a[y-1][x-1]);
    }

}*/
