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

class Repartition
{
  public:
    Repartition() = delete;
    Repartition(PrimeSP primes);

    void compute();
    void print_results();

  private:
    std::map<uint8_t, CountTotal> m_results{
      {1, CountTotal{0,0}},
      {3, CountTotal{0,0}},
      {7, CountTotal{0,0}},
      {9, CountTotal{0,0}}
    };

    PrimeSP m_primes;
};

}

#endif