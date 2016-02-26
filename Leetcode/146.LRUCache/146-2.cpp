// basic container should be a list, suitable for delete and add element;
// Also need a hashtable for get (key) = value operations.
// So we need a media to connect hashtable and list. so we implement value of table by a pair<key, list::iterator>;
// cache must store the key, otherwise you can find the table's key(position) through the cache's value;
 LRUCache(int capacity) {
       _capacity = capacity; 
    }
    
    int get(int key) {
     	if (table.count(key) > 0) 
     		{
     			use(table.find(key));
     			return (table[key].first);
     		}
     	return -1;
    }
    
    void set(int key, int value) {
        auto it = table.find(key);
    	if (it!= table.end())
    		{
    			use(it);
    		//	(*table[key].second) = value;
    		}
    	else {
    		if (table.size() == _capacity)//table.size() takes constant time, but the cache.size() takes linear time;
    		 {
           	 table.erase(cache.back());
          	 cache.pop_back();
             }
             cache.push_front(key);
    	}
             table[key] = {value, cache.begin()};
    }
private:
	unordered_map<int, pair <int, list<int>:: iterator> > table;
	list<int> cache;
	int _capacity;

	void use (unordered_map <int, pair<int, list<int> :: iterator> > :: iterator it)
	{
		int key = it -> first;
		cache.erase(it -> second.second);
		cache.push_front(key);
		it -> second.second = cache.begin();
	}




	
