http://blog.csdn.net/u010738052/article/details/50481559
class TrieNode
{
public:
	TrieNode* next[52];//upper and lower case
	bool end_Word;
	int sons;
	TrieNode() : end_Word(false), sons(0) //(bool end_Word = false)
	{
		for (int i = 0 ; i < 52; ++i)
			next[i] = NULL;
	}
};
class Trie
{
public:
  	TrieNode * root;
	Trie ()
	{
		root = new TrieNode();
	}
	void insert(string word) {
		TrieNode * p = root;
		for (char c : word)
		{
			if (c >= 'a')
			{
				if (p -> next[c - 'a'] == NULL)
					{
						p -> next[c - 'a'] = new TrieNode();
						p -> sons ++;
					}
				p = p -> next[c - 'a'];
			}
			else
			{
				if (p -> next[c - 'A' + 26] == NULL)
					{
						p -> next[c - 'A' + 26] = new TrieNode();
						p -> sons ++;
					}

				p = p -> next[c - 'A' + 26];	
			}
		}
		p -> end_Word = true;
	}
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
    	Trie T;
    	for(auto str : strs)
    		T.insert(str);
    	return findPrefix(T);
    }
private :
	string findPrefix(Trie& T)
	{
		TrieNode* p = T.root;
		string res = "";
		int i = 0;
		while (p -> sons == 1 && !p -> end_Word)
		{
			for (i = 0; i < 52; ++i)
			{
				if (p -> next[i])
				{
					if (i < 26)
						res += char('a' + i);
					else 
						res += char('A' + i - 26);
					break;
				}
			}
			if (i == 52) break;
			p = p -> next[i];
		}
		return res;
	}
};
