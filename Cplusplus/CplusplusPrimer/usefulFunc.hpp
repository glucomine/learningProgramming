#include <iostream>
#include <string>

// template func for printing stl containers
template <typename> Container> inline void print (const Container &container)
{
  for (auto i : container)
  {
    std::cout << i << " ";
  }
  std::cout << "\n";
}
