class Trie {
public:
     struct node{
            struct node *val[26];
            bool exist=false;
        };
    node *root;
    
    /** Initialize your data structure here. */
    Trie() {
        root=new node();
    }
    // node root;
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        struct node *curr=root;
        for(int i=0;i<word.length();i++)
        {
            int tmp=word[i]-'a';
            if(curr->val[tmp]==NULL)
                curr->val[tmp]=new node();
            curr=curr->val[tmp];
        }
        curr->exist=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        struct node *curr=root;
        for(int i=0;i<word.length();i++)
        {
            int tmp=word[i]-'a';
            if(curr->val[tmp]==NULL)
                return false;
            curr=curr->val[tmp];
        }
        if (curr->exist)
            return true;
        return false;
        
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        struct node *curr=root;
        for(int i=0;i<prefix.length();i++)
        {
            int tmp=prefix[i]-'a';
            if(curr->val[tmp]==NULL)
                return false;
            curr=curr->val[tmp];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */