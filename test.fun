#komentarz

#rekurencyjny fibonaczi (na razie nie działa)
fib(0) = 0
fib(1) = 1
fib(x) = fib(x-1)+fib(x-2)

#inne listy
lista() = [0,1,2,3]
listaGenerowana(x) = [_y: (2*x) > _y > x] #lista generowana automatycznie

listaGenerowanaFunkcja(x) = [fib(x): x>0] #lista generowana za pomocą funkcji

#funkcja main
main() = [fib(0),fib(1),fib(2),fib(3)] #przykład list
