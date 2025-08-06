class Solution {
public:
    // Here we build the recursive function to build the segment tree. Now our next step will be:
    // To make the function which will update the queries
    int buildTree(vector<int>& segmentTree,vector<int>& nums,int indx,int l,int r){
        if(l == r){
            segmentTree[indx] = nums[l];
            return segmentTree[indx];
        }
        int mid = l + (r - l)/2;
        int leftNode = buildTree(segmentTree, nums,2 * indx + 1, l, mid);
        int rightNode = buildTree(segmentTree, nums,2 * indx + 2,mid + 1, r);
        int maxNode = max(leftNode,rightNode);
        segmentTree[indx] = maxNode;
        return maxNode;
    }
    // Here we create the Update Query. Now our task is t implement it
    void Update(vector<int>& segmentTree,int val,int indx,int l,int r){
        if(l == r){
            segmentTree[indx] = 0;
            return ;
        }   
        int mid = l + (r - l) / 2;
        if(val <= segmentTree[2 * indx + 1]){
            Update(segmentTree,val,2 * indx + 1,l,mid);
        }else{
            Update(segmentTree,val,2 * indx + 2, mid + 1, r);
        }
        segmentTree[indx] = max(segmentTree[indx * 2 + 1],segmentTree[indx * 2 + 2]);
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        //In this problem we have to use Segment tree to solve the problem 
        //We get the idea for the segment tree form the fact that 
        //if we want to find any thing in range for many thing then we use segment tree
        //first we will create the segment tree;
        //We will create the int data structure which will store the count of the element which we can store
        int n = fruits.size(); // n represent the size of the furits and the baskets vector
        int count = 0;
        vector<int> segmentTree(4 * n); // This will the vector which store the segmentTree
        buildTree(segmentTree,baskets,0,0,n-1);
        for(int i = 0; i < n; i++){
            if(fruits[i] <= segmentTree[0]){
                Update(segmentTree,fruits[i],0,0,n-1);
            }else{
                count++;
            }
        }
        return count;
    }
};