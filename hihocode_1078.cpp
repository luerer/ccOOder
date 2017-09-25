#include <bits/stdc++.h>
using namespace std;
struct node
{
    int left,right;
    int val;
};
vector<int> nums;
node data[8000000];
int father[1000001];
int ans;
void bulid(int pos, int l, int r){
    data[pos].left = l;
    data[pos].right = r;
    if(l==r) {
        data[pos].val = nums[l];
        father[l] = pos;
        return;
    }
    int mid = l + (r-l)/2;
    bulid(pos<<1, l,mid);
    bulid(pos<<1|1, mid+1,r);

    data[pos].val = data[pos<<1].val+data[pos<<1|1].val;
}
void update(int pos){
    if(pos==1) return;
    int tmp = pos/2;
    data[tmp].val = data[tmp<<1].val+data[tmp<<1|1].val;
    update(tmp);
}
void query(int pos, int l, int r){
    if(data[pos].left == l && data[pos].right == r){
        ans += data[pos].val;
        return;
    }
    int ll = data[pos].left, rr = data[pos].right;
    int mid = ll+(rr-ll)/2;
    if(l>mid){
        query(pos<<1|1,l,r);
    }else if(r<=mid){
        query(pos<<1,l,r);
    }else{
        query(pos<<1,l,mid);
        query(pos<<1|1,mid+1,r);
    }
}
int main(){
    int n,m,op,a,b;
    scanf("%d",&n);
    nums.clear();
    nums.resize(n+1,0);
    for(int i=1; i<=n; scanf("%d",&nums[i++]));
    bulid(1,1,n);
    scanf("%d",&m);
    while(m--){
        scanf("%d",&op);
        if(op){//update
            int l,r,num;
            scanf("%d%d%d",&l, &r, &num);
            update(l,r,num);

        }else{//query
            ans = 0;
            int a,b;
            scanf("%d%d",&a, &b);
            query(1,a,b);
            printf("%d\n",ans);
        }
    }
    return 0;
}