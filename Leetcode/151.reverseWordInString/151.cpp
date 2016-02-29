void reverseWords(string & s) {
	string r ;
	int i = s.size() - 1, end;
	while (i >= 0)
	{
		while (s[i] == ' ' && i >= 0) --i; //skip the trailing spaces;
		end = i + 1;	
		if (i >= 0 && !r.empty()) r += ' '; // add the space in the next loop to avoid the extra space in the tail
		while (s[i] != ' ' && i >= 0) --i; // find the start of the word;
		for (int k = i + 1; k < end; ++k)  // add chars from [k, end) to r;
			r += s[k];
	}
	s = r;
}
