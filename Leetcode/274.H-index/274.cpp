 int hIndex(vector<int>& citations) {
		int n=citations.size(),h=0;
		int *counts=new int[n+1]();
		for(int c:citations)
			counts[min(c,n)]++;
		for(int i=n;i;--i)
		{
			h+=counts[i];
			if(h>=i)return i;
		}
	return h;
	}
