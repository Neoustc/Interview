 double myPow(double x, int n) {
       	if(n==0)return 1;
       	 if(n < 0)
       	  { 
       	  	x=1/x;
       	  	if(n == INT_MIN) 
       	 	return (myPow(x, INT_MAX) * x);
       	    n=-n;//cause overflow
          }
      return (n%2==0)?myPow(x*x,n/2):myPow(x*x,(n-1)/2)*x;
    }
