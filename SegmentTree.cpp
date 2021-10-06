class NumArray {
public:
    
    void buildTree(vector<int> &nums,vector<int>& tree,int s,int e,int index){
        
        if(s==e) {tree[index]=nums[s]; return ;}
        
        int mid=(s+e)/2;
        buildTree(nums,tree,s,mid,2*index);
        buildTree(nums,tree,mid+1,e,2*index+1);
        tree[index]=tree[2*index] + tree[2*index+1]; // building the tree in bottom up fashion
        return;
    }
    
    vector<int> tree;
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        if(n==0) return ;
        tree.resize(4*n+1);
        buildTree(nums,tree,0,n-1,1);
        // for(int i=1;i<=3;i++) cout<<tree[i]<<" ";
    }
    
    void pointUpdate(vector<int>&tree,int ss,int se,int i,int value,int index){
        if(i<ss || i> se) return ;
        if(ss==se){
            tree[index]=value;
            return;
        }
        int mid=(ss+se)/2;
        pointUpdate(tree,ss,mid,i,value,2*index);
        pointUpdate(tree,mid+1,se,i,value,2*index+1);
        
        tree[index]=tree[2*index]+tree[2*index+1];
    }
    void update(int i, int val) {
        if(n==0) return ;
        pointUpdate(tree,0,n-1,i,val,1);
        cout<<endl;
    }
    
    int query(vector<int>& tree,int ss,int se,int qs,int qe,int index){
       // complete overlap 
	   if(se<=qe and ss>=qs) return tree[index];
       
	   // out of bounds
	   if(qs>se || qe<ss) return 0;
        
        // partial overlap 
        int mid=(ss+se)/2;
        int left=query(tree,ss,mid,qs,qe,2*index);
        int right=query(tree,mid+1,se,qs,qe,2*index+1);
        
        return left+right;
        
    }
    int sumRange(int i, int j) {
        if(n==0) return 0;
        return query(tree,0,n-1,i,j,1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

// Refer Segment Tree Directory for Better Implementation
