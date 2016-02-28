int candy(vector<int>& ratings) 
{
     int n = ratings.size();
     if (n <= 1) return n;
     int range = 0, min_candies = n;//allot 1 each child
     for (int i = 0; i < n - 1;)
     {
          int start = i;
          //1,2,3,2    
          //s   i

          while (ratings[i] < ratings[i + 1] && i < n - 1) ++i;
          range = i - start;
          min_candies += (range * ( range + 1 )) / 2;

          if ( i == n - 1) break;

          start = i;
          while (ratings[i] > ratings[i + 1] && i < n - 1) ++i;
          int k = i - start - 1;
          min_candies += (k * (k + 1)) / 2;
          if (i - start > range) min_candies += (i - start- range);
          if (ratings[i] == ratings[i + 1]) ++i;
     }
     return min_candies;
}
