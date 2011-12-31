### Test program for CFun interpreter ###
#
#   @author J.Michalski
#   @version 0.2
#
#########################################

#### comments test ####
#one line comment

#multi
#lines
#comment


#### functions test ####

### function declaration

#basic, most gramatical form
a(x: x!=0) = x + 1
#shortened form
b(x!=0) = x + 1

#shortest form
c(x) = x + 1

### multiple cases test
#absolute value
abs(x: x>=0) = x
abs(x: x<0)  = -1 * x #negative numbers not working yet

### recursion test
#fibonacci numbers
fib(x: x=0) = 0
fib(x: x=1) = 1
fib(x: x)   = fib(x-1)+fib(x-2)
#shortened fib
fib(0) = 0
fib(1) = 1
fib(x) = fib(x-1) + fib(x-2)

#greatest common divisor (euclidian algorithm)
gcd(a,b: a!=0, b=0)  = a
gcd(a,b: a!=0, b!=0) = gdc(b, a%b)

#### lists test ####
#basic list
simpleList() = [0,1,2,3]

#list generated with an inequality
generatedList(x) = [_y: (2*x) > _y > x]

#list generated with a function
listaGenerowanaFunkcja(x) = [fib(x): x>0]

#### input/output test ####
main() = [fib(0),fib(1),fib(2),gdc(99,121),simpleList()]
