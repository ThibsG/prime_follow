#include "Repartition.hpp"

#include <iostream>

namespace Primes
{

Repartition::Repartition(PrimeSP primeSP) :
  m_primes(primeSP)
{
}

void Repartition::compute()
{
  auto lastDigit = 0;
  for(auto prime : *m_primes)
  {
    const auto digit = prime % 10;

    if(lastDigit == 0) {
      std::cout << "Init lastDigit: " << digit << std::endl;
      lastDigit = digit;
    }

    for(auto end : m_ending)
    {
      if(digit == end)
        continue;

//       m_results[end] =
    }
  }
}

}