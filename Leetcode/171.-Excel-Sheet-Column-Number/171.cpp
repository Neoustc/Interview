int titleToNumber(string s) {
      int n=s.size();
      int col=0;
      for (int i = 0; i < n; ++i)
      {
      	col=col*26+(s[i]-'A'+1);
      }
      return col;
    }
};
