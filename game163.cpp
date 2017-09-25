#include <bits/stdc++.h>
using namespace std;
struct mag
{
    int atk;
    int cd;
    bool avalib;
    mag(int _a):atk(_a){cd = 0; avalib=true;};
    void reset(){cd=0; avalib=true;};
};

bool mycomp(const mag& a, const mag& b){
    return a.atk>b.atk;
}

void solve(){
    int hp,atk,cd,magatk;
    cin>>hp>>atk>>cd;
    vector<mag> M;
    for(int i=0; i<3; ++i){
        cin>>magatk;
        M.push_back(mag(magatk));
    }
    sort(M.begin(),M.end(),mycomp);
    vector<pair<int,int>> emy;
    for(int i=0; i<3; i++){
        int a,b;
        cin>>a>>b;
        emy.push_back({a,b});
    }
    int emcnt = 0;
    int time[3];
    for(auto em:emy){
        for(int i=0; i<3; M[i++].reset());
        int t = 0;
        while(em.first>0){
            t++;
            bool ismag = false;
            for(int i=0; i<3; ++i){
                if(M[i].atk>atk) {
                    if (M[i].avalib) {
                        em.first -= M[i].atk;
                        M[i].avalib = false;
                        M[i].cd++;
                        ismag = true;
                        break;
                    } else {
                        M[i].cd++;
                        if (M[i].cd == cd) M[i].reset();
                    }
                }
            }
            if(ismag) continue;
            em.first -= atk;
        }
        time[emcnt] = t;
        emcnt++;
    }
    
    vector<pair<int,int>> atktime;
    for(int i=0; i<3; ++i){
        atktime.push_back({emy[i].second,time[i]});
    }

    int res = INT_MAX;
    for(int i=0; i<3; ++i){
        int tmp = atktime[i].second*(atktime[0].first+atktime[1].first+atktime[2].first);
        for(int j=0; j<3; ++j){
            if(i!=j){
                for(int k=0; k<3; ++k){
                    if(k!=i && k!=j) {
                    	int tt = tmp;
                        tt += atktime[j].second * (atktime[j].first + atktime[k].first);
                        tt += atktime[k].second * atktime[k].first;
                        res = min(res,tt);
                    }
                }
            }
        }

    }
    cout<<(hp>res?hp-res:-1)<<endl;

}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}