#ifndef REPARTITION_HPP
#define REPARTITION_HPP

#include <cstdint>
#include <vector>
#include <memory>
#include <unordered_map>
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
    virtual ~Repartition() {};

    void compute();

  private:
    const std::vector<uint8_t> m_ending = {1, 3, 7, 9};

    std::unordered_map<uint8_t, CountTotal> m_results;
    PrimeSP m_primes;
};

}

#endif