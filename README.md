# Prime follow distribution


__Resource__ : https://www.quantamagazine.org/20160313-mathematicians-discover-prime-conspiracy/


In classic primes distribution, it is admitted that for any positive integer, primes are equaly distributed.

It means that in general, \frac{1}/{4} of primes ends in 1, 3, 7 or 9.

But when we take a look at consecutive primes, they do not act like expected.

We expect that a prime ending by 1 should have 25% of chance to be followed by another prime ending by 1.

In fact, it is only 18,5%... For 3 or 7, it is 30%. For 9, it is 22%.

They do not follow equidistributed !



This code gives probability for a prime ending by 1, 3, 7 or 9 to be followed by a prime ending by 1, 3, 7 or 9.

Upper real limit is 25x10^6.

# TODO

Actually the code gives probability for a prime to be followed by itself.
- Do it for all primes by all primes
- Impossible to process large amount (100.000.000 elements). Do chunk processing
