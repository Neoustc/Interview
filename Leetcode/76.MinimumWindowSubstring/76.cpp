//1. store the char and count for chars in T.
//2. use a window  represent by start and end to find the result.
//3. first move the end to just find a window that meets requirement.
// a. decrease the mp[s[end]];	
// b. if a char is in the t, decrease the count;
// c. when the count == 0, that means we find a target sustring;
// d. Enter the inner loop check the length is smaller or not and update the record;
// e. so far we have a window size, we try to fix the end and move the start to shrink the window,
// f. increase the mp[s[start]](correponding with a(first) step);
// g. if the mp[s[start]] > 0, means the s[start] in the T, we need increase count and stop move the start and jump out of
//the inner loop,
// h. else  it means we are safe, the start skip the elements are all not in the T, and we can update the window record.
// 4. repeat until the end >= size; 
 string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for (auto c : t)
        	m[c]++;
        int start = 0, end = 0, counter = t.size();
        int size = s.size(), minStart = 0, minLen = INT_MAX;
        //move end to find a valid window;
        while (end < size)
        {
        	if (m[s[end]] > 0)
        		counter--;
        	m[s[end]]--;
        	end++;
        	while (counter == 0)
        	{
        		if (end - start < minLen)
        		{
        			minStart = start;
        			minLen = end - start;
        		}
        		m[s[start]]++;
        		if (m[s[start]] > 0)
        			counter ++;
        		start++;
        	}
	    }
	    if (minLen != INT_MAX)
	    	return s.substr(minStart, minLen);
	    return "";
    }
