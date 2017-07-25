牛牛和羊羊在玩一个有趣的猜数游戏。在这个游戏中,牛牛玩家选择一个正整数,羊羊根据已给的提示猜这个数字。第i个提示是"Y"或者"N",表示牛牛选择的数是否是i的倍数。
例如,如果提示是"YYNYY",它表示这个数使1,2,4,5的倍数,但不是3的倍数。
注意到一些提示会出现错误。例如: 提示"NYYY"是错误的,因为所有的整数都是1的倍数,所以起始元素肯定不会是"N"。此外,例如"YNNY"的提示也是错误的,因为结果不可能是4的倍数但不是2的倍数。
现在给出一个整数n,表示已给的提示的长度。请计算出长度为n的合法的提示的个数。
例如 n = 5:
合法的提示有:
YNNNN YNNNY YNYNN YNYNY YYNNN YYNNY
YYNYN YYNYY YYYNN YYYNY YYYYN YYYYY
所以输出12 
输入描述:
输入包括一个整数n(1 ≤ n ≤ 10^6),表示已给提示的长度。


输出描述:
输出一个整数,表示合法的提示个数。因为答案可能会很大,所以输出对于1000000007的模

输入例子1:
5

输出例子1:
12
思路：
每个位置是Y还是N取决于它的因数。
每个数可以分为若干个素数的乘积。
num = sum(p_i ^ cnt_i)
如 6 = 2^1*3^1
6只和2，3有关
2Y3Y6Y
2Y3N6N
2N3N6N
2N3Y6N
4种情况
再如 64 = 2^6
2Y4Y8Y16Y32Y 64Y
2Y4Y8Y16Y32N 64N
2Y4Y8Y16N32N 64N
一共7种
所以 对于数字num 一共的情况是(cnt_i+1)的乘积

这里选择素数的方法也很巧妙，所有i的倍数都置1，没有置1的都是素数。

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int vis[maxn];

int main() {
    int n;
    scanf("%d", &n);
    long long ans = 1;
    for(int i = 2; i <= n; i++) {
        if(vis[i]) continue;
        for(int j = i + i; j <= n; j += i) vis[j] = 1;
        int tmp = n, cnt = 0;
        while(tmp >= i) tmp /= i, cnt++;
        ans = ans * (cnt + 1) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
