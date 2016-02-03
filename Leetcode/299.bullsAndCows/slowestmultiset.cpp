 string getHint(string secret, string guess) {
        int bull = 0, both = 0, n = secret.length();
        for (int i = 0; i < n; i++)
            bull += (secret[i] == guess[i]);
        multiset<char> s(secret.begin(), secret.end()), g(guess.begin(), guess.end());
        for (char c = '0'; c <= '9'; c++)
            both += min(s.count(c), g.count(c));
        return to_string(bull) + "A" + to_string(both - bull) + "B";
    }
