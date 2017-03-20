#ifndef PRIMES_HPP
#define PRIMES_HPP

#include <memory>
#include <cstdint>
#include <vector>
#include <list>
#include <numeric>

namespace Primes
{

using PrimeSP = std::shared_ptr<std::vector<uint64_t>>;

inline PrimeSP primes(uint64_t primesUpTo)
{
  PrimeSP out(new std::vector<uint64_t>);
  std::list<uint64_t> table(primesUpTo - 2);
  std::iota(table.begin(), table.end(), 2);

  while(not table.empty())
  {
    auto prime = table.front();
    out->push_back(prime);
    table.remove_if([&](uint64_t n){ return n % prime == 0;});
  }

  return out;
}

}

#endif