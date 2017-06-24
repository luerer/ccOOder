有一个大水缸，里面水的温度为T单位，体积为C升。另有n杯水（假设每个杯子的容量是无限的），每杯水的温度为t[i]单位，体积为c[i]升。
现在要把大水缸的水倒入n杯水中，使得n杯水的温度相同，请问这可能吗？并求出可行的最高温度，保留4位小数。
注意：一杯温度为t1单位、体积为c1升的水与另一杯温度为t2单位、体积为c2升的水混合后，温度变为(t1*c1+t2*c2)/(c1+c2)，体积变为c1+c2。 
输入描述:
第一行一个整数n, 1 ≤ n ≤ 10^5
第二行两个整数T，C,其中0 ≤ T ≤ 10^4, 0 ≤ C ≤ 10^9
接下来n行每行两个整数t[i]，c[i]
0 ≤ t[i], c[i] ≤ 10^4


输出描述:
如果非法，输出“Impossible”（不带引号)否则第一行输出“Possible"（不带引号），第二行输出一个保留4位小数的实数表示答案。

样例解释：往第二杯水中倒0.5升水
往第三杯水中到1升水
三杯水的温度都变成了20

输入例子:
3
10 2
20 1
25 1
30 1

输出例子:
Possible
20.0000


int T,C;
int n;
vector<int> t,c;
void poss(double T)
{
    cout<<"Possible"<<endl;
    cout<<fixed<<setprecision(4)<<T<<endl;
}
int main(){
    cin>>n>>T>>C;
    t.resize(n,0);
    c.resize(n,0);
    bool f1=false, f2=false;
    for(int i=0; i<n; i++){
        cin>>t[i]>>c[i];
        if(t[i]>T) f1|=true;
        if(t[i]<T) f2|=true;
    }
    if(f1&&f2) {cout<<"Impossible"<<endl; return 0;}
    if(~f1&&~f2){poss(T); return 0;}
    if(f1){        //T小于所有
        int minT=INT_MAX;
        for(int i=0; i<n;  ++i)  minT=min(minT,t[i]);
        if(minT==T){cout<<"Impossible"<<endl; return 0;}
        int cc = 0;
        for(int i=0; i<n; ++i) cc+=t[i]*c[i]-minT*c[i];
        if(cc>(minT-T)*C) {cout<<"Impossible"<<endl; return 0;}
        else {poss(minT); return 0;}

    }
    else{
        int maxT = INT_MIN;
        for(int i=0; i<n;  ++i)  maxT=max(maxT,t[i]);
        if(maxT==T){cout<<"Impossible"<<endl; return 0;}
        double tar = 0.0;
        int to_c=0;
        for(int i=0; i<n; i++) 
        {
            tar+=t[i]*c[i];
            to_c+=c[i];
        }
        poss((T*C+tar)/(to_c+C));
    }
    return 0;
}