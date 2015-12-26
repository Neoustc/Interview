//http://blog.csdn.net/u010738052/article/details/50411277
 #include <iostream>
 class solution{
 public:
// also can use division method or multipcation method 
//h(k)=k mod m;    m is random prime >=|s|;
 inline char hash(const string &s)
 {
    char all=0;
    for(i:s)
        all^=i;
    return all;
 }
 int strStr(string haystack, string needle) {
 int i=0,hsize=haystack.size(),nsize=needle.size();
 char target;
   if(hsize<nsize)return 0;
   target=hash(needle);
   for(;i<hsize-nsize;i++) 
   {
    if(hash(haystack.substr(i,nsize))==target&&haystack(i,nszie)==needle)break;    
   }
   return i<=hsize-nsize?i:-1
  }
 }
