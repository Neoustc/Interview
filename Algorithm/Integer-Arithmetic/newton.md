Integer Arithmetic 

catalan number
set p of balanced parentheses strings

$ \lambda $ belongb to p ( lamba is the empty string )
 if $\alpha  and  \beta$ belong to p then (alpha) beta belong to p
Every nonempty balanced parenthers string from a unique alpha and beta

Cn=$\Sigma Ck*Cn-k$   (0<=k<=n  )n>=0


**Newton's Method：**
x0 = 1 (initial guess)
$x_i+1 = (x_i+a/x_i)/2$
` it's a quadratic convergence rate
so if we need d digits of precision 
we just d iterations` 

**Multiplication Algorithm**
divide and conquer: x1, x2, y1, y2
T(n)=4T(n/2)+$\theta(n)=\theta(n^2)$
**karatsuba** :
reduce to 3 multiplication
T(n)=3T(n/2)+$\theta(n) = \theta(n^1.58)$
**Toom-Cook** 
split num to 3 part
T(n)=5T(n/2)+$\theta(n)=\theta(n^log3,5)$
 
 High-precision Division
 newton's method :
 2* x_i-b*x_i^2/r



