#ifndef REPARTITION_HPP
#define REPARTITION_HPP

#include <cstdint>
#include <vector>
#include <memory>
#include <map>
#include <tuple>

#include "Primes.hpp"

namespace Primes
{

using CountTotal = std::tuple<uint16_t, uint16_t>;
using Results = std::map<uint8_t, CountTotal>;

// forward declaration
class Repartition;

void displayResults(const Repartition& r);

class Repartition
{
  public:
    Repartition() = delete;
    Repartition(PrimeSP primes, uint8_t digit);

    void compute() noexcept;

    const Results& results() const
    { return m_results;}

    uint8_t digit() const
    { return m_digit;}

  private:
    Results m_results{
      {1, CountTotal{0,0}},
      {3, CountTotal{0,0}},
      {7, CountTotal{0,0}},
      {9, CountTotal{0,0}}
    };

    PrimeSP m_primes;
    uint8_t m_digit;
};

}

#endif