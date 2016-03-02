 bool isSelfCrossing(vector<int>& x) {
       for (int i = 3, n = x.size(); i < l; ++i)
       	{
       		//case 1 : current line cross with line 3 steps ahead of it;
       		if (x[i] >= x[i - 2] && x[i - 1] <= x[i -3]) return true;
       		//case 2 : current line cross with line 4 steps ahead of it;
       		else if (i >= 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2]) return true;
       		//case 3 : current line cross with line 6 steps aheado f it;
       		else if (i >= 5 && x[i - 2] >= x[ i - 4] && x[i] + x[i - 4] >= x[i - 2] && x[i- 1] <= x[i - 3] && x[i - 5] + x[i - 1] >= x[i - 3])
       			return true;
       	}

    }
