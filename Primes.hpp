#ifndef PRIMES_HPP
#define PRIMES_HPP

#include <memory>
#include <cstdint>
#include <vector>
#include <list>
#include <numeric>
#include <thread>

#include <iostream>

namespace Primes
{

using PrimeSP = std::shared_ptr<std::vector<uint64_t>>;

enum class ExecPolicy
{
  Sequenced,
  MultiTasked,
  Threaded
};

class Primes
{
  public:
    explicit Primes(uint64_t upTo, ExecPolicy ep = ExecPolicy::MultiTasked);

    void generate();

    ExecPolicy policy() const;
    void setPolicy(ExecPolicy ep);

    PrimeSP primes() const;

  private:
    uint64_t m_upTo;
    ExecPolicy m_policy;
    PrimeSP m_primes;

    void tasked();
    void threaded();
    void sequenced();

    uint8_t cpuCount() const;
};

}

#endif