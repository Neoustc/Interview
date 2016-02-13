 bool isPowerOfThree(int n) 
 {
   return fmod(log10(n)/log10(3), 1)==0;//Returns the floating-point remainder of numer/denom
 }
