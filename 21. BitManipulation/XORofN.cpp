/*Naive Approach
// C++ program to find XOR of numbers
// from 1 to n.
#include <bits/stdc++.h>
using namespace std;

int computeXOR(int n)
{
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = res ^ i; 
    }
    return res;
}
int main()
{
    int n = 7;
    cout << computeXOR(n) << endl;
    return 0;
}*/

// Optimized Approach

#include<bits/stdc++.h>
using namespace std;

// Method to calculate xor
int computeXOR(int n)
{
  
  // If n is a multiple of 4
  if (n % 4 == 0)
    return n;

  // If n%4 gives remainder 1
  if (n % 4 == 1)
    return 1;

  // If n%4 gives remainder 2
  if (n % 4 == 2)
    return n + 1;

  // If n%4 gives remainder 3
  return 0;
}

// Driver method
int main()
{
  int n = 5;
  cout<<computeXOR(n);
}

