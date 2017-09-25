#include<bits/stdc++.h>
using namespace std;

const int MAX=999999999;
typedef struct{char c;int v;}para;


void solve(){
    string str;
    cin>>str;
            int L=str.size();
            if(L<=1){
                cout<<str<<' '<<"-1"<<endl;
            }else{
                vector<para>s1(150003);
                vector<para>s2(150003);

                para p1,p2,p3;
                for(int i=0;i<L;i++){
                    p1.c=str[i];
                    if(str[i]!=')'){
                        p1.v=-1;
                        s1.push_back(p1);
                    }else{
                        p1=s1.back();
                        s1.pop_back();
                        p2=s1.back();
                        s1.pop_back();
                        p3=s1.back();
                        s1.pop_back();
                        s1.pop_back();
                        if(p1.c==p3.c){
                            //'|'
                            if(p2.c=='|'){
                                //0 v
                                if(p1.v==-1&&p3.v==-1){
                                    if(p1.c=='1'||p3.c=='1')p1.c=='1';
                                    else p1.c=='0';
                                }else{
                                    //1 v
                                    if(p1.v==-1||p3.v==-1){
                                        if(p1.c=='0')
                                        {p1.c='0';p1.v=max(p1.v,p3.v);}
                                        else{
                                            p1.c='1';p1.v=max(p1.v,p3.v)+1;
                                        }
                                        
                                    }else{//2 v
                                        if(p1.c=='0'){
                                            p1.v=min(p1.v,p3.v);
                                        }else{
                                            p1.v=min(p1.v,p3.v)+1;
                                        }
                                    }
                                }
                            }
                            //'&'
                            else{
                                //0 v
                                if(p1.v==-1&&p3.v==-1){
                                    if(p1.c=='1'||p3.c=='1')p1.c=='1';
                                    else p1.c=='0';
                                }else{
                                    //1 v
                                    if(p1.v==-1||p3.v==-1){
                                        if(p1.c=='0')
                                        {p1.v=max(p1.v,p3.v)+1;}
                                        else{
                                            p1.c='1';p1.v=max(p1.v,p3.v);
                                        }
                                        
                                    }else{//2 v
                                        if(p1.c=='0'){
                                            p1.v=min(p1.v,p3.v)+1;
                                        }else{
                                            p1.v=min(p1.v,p3.v);
                                        }
                                    }
                                }
                            }
                        }else{
                            if(p2.c=='|'){
                                p1.c='1';
                                p1.v=1;
                            }else{
                                p1.c='0';
                                p1.v=1;
                            }
                        }
                        s1.push_back(p1);
                    }
                }
                auto p=s1.back();
                cout<<p.c<<' '<<p.v<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}