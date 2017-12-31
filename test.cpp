        
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// To execute C++, please define "int main()"
int main() {
  
  string input{};
  vector<string> tokens{};
  map<const string, int> tokenMap{};
  vector<string> insertionOrder{}; //Just to keep track of order
  
  cout<< "Enter the string:";
  getline(cin, input);
  istringstream iss(input);
  
  if(input.size() > 0)
  {
    //Parse words of string in vector
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(tokens));
    
    if(tokens.size() > 0)
    {
      for(const auto& token : tokens)
      {
        if(tokenMap[token] < 1) //We yet have not encountered this key
           insertionOrder.push_back(token);
        tokenMap[token]++;
      }
    }
  }
  
  for(const auto& orderToken : insertionOrder)
  {
    for(const auto& token : tokenMap)
    {
      if(token.first == orderToken)
         cout << token.first << " : " << token.second << "\n";
    }
  }
  return 0;
}
 

/*

"these are good apples and these are bad apples"

Print word occurences in a string in the order the words appear

So the output should be:

these: 2
are: 2
good: 1
apples: 2
and: 1
bad: 1

*/
