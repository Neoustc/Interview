lower bound:
Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.(first greater or equal one)

upper_bound:
Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
can't find will return end();

example:
v = 10,10,10,20,20,20,30,30 (size = 8)

std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

lower_bound(v.begin(),v.end(),20);     
upper_bound(v.begin(),v.end(),20);   

>> 3, 6

lower_bound(v.begin(),v.end(),15);     
upper_bound(v.begin(),v.end(),15);   
>> 3, 3

lower_bound(v.begin(),v.end(),8);     
upper_bound(v.begin(),v.end(),8);   
>> 0, 0

lower_bound(v.begin(),v.end(),10);     
upper_bound(v.begin(),v.end(),10);   
>> 0, 3


lower_bound(v.begin(),v.end(),30);     
upper_bound(v.begin(),v.end(),30);   
>> 6, 8

lower_bound(v.begin(),v.end(),35);     
upper_bound(v.begin(),v.end(),35);   
>> 8, 8
