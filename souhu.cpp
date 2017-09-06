#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> p(6,1);
	while(true){
		for(int i=0; i<6; cin>>p[i++]);
		if(p==vector<int>(6,0)) return;

		int res = 0;
		if(p[5]) res+=p[5];
		if(p[4]) {
			res +=p [4];
			p[0] -= 11*p[4];
		}
		if(p[3]){
			res += p[3];
			if(p[1]>=5*p[3])
				p[1] -= 5*p[3];
			else{
				p[0] -= 36*p[3] - 4*p[1];
				p[1] = 0;
			}
		}
		if(p[2]>0){
			if(p[2]%4 == 0) res += p[2]/4;
			else{
				int n = p[2]/4;
				int l = p[2]%4;

				res+=n+1;

				if(l==1){
					if(p[1]){
						p[0] -= (36 - 9 - 4*min(4,p[1]));
						p[1] -= 4;
					}
					else
						p[0] -= (36-9);
				}else if(l==2){
					if(p[1]){
						p[0] -= (36 - 9 - 4*min(3,p[1]));
						p[1] -= 3;
					}
					else
						p[0] -= (36-9*2);

				}else{
					if(p[1]){
						p[0] -= (36 - 9 - 4*min(1,p[1]));
						p[1] -= 1;
					}
					else
						p[0] -= (36-9*3);

				}
			}
		}
		if(p[1]>0){
			if(p[1]%9==0) res += p[1]/9;
			else{
				int n = p[1]/9;
				int l = p[1]%9;
				res += n+1;

				p[0] -= (36 - 4*l);
			}
		}
		if(p[0]>0){
			res += (p[0]/36 + (p[0]%36==0)?0:1);
		}

		cout<<res<<endl;
		
	}
	
}