/************
Major Element
大意：
找到数组中主要元素，即出现次数大于[n/2]的数。
思路：
不考虑时间复杂度的方法：1.排序 2.返回nums[n/2]

看solutions发现Moore's voting algorithm，一种投票算法，可以找出出现k次以上的数，时间复杂度O(n),空间复杂度O(1)
具体思路：遍历数组，每次找出一对不同的元素从数组中去除，直到数组为空或剩下一种元素
************/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
        */
        
        int cnt = 1;
        int compare = nums[0];
        for(int i=1; i<nums.size(); ++i)
        {
            compare==nums[i]?cnt++:cnt--;
            if(cnt==0)
            {
                compare = nums[i];
                cnt = 1;
            }
        }
        return compare;
    }
};

//附：如果要找到数组中出现次数大于n/3的数
//出现次数大于n/3的数最多两个
     /** 
      * Given an integer array of size n,  
      * find all elements that appear more than n/3 times. The algorithm should run in linear time and in O(1) space. 
      * @param nums 
      * @return 
      */  
     public List<Integer> majorityElement2(int[] nums) {  
           /* 
           A Linear Time Majority Vote Algorithm 
           每次都找出一对不同的元素，从数组中删掉，直到数组为空或只有一种元素。 
           不难证明，如果存在元素e出现频率超过半数，那么数组中最后剩下的就只有e。 
           top 2  Majority Element (more than n/3 times.) 
            */  
            List<Integer> list=new ArrayList<Integer>();  
            if(nums==null)  
                return list;  
            int[] count=new int[2];  
            int[] candidate=new int[2];  
            candidate[0]=0;  
            candidate[1]=1;  
            for(int i : nums){  
                if(candidate[0]==i){  
                    count[0]++;  
                }  
                else if(candidate[1]==i){  
                    count[1]++;  
                }  
                else if(count[0]==0){  
                    candidate[0]=i;  
                    count[0]=1;  
                }  
                else if(count[1]==0){  
                    candidate[1]=i;  
                    count[1]=1;  
                }  
                else{  
                    count[0]--;  
                    count[1]--;  
                }  
            }  
            for(int j=0;j<2;j++){  
                count[j]=0;  
            }  
            for(int k : nums){//验证count是否满足n/3  
                if(k==candidate[0])  
                     count[0]++;  
                else if(k==candidate[1])  
                    count[1]++;  
            }  
            for(int l=0;l<2;l++){  
                if(count[l]>nums.length/3&&!list.contains(candidate[l]))  
                     list.add(candidate[l]);  
            }  
            return list;  
        }  