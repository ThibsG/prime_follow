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
#include <vector>

#include "Tools.hpp"
#include "Repartition.hpp"

using namespace std;

template<typename T>
void check(T&& results);
void parseArguments(int argc, char** argv, uint64_t& n);

int main(int argc, char** argv)
{
  uint64_t primesUpTo = 0;
  parseArguments(argc, argv, primesUpTo);

  if(primesUpTo <= 0)
    throw runtime_error("Please assert that -n option >0");

  vector<future<Primes::PrimeSP>> futures;
  futures.push_back(
    async(getPrimes, primesUpTo, Primes::ExecPolicy::Sequenced)
  );
  futures.push_back(
    async(getPrimes, primesUpTo, Primes::ExecPolicy::MultiTasked)
  );

  vector<Primes::PrimeSP> primes;
  for(auto& e : futures) {
    primes.push_back(e.get());
  }

  check(primes);
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

template<typename T> void check(T&& results)
{
  auto show = [&](auto which, auto res) {
    cout << which << res->size() << endl;
    for(auto& e : *res)
      cout << e << " ";
    cout << endl;
  };

  auto first  = results.at(0);
  auto second = results.at(1);

  if(*first != *second) {
    show("First: ",  first);
    show("Second: ", second);
    throw runtime_error("Primes should be equal");
  }
}