#include<bits/stdc++.h>
using namespace std;
vector<int> alls; // 存储所有待离散化的值
// 二分求出x对应的离散化的值
int find(int x) // 找到第一个大于等于x的位置
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // 映射到1, 2, ...n
}

int main(){
    sort(alls.begin(), alls.end()); // 将所有值排序
    alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素
    return 0;
}
//作者：yxc
//链接：https://www.acwing.com/blog/content/277/
//来源：AcWing
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。