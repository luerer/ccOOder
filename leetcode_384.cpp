/************
Shuffle an Array
大意：
题目不重要，需要一个方法：生成一个随机0-N-1的随机数组，不重复。
思路：
首先初始化一个0-N的数组，然后打乱顺序。打乱顺序的方法是：每次随机从原数组中选一个数出来，直到选完所有数
************/

vector<int> Shuffle(int N)
{
	int data[N]={0};
	int res[N]={0};
	for(int i=0; i<N; ++i)
		data[i]=i;
	for(int i=0; i<N; ++i)
	{
		int index = rand()%(N-i);
		res[i] = data[index];
		data[index] = data[N-1-i];//从后面补一个到该位置
	}
	return res;
}
//发现该方法空间复杂度高，其实不需要两个数组，在原数组中，每次选一个数后，将它和开头（这个开头是指没有被选到的部分的开头，不停移动至最后）交换
//改进的算法：
vector<int> Shuffle(int N)
{
	int res[N]={0};
	for(int i=0; i<N; ++i)
		res[i]=i;
	for(int i=0; i<N; ++i)
	{
		int index = rand()%(N-i);
		swap(res[i],res[i+index]);
	}
	return res;
}