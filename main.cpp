#include <iostream>
#include <memory>
#include <cstdint>
#include <cmath>

#include "Primes.hpp"
#include "Repartition.hpp"

using namespace std;

static constexpr uint64_t PrimesUpTo = 25*pow(10,4); // 10,6
static constexpr uint8_t  ShowLimit = 25;

int main(int argc, char** argv)
{
  cout << ":: Prime distribution rule tester" << endl;

  cout << "\tPrime calculation from 0 to " << PrimesUpTo << "..." << endl;

  auto primeGenerator = Primes::Primes(PrimesUpTo);
  primeGenerator.generate();

  const auto primes = primeGenerator.primes();
  cout << "\t" << primes->size() << " prime numbers detected" << endl;

  cout << "\tFirst primes: ";
  for(int i = 0 ; i < ShowLimit ; ++i) {
    cout << primes->at(i) << " ";
  }
  cout << endl;

  cout << "\tLast primes: ";
  for(auto i = primes->size()-ShowLimit ; i < primes->size() ; ++i) {
    cout << primes->at(i) << " ";
  }
  cout << endl;

  for(auto&& p: vector<uint8_t>{1, 3, 7, 9}) {
    Primes::Repartition repartition(primes, p);
    repartition.compute();

    Primes::displayResults(repartition);
  }

  cout << ":: End of tests" << endl;
  return 0;
};