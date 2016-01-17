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
compute the “official” string representation of an object

r[1:] = `n` 
it replaces everything after the first element in r (or everything, in case r is empty) by just n

——————————————————————————————————————————————————————————————————————————————————————————————
enumerate(iterable, start=0)
Return an enumerate object. iterable must be a sequence, an iterator, or some other object which supports iteration
>>> seasons = ['Spring', 'Summer', 'Fall', 'Winter']
>>> list(enumerate(seasons))
[(0, 'Spring'), (1, 'Summer'), (2, 'Fall'), (3, 'Winter')]
>>> list(enumerate(seasons, start=1))
[(1, 'Spring'), (2, 'Summer'), (3, 'Fall'), (4, 'Winter')]

**************
zip(*iterables)
# zip('ABCD', 'xy') --> Ax By
Make an iterator that aggregates elements from each of the iterables.
Returns an iterator of tuples, where the i-th tuple contains the i-th element from each of the argument sequences or iterables.
zip() in conjunction with the * operator can be used to unzip a list:
 
 *************************
 Lambda expressions (sometimes called lambda forms) are used to create anonymous functions. 
 The expression    ** lambda arguments: expression **    yields a function object. 
 The unnamed object behaves like a function object defined with

*********************
reduce(function, iterable[, initializer])
Apply function of two arguments cumulatively to the items of sequence, from left to right,so as to reduce the sequence to a single value.

For example, reduce(lambda x, y: x+y, [1, 2, 3, 4, 5]) calculates ((((1+2)+3)+4)+5).

The left argument, x, is the accumulated value and the right argument, y, is the update value from the sequence. 
If the optional initializer is present, it is placed before the items of the sequence in the calculation, and serves as a default when the sequence is empty. 
If initializer is not given and sequence contains only one item, the first item is returned.
