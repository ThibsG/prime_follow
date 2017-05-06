#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <unistd.h>
#include <future>
#include <exception>
#include <chrono>
#include <ctime>

#include "Primes.hpp"
#include "Repartition.hpp"

using namespace std;

void parseArguments(int argc, char** argv, uint64_t& n);


Primes::PrimeSP getPrimes(uint64_t primesUpTo, Primes::ExecPolicy policy)
{
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


int main(int argc, char** argv)
{
  uint64_t primesUpTo = 0;
  parseArguments(argc, argv, primesUpTo);

  if(primesUpTo <= 0)
    throw std::runtime_error("Please assert that -n option >0");

  std::vector<std::future<Primes::PrimeSP>> futures;
  futures.push_back(
    std::async(getPrimes, primesUpTo, Primes::ExecPolicy::Sequenced)
  );
  futures.push_back(
    std::async(getPrimes, primesUpTo, Primes::ExecPolicy::MultiTasked)
  );

  std::vector<Primes::PrimeSP> primes;
  for(auto& e : futures) {
    primes.push_back(e.get());
  }

  auto first = primes.at(0);
  auto second = primes.at(1);

  if(*first != *second) {
    std::cout << "First: " << first->size() << std::endl;
    for(auto& e : *first)
      std::cout << e << " ";
    std::cout << std::endl;

    std::cout << "Second: " << second->size() << std::endl;
    for(auto& e : *second)
      std::cout << e << " ";
    std::cout << std::endl;

    throw std::runtime_error("Primes should be equal");
  }

  return 0;
};


void parseArguments(int argc, char** argv, uint64_t& n)
{
  int c = 0;
  while((c = getopt(argc, argv, "n:")) != -1)
  {
    switch(c)
    {
      case 'n':
        n = atoll(optarg);
        break;
      default:
        abort();
    }
  }
}
