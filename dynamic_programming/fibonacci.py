import sys

fib = [-1 for _ in range(10000)]

def fibonacci(n):
    if n < 0:
        print("Wrong answer!")
        return -1
    
    if n == 0 or n == 1:
        return n
    
    if fib[n] != -1:
        return fib[n]
    
    res = fibonacci(n - 1) + fibonacci(n - 2)
    fib[n] = res
    return res

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    print(fibonacci(n))
    