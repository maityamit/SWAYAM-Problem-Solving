struct Node{
	Node* links[2];
	bool containsKey(int bit){
		return (links[bit]!=NULL);
	}
	Node* get(int bit){
		return links[bit];
	}
	void put(int bit,Node* node){
		links[bit]=node;
	}
};
class TrieXOR{
public:
	Node* root;
	TrieXOR(){
		root = new Node();
	}
	void insert(int num){
		Node* node = root;
		for(int i=31;i>=0;i--){
			int bit = (num>>i)&1;
			if(!node->containsKey(bit)){
				node->put(bit,new Node());
			}
			node = node->get(bit);
		}
	}
	int getMax(int num){
		Node* node = root;
		int maxNum = 0;
		for(int i=31;i>=0;i--){
			int bit = (num>>i)&1;
			if(node->containsKey(1-bit)){
				maxNum = maxNum | (1<<i);
				node = node->get(1-bit);
			}else{
				node = node->get(bit);
			}
		}
		return maxNum;
	}
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi = 0;
        TrieXOR tr;
        for(auto it:nums) tr.insert(it);
        for(auto it:nums) maxi=max(maxi,tr.getMax(it));
        return maxi;
    }
};