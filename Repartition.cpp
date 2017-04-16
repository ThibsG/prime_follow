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
  unsigned short lastDigit = 0;
  for(auto&& prime : *m_primes)
  {
    const auto digit = prime % 10;

    if(prime > 10)
    {
      auto& counter = m_results[digit];
      std::get<1>(counter) += 1;
      std::get<0>(counter) += (lastDigit == digit) ? 1 : 0;
    }

    lastDigit = digit;
  }
}

void Repartition::print_results()
{
  uint16_t followed, total;

  for(auto&& it: m_results) {
    std::tie(followed, total) = it.second;
    const auto perc = float(followed*100) / total;

    std::cout << "\t\t" << unsigned(it.first) << ": ";
    std::cout << followed << " / " << total;
    std::cout << " so " << perc << "%" << std::endl;
  }
}

}