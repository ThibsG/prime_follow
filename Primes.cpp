#include "Primes.hpp"

#include <algorithm>
#include <future>

namespace
{

std::vector<uint64_t> keepPrimes(std::vector<uint64_t> table)
{
  std::vector<uint64_t> primes;
  while(not table.empty())
  {
    auto prime = table.front();
    primes.emplace_back(prime);
    table.erase(
      std::remove_if(table.begin(), table.end(), [&](uint64_t n){ return n % prime == 0;}),
      table.end());
  }
  return std::move(primes);
}

}

namespace Primes
{

Primes::Primes(uint64_t upTo, ExecPolicy ep):
  m_upTo(upTo),
  m_policy(ep),
  m_primes(nullptr)
{
}

ExecPolicy Primes::policy() const
{
  return m_policy;
}

void Primes::setPolicy(ExecPolicy ep)
{
  m_policy = ep;
}

PrimeSP Primes::primes() const
{
  return m_primes;
}

void Primes::generate()
{
  if(m_policy == ExecPolicy::Sequenced)
    sequenced();
  else
    tasked();
}

void Primes::sequenced()
{
  std::vector<uint64_t> table(m_upTo - 2);
  std::iota(table.begin(), table.end(), 2);

  m_primes = PrimeSP(new std::vector<uint64_t>(keepPrimes(table)));
}

void Primes::tasked()
{
  auto data = setupData();

  std::vector<std::future<std::vector<uint64_t>>> futures;
  for(auto& chunk : data) {
    futures.push_back(
      std::async(std::launch::async, keepPrimes, chunk)
    );
  }

  std::vector<uint64_t> asyncPrimes;
  for(auto& result: futures) {
    auto&& future = result.get();
    asyncPrimes.insert(asyncPrimes.end(), future.begin(), future.end());
  }

  m_primes = PrimeSP(new std::vector<uint64_t>(keepPrimes(asyncPrimes)));
}

std::list<std::vector<uint64_t>> Primes::setupData() const
{
  auto start = std::chrono::high_resolution_clock::now();

  std::list<std::vector<uint64_t>> data;
  const auto cpus = cpuCount();
  const auto chunkSize = m_upTo / cpus;

  for(uint64_t i = 2 ; i <= m_upTo ; i += chunkSize)
  {
    std::vector<uint64_t> table(std::min(chunkSize, m_upTo-i));
    std::iota(table.begin(), table.end(), i);
    data.emplace_back(std::move(table));
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "Splitting data took "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
            << "ms" << std::endl;
  return data;
}

uint8_t Primes::cpuCount() const
{
  auto cpus = std::thread::hardware_concurrency();
  // Unable to detect -> set default only 1 CPU
  if(cpus <= 0)
    cpus = 1;
  std::cout << unsigned(cpus) << " CPUs detected" << std::endl;
  return cpus;
}

}