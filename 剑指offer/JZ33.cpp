//把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。
//求按从小到大的顺序的第N个丑数。
class Solution {
public:
//用空间换时间
    int GetUglyNumber_Solution(int index) {
        if(index <= 0 ) return 0;
        int *pugly = new int [index];
        pugly[0]=1;
        int nextIndex= 1;
        int *p2 = pugly;
        int *p3 = pugly;
        int *p5 = pugly;
        while(nextIndex<index){
            int min = Min(*p2 * 2,*p3 * 3,*p5 * 5);
            pugly[nextIndex]=min;
            while (*p2 *2 <=pugly[nextIndex])
            {
                ++p2;
            }
            while (*p3 *3 <=pugly[nextIndex])
            {
                ++p3;
            }
            while (*p5 *5 <=pugly[nextIndex])
            {
                ++p5;
            }
            ++nextIndex;
        }
        int ugly = pugly[nextIndex-1];
        delete []pugly;
        return ugly;
    }
    int Min(int n1,int n2,int n3){
        int min = n1<n2?n1:n2;
        min = min<n3?min:n3;
        return min;
    }
}; 