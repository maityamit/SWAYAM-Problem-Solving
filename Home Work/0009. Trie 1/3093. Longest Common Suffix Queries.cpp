struct Node {
	Node *links[26];
    int len=1e9;
    int idx=-1;
	bool flag = false;
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	void setEnd() {
		flag = true;
	}
	bool isEnd() {
		return flag;
	}
};
class Trie {
private:
	Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string word,int idx) {
        Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
            //node->ind[idx]=(int)word.size();
            if(node->len>=word.size()){
                if(node->len==word.size()) node->idx=min(node->idx,idx);
                else node->idx=idx;
                node->len = word.size();
            }
			node = node->get(word[i]);
		}
        if(node->len>=word.size()){
            if(node->len==word.size()) node->idx=min(node->idx,idx);
            else node->idx=idx;
            node->len = word.size();
        }
		node->setEnd();
    }
 
    Node* finishLine(string word){
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                return node;
            }
            node = node->get(word[i]);
        }
        return node;
    }
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> ans;
        for(auto &it:wordsContainer) reverse(it.begin(),it.end());
        for(auto &it:wordsQuery) reverse(it.begin(),it.end());
        
        Trie tr;
        for(int i=0;i<wordsContainer.size();i++){
            tr.insert(wordsContainer[i],i);
        }
        for(int i=0;i<wordsQuery.size();i++){
            Node* node = tr.finishLine(wordsQuery[i]);
            ans.push_back(node->idx);
        }
        
        
        return ans;
        
    }
};