 string getHint(string secret, string guess)
 {
 	int bull = 0, both = 0, n = secret.size();
 	for (int i = 0; i < n; ++i)
 		bull += (secret[i] == guess[i]);
 	for (char c = '0' ; c <= '9'; c++)
 		both += min(count(secret.begin(), secret.end(), c), 
 			count(secret.begin(), secret.end(), c));
 	return to_string(bull) + "A" + to_string(both - bull) + "B";
 }
