#include <iostream>
#include <memory>
#include <cstdint>
#include <cmath>

#include "Tools.hpp"
#include "Repartition.hpp"

using namespace std;

static constexpr uint64_t PrimesUpTo = pow(10,6);

int main(int argc, char** argv)
{
  cout << ":: Prime distribution rule tester" << endl;

  auto primes = getPrimes(PrimesUpTo, Primes::ExecPolicy::MultiTasked);
  showDetails(primes);

  for(auto p: vector<uint8_t>{1, 3, 7, 9}) {
    Primes::Repartition repartition(primes, p);
    repartition.compute();
    Primes::displayResults(repartition);
  }

  return 0;
};