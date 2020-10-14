#include<bits/stdc++.h> 
using namespace std;

class MaxHeap{
    int heap_size,capacity;
    int heaparr[100005];
    public: 
    
    int parent(int child)
    { 
        int p = (child - 1)/2;
        if (child == 0)
            return -1;
        else
            return p;
    } 

    int left(int i)
    { 
        int l=2*i + 1;
        if (l < heap_size)
            return l;
        else
            return -1;
    }

    int right(int i)
    { 
        int r=2*i + 2;
        if (r < heap_size)
            return r;
        else
            return -1;
    } 
    MaxHeap(){
        heap_size=0;
    }
    
    int getMax(){
         return heaparr[0]; 
    }

    void heapifyup(int idx)
    {
        if (idx >= 0 && parent(idx) >= 0 && heaparr[parent(idx)] < heaparr[idx])
        {
            int temp = heaparr[idx];
            heaparr[idx] = heaparr[parent(idx)];
            heaparr[parent(idx)] = temp;
            heapifyup(parent(idx));
        }
    }

    void heapifydown(int idx)
    {
        int child = left(idx);
        int child1 = right(idx);
        if (child >= 0 && child1 >= 0 && heaparr[child] < heaparr[child1]) 
        {
            child = child1;
        }
        if (child > 0 && heaparr[idx] < heaparr[child])
        {
            int t = heaparr[idx];
            heaparr[idx] = heaparr[child];
            heaparr[child] = t;
            heapifydown(child);
        }
    }

    void Insert(int ele)
    {
        heaparr[heap_size]=ele;
        heap_size+=1;
        heapifyup(heap_size -1);
    }
    void delet()
    {
        if (heap_size == 0)
        {
            return;
        }
        heaparr[0] = heaparr[heap_size - 1];
        heap_size-=1;
        heapifydown(0);
    }
    
}; 
int main()
{
   int t,n,m,i,j,x,y;
   MaxHeap h;
   cin>>n;
   for(i=0;i<n;i++)
   {
       cin>>x;
       h.Insert(x);
   }
   for(i=0;i<n;i++)
   {
       cout<<h.getMax()<<endl;
       h.delet();
   }
   
}
