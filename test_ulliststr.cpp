#include <cassert>
#include <iostream>
#include <vector>
#include "ulliststr.h"

using std::cout;
using std::endl;

static void checkList(const ULListStr& xs, const std::vector<std::string>& expect) {
  assert(xs.size() == expect.size());
  for (size_t i = 0; i < expect.size(); ++i) {
    assert(xs.get(i) == expect[i]);
  }
}

int main() {
  ULListStr xs;

  assert(xs.empty());
  try { xs.front(); assert(false && "front() should throw on empty"); }
  catch (const std::out_of_range&) {}
  try { xs.back();  assert(false && "back() should throw on empty");  }
  catch (const std::out_of_range&) {}
  try { xs.get(0);  assert(false && "get(0) should throw on empty");  }
  catch (const std::invalid_argument&) {}

  xs.push_back("A");
  assert(!xs.empty());
  assert(xs.size() == 1);
  assert(xs.front() == "A" && xs.back() == "A");
  checkList(xs, {"A"});

  xs.back() = "B";
  checkList(xs, {"B"});

  xs.push_front("Z");                
  checkList(xs, {"Z", "B"});
  assert(xs.front() == "Z");
  assert(xs.back()  == "B");

  xs.set(1, "Bee");
  assert(xs.get(1) == "Bee");

  xs.pop_front();                    
  checkList(xs, {"Bee"});

  xs.pop_back();
  assert(xs.empty());

  const int N = 25; 
  for (int i = 0; i < N; ++i) xs.push_back(std::to_string(i));
  assert(xs.size() == static_cast<size_t>(N));
  assert(xs.front() == "0");
  assert(xs.back()  == std::to_string(N - 1));
  assert(xs.get(5) == "5");
  assert(xs.get(N - 1) == std::to_string(N - 1));

  for (int i = 0; i < 10; ++i) xs.pop_back();   
  assert(xs.back() == std::to_string(N - 11));
  assert(xs.size() == static_cast<size_t>(N - 10));

  for (int i = 0; i < 15; ++i) xs.push_front("F" + std::to_string(i));
  assert(xs.front() == "F14");
  assert(xs.size() == static_cast<size_t>(N - 10 + 15));

  try { xs.get(xs.size()); assert(false && "get(size) should throw"); }
  catch (const std::invalid_argument&) {}

  while (!xs.empty()) xs.pop_back();
  assert(xs.empty());

  cout << "All basic ULListStr tests passed!\n";
  return 0;
}