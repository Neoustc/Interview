 bool isMatch(string s, string p) {
		int n=s.size()-1;
		int m=p.size()-1;
		int i=0,j=0;
		if(m==-1)return -1==n;
		if(p[j+1]=='*')
			{	
				while(p[j]==s[i]||(p[j]=='.'&&s[i]))
				{
				  if(isMatch(s,p.substr(2)))
				  	return true;
				  s=s.substr(1);
				}
				return isMatch(s,p.substr(2));

			}
		else{
		    if(s[i]==p[j]||(p[j]=='.'&&s[i]))
			{
				return isMatch(s.substr(1),p.substr(1));
			}
			else return false;
		}

    }
