class TrieNode {
public:
  bool is_word;
  TrieNode* next[26];
  TrieNode() : is_word(0){
    memset(next,0,sizeof(TrieNode*)*26);//FASTER
  }
};

class WordDictionary {
public:
    WordDictionary(){
      root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
      TrieNode * p = root;
       for (char c : word)
       {
        if (!p -> next[c - 'a'])
          p -> next[c - 'a'] = new TrieNode();
        p = p -> next[c - 'a']; 
       }
       p -> is_word = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        TrieNode * p = root;
        int n = word.size();
        for (int i = 0; i < n; ++i)
        {
          if (word[i] == '.')
          {
            for (int j = 0; j < 26; ++j)
            {
              if (p -> next[j])
              {
                if (find (word.substr(i + 1), p -> next[j]))return true;
              } 
            } 
            return false;
          }
          else 
          {
            if (! p -> next[word[i] - 'a'] ) return false;
            p = p -> next[word[i] - 'a'];
          }
        }
        return p && p -> is_word;
      }
      
      bool find(string word, TrieNode * node)
      {
         if (word == "") return node && node -> is_word;
        for (int i = 0; i< word.size(); ++i)
        {
          if (word[i] != '.') {
          if (node -> next[word[i] - 'a'])
            node = node -> next[word[i] - 'a'];
          else return false;
          }
          else {
            for (int j = 0; j < 26; ++j)
            {
              if (node -> next[j]) {
               if (find (word.substr(i + 1), node -> next[j])) return true;
              }
            }
            return false;
          }
        }
        return node && node -> is_word;
      }
private : 
   TrieNode * root;
};
