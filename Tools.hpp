#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <chrono>
#include <cstdio>

#include "Primes.hpp"

namespace
{

inline Primes::PrimeSP getPrimes(uint64_t primesUpTo, Primes::ExecPolicy policy)
{
  std::cout << "\tPrime calculation from 0 to " << primesUpTo << "..." << std::endl;

  auto start = std::chrono::high_resolution_clock::now();
  auto primeGenerator = Primes::Primes(primesUpTo, policy);
  primeGenerator.generate();
  auto end = std::chrono::high_resolution_clock::now();

  auto strPolicy = (policy == Primes::ExecPolicy::Sequenced) ? "Sequenced" : "MultiTasked";
  std::cout << strPolicy << " took "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
            << "ms" << std::endl;
  return primeGenerator.primes();
}

inline void showDetails(Primes::PrimeSP primes, int showLimit = 25)
{
  auto show = [&](auto txt, auto start, auto end){
    std::cout << txt;
    for(auto i = start ; i < end ; ++i) {
      std::cout << primes->at(i) << " ";
    }
    std::cout << std::endl;
  };

  std::cout << "\t" << primes->size() << " prime numbers detected" << std::endl;
  show("\tFirst primes: ", 0, showLimit);
  show("\tLast  primes: ", primes->size()-showLimit, primes->size());
}

}

#endif