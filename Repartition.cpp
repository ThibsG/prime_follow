#include "Repartition.hpp"

#include <iostream>


namespace Primes
{

Repartition::Repartition(PrimeSP primeSP, uint8_t digit) :
  m_primes(primeSP),
  m_digit(digit)
{
}

const Results& Repartition::results() const
{
  return m_results;
}

uint8_t Repartition::digit() const
{
  return m_digit;
}

void Repartition::compute() noexcept
{
  uint8_t lastDigit = 0;

  for(auto&& prime: *m_primes)
  {
    const auto digit = prime % 10;

    if(lastDigit == m_digit && prime > 10)
    {
      for(auto&& it: m_results) {
        std::get<1>(it.second) += 1;
        std::get<0>(it.second) += (it.first == digit) ? 1 : 0;
      }
    }

    lastDigit = digit;
  }
}

void displayResults(const Repartition& r)
{
  uint16_t followed, total;

  std::cout << "\tComputing global repartition for prime ending by " << unsigned(r.digit()) << std::endl;

  for(auto&& it: r.results()) {
    std::tie(followed, total) = it.second;
    const auto perc = float(followed*100) / total;

    std::cout << "\t\t(" << unsigned(r.digit()) << "," << unsigned(it.first) << "): ";
    std::cout << perc << "% (" << followed << "/" << total << ")" << std::endl;
  }
}

}