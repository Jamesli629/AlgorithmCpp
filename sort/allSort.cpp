#include<bits/stdc++.h>
using namespace std;
#define N 105
#define fors(i,a,b) for(int i=a;i<b;++i)

int main(){
    void bubbleSort(int n[N],int sz);
    void selectSort(int num[N],int sz);
    void insertSort(int num[N],int sz);
    void merge(int num[N],int left,int mid,int right);
    void internalMerge(int num[N],int left,int right);
    void mergeSort(int num[N],int sz);
    void mergePass(int num[N],int length,int sz);
    void MergeSort(int num[N],int sz);
    int partition(int num[N],int low,int high);
    void qsort(int num[N],int s,int t);
    void quickSort(int num[N],int sz);
    void heapAdjust(int num[],int start,int end);
    void heapSort(int num[],int len);
    int a[]={3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    int sz=15;
    //bubbleSort(a,sz);
    //selectSort(a,sz);
    //insertSort(a,sz);
    //mergeSort(a,15);
    //MergeSort(a,sz);
    //quickSort(a,sz);
    heapSort(a,sz);
    fors(k,0,sz){
        cout<<a[k]<<" ";
    }
    cout<<endl;
    return 0;
}

/**
 * 冒泡排序
 * 稳定排序
 * 时间复杂度：O(n^2)
 * 适合小数据量的排序
 * 增加一个is_swap来简单优化一下
 */
void bubbleSort(int n[N],int sz){
    int temp;
    bool is_swap;
    fors(i,0,sz){
        is_swap=false;
        fors(j,i+1,sz){
            if(n[i]>n[j]){
                temp=n[i];
                n[i]=n[j];
                n[j]=temp;
                is_swap=true;
            }
        }
        if(!is_swap){
            break;
        }
    }
}

/**
 * 选择排序
 * 不稳定
 * 时间复杂度：O(n^2)
 * 各种情况下时间复杂度比较稳定，优于冒泡排序
 * 适用于简单的数据量
 */
void selectSort(int num[N],int sz){
    int temp;
    fors(i,0,sz){
        int min=i;
        fors(j,i+1,sz){
            if(num[min]>num[j]){
                min=j;
            }
        }
        if(min!=i){
            temp=num[i];
            num[i]=num[min];
            num[min]=temp;
        }
    }
}

/**
 * 插入排序
 * 稳定排序
 * 时间复杂度：O(n^2)
 * 适用在数据量较小的情况，一般作为快速排序的补充，用于少量数据的排序
 */
void insertSort(int num[N],int sz){
    fors(i,1,sz){
        int val = num[i];
        int pos = i;
        while(pos > 0 && num[pos-1]>val){
            num[pos]=num[pos-1];
            pos--;
        }
        num[pos] = val;
    }
}

/**
 * 归并排序
 * 稳定排序
 * 数据量比较大时表现优秀，但因为空间复杂度为O(n)，数据量特别大时要考虑机器本身内存，
 * 几乎不可接受
 */
void merge(int num[N],int left,int mid,int right){
    int i=left;
    int j=mid+1;
    int k=0;
    int *temp=new int[right-left+1];
    while(i<=mid && j<=right){
        temp[k++] = num[i]<=num[j]?num[i++]:num[j++];
    }
    while(i<=mid){
        temp[k++]=num[i++];
    }
    while(j<=right){
        temp[k++]=num[j++];
    }

    fors(i,0,k){//将数据复制回原数组
        num[left+i]=temp[i];
    }
}
//递归：
void internalMerge(int num[N],int left,int right){
    //当left==right时，就不需要再划分了
    if(left<right){
        int mid=(left+right)>>1;//与除2等效
        internalMerge(num,left,mid);//左子数组
        internalMerge(num,mid+1,right);//右子数组
        merge(num,left,mid,right);//合并左右子数组
    }
}
void mergeSort(int num[N],int sz){
    //sz表示要排序的数组的大小
    internalMerge(num,0,sz-1);
}
//非递归：
void mergePass(int num[N],int length,int sz){
    int i=0;
    for(;i+2*length-1<sz;i=i+2*length)
        merge(num,i,i+length-1,i+2*length-1);
    if(i+length-1<sz-1)
        merge(num,i,i+length-1,sz-1);
}
void MergeSort(int num[N],int sz){
    int length;
    for(length=1;length<sz;length=2*length){
        mergePass(num,length,sz);
    }
}

/**
 * 快速排序
 * 不稳定排序
 * 时间复杂度：O(nlogn)
 * 大多数情况下都适用，尤其在数据量大的时候性能优越性更加明显，但要考虑到最坏情况
 */
int partition(int num[N],int low,int high){
    int i=low,j=high;
    int temp=num[i];
    while(i<j){
        while(j>i && num[j]>=temp)
            j--;
        num[i]=num[j];
        while(i<j && num[i]<=temp)
            i++;
        num[j]=num[i];
    }
    num[i]=temp;
    return i;
}
void qsort(int num[N],int s,int t){
    if(s<t){
        int i=partition(num,s,t);
        qsort(num,s,i-1);
        qsort(num,i+1,t);
    }
}
void quickSort(int num[N],int sz){
    qsort(num,0,sz-1);
}

/**
 * 堆排序
 * 不稳定排序
 * 时间复杂度：O(nlogn)
 * 建堆和调整堆的开销较大，不适用于元素少时，适用于元素较多时。
 * 在解决诸如“前n大的数”一类问题时，几乎是首选算法。
 */
void heapAdjust(int num[],int start,int end){
    int dad = start;
    int son = 2 * dad + 1;
    while (son<=end)
    {
        if(son + 1 <=end && num[son]<num[son+1])
            son++;
        if(num[dad]>num[son])
            return;
        else{
            swap(num[dad],num[son]);
            dad = son;
            son = 2 * dad + 1;
        }
    } 
}
void heapSort(int num[],int len){
    for(int i = len /2-1;i>=0;i--){
        heapAdjust(num,i,len-1);
    }
    for(int i=len-1;i>0;i--){
        swap(num[0],num[i]);
        heapAdjust(num,0,i-1);
    }
}