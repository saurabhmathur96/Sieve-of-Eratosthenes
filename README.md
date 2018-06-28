Sieve-of-Eratosthenes
=====================

A program that generates prime numbers upto n.

It is an implementation of the Sieve of Eratosthenes in C.

### Usage
```
prime [n] [filename]
```
where n is the limit upto which prime numbers are to be generated and,
filename is an optional parameter that is the name of the output file. 
If no output file is specified, it defaults to *stdout*.

*For example*
```
prime 10
```
will give output 
```
Number of primes = 4
2, 3, 5, 7
```

while
```
prime 10 primes_less_than_ten.txt
```
will create a new text file named *primes_less_than_ten.txt* that contains **2, 3, 5, 7**.
