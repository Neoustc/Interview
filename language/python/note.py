#comparison chaining
 testing whether a number is the largest of three: a < x > b
 a == b < c actually means a == b and b < c in python!
 
***
str.join(iterable)
#Return a string which is the concatenation of the strings in the iterable iterable
ex : ["->".join(["22","33","11"])]
['22->33->11']

***
Map(function, iterable)
Return an iterator that applies function to every item of iterable,
yielding the results. If additional iterable arguments are passed, 
function must take that many arguments and is applied to the items from all iterables in parallel. 
With multiple iterables, the iterator stops when the shortest iterable is exhausted.


`n`
Backquotes calls the __repr__() , so the result would be a string rather than a int

r[1:] = `n` 
it replaces everything after the first element in r (or everything, in case r is empty) by just n
