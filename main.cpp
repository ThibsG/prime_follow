#include <iostream>
#include <memory>
#include <cstdint>
#include <cmath>

#include "Primes.hpp"
#include "Repartition.hpp"

using namespace std;

static constexpr uint64_t PrimesUpTo = 25*pow(10,3); // 10,6

int main(int argc, char** argv)
{
  cout << "=== Prime distribution rule tester ===" << endl;

  cout << "Prime calculation from 0 to " << PrimesUpTo << "..." << endl;
  auto prime = Primes::primes(PrimesUpTo);
  cout << prime->size() << " prime numbers detected" << endl;

  cout << "Computing global repartition..." << endl;
  Primes::Repartition repartition(prime);

  cout << "=== End of tests ===" << endl;
  return 0;
};