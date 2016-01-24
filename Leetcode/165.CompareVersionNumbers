int compareVersion(string version1, string version2) 
{
	int n1 = version1.size(), n2 = version2.size();
	int i = 0, j = 0;
	while (i < n1 || j < n2)
	{
		int a = 0, b = 0;
		while (i < n1 && isdigit(version1[i]))
		{
			a = a * 10 + (version1[i] - '0');
			i++;
		}
		while (j < n2 && isdigit(version2[j]))
		{
			b = b * 10 + (version2[j] - '0');
			j++;
		}
		if (a > b) return 1;
		if (a < b) return -1;
		if (a == b && i == n1 && j == n2) return 0;
		if (i < n1) i++;
		if (j < n2) j++;
	}
}
