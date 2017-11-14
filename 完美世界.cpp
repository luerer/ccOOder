//重叠区间个数
#include <bits/stdc++.h>
using namespace std;
class Interval  
{  
public:  
    Interval( int iStart, int iEnd)  
        :m_iStart( iStart), m_iEnd(iEnd){}  
    int m_iStart;  
    int m_iEnd;  
};  
  
typedef vector<Interval> IntervalVec;  
  
  
//区间拆分的点定义  
class PointComparable  
{  
public:  
    PointComparable( int iVal, int iType )  
        :m_iVal( iVal ), m_iType( iType ){}  
  
    //重载小于操作符，排序使用  
    bool operator < ( const PointComparable& pcPoint )  
    {  
        if ( this->m_iVal == pcPoint.m_iVal )  
        {  
            return this->m_iType < pcPoint.m_iType;  
        }  
        return this->m_iVal < pcPoint.m_iVal;  
    }  
  
    int m_iVal;  
    int m_iType;//点类型，0为起点，1为终点  
};  
  
int GetOverlappedIntervalMaxCount( const IntervalVec& intvVec )  
{  
    vector<PointComparable> pcVec;  
    for ( IntervalVec::const_iterator it = intvVec.begin();  
        it != intvVec.end(); ++it )  
    {  
        pcVec.push_back( PointComparable( it->m_iStart, 0 ) );  
        pcVec.push_back( PointComparable( it->m_iEnd, 1 ) );  
    }  
  
    sort( pcVec.begin(), pcVec.end() );  
  
  
  
    int iMaxCount = 0;  
    int iCurCount = 0;  
    for ( vector<PointComparable>::iterator itTemp = pcVec.begin();  
        itTemp != pcVec.end(); ++itTemp )  
    {  
        //cout << itTemp->m_iVal << " " << itTemp->m_iType << endl;  
        if ( itTemp->m_iType == 0 )  
        {  
            iCurCount++;  
            iMaxCount = __max( iCurCount, iMaxCount );  
        }  
        else  
        {  
            iCurCount--;  
        }  
    }  
  
    return iMaxCount;  
}  
  
int main()  
{  
    int n;
    cin>>n;
    IntervalVec intvVec(n, Interval(0,0));
  
  	for(int i=0; i<n; ++i)
  		cin>>intvVec[i].m_iStart;

  	for(int i=0; i<n; ++i)
  		cin>>intvVec[i].m_iEnd;
     
    cout<<GetOverlappedIntervalMaxCount(intvVec)<<endl;
    return 0;
}