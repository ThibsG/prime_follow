# Prime follow distribution or distribution of consecutive primes


__Resources__ :
* https://www.quantamagazine.org/20160313-mathematicians-discover-prime-conspiracy/
* https://terrytao.wordpress.com/2016/03/14/biases-between-consecutive-primes/


In classic primes distribution, it is admitted that for any positive integer, primes are equaly distributed.

It means that in general, $\frac14$ of primes ends in 1, 3, 7 or 9.

But when we take a look at consecutive primes, they do not act like expected.

We expect that a prime ending by 1 should have 25% of chance to be followed by another prime ending by 1.

In fact, it is only 18,5%... For 3 or 7, it is 30%. For 9, it is 22%.

They do not follow equidistributed !



This code gives probability for a prime ending by 1, 3, 7 or 9 to be followed by a prime ending by 1, 3, 7 or 9.

Upper real limit is 25x10^6.

# TODO

Actually the code gives probability for a prime to be followed by itself.
- Impossible to process large amount (100.000.000 elements). Do chunk processing
- Multi-threading
- Perform time analysis
- Add tests
