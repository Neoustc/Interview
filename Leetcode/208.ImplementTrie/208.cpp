class TrieNode {
public:
    // Initialize your data structure here.
    bool isEnd;
    TrieNode * next[26];
    TrieNode() {
       for (int i = 0 ; i < 26; ++i)
            next[i] = NULL;
        isEnd = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode * p = root;
        for (int i : word)
        {
            if (p -> next[i - 'a'] == NULL)
                p -> next[i - 'a'] = new TrieNode ();
            p = p -> next[i - 'a'];
        }
        p -> isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * p = root;
        for (int i : word)
        {
            if (p -> next[i - 'a'])
               p = p -> next[i - 'a'];
            else return false;
        }
        return p -> isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
       TrieNode * p = root;
        for (int i : prefix)
        {
            if ( p -> next[i - 'a'])
              p = p -> next[i - 'a']; 
            else return false;
        }
        return p != NULL;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
