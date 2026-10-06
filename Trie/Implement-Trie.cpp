class TrieNode{
public:
    TrieNode *children[26];
    bool end;
    TrieNode() {
        
        end = false;
        for(int i=0;i<26;i++)
        {
            children[i] = nullptr;
        }
    }
    TrieNode(bool end) {
        
        this->end = end;
        for(int i=0;i<26;i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for(int i=0;i<word.size();i++)
        {
            int letterInd = word[i]-'a';

        // do not create new node every time, only create when it doesn't exist
            if(curr->children[letterInd] == nullptr)
                curr->children[letterInd] = new TrieNode();

            curr = curr->children[letterInd];
        }
        
        curr->end = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for(int i=0;i<word.length();i++)
        {
            int letterInd = word[i]-'a';
            if(curr->children[letterInd] == nullptr) return false;

            curr = curr->children[letterInd];
        }
    
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(int i=0;i<prefix.length();i++)
        {
            int letterInd = prefix[i]-'a';
            if(curr->children[letterInd] == nullptr) return false;

            curr = curr->children[letterInd];
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
