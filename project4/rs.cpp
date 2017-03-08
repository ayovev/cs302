#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void radixSortInt( vector<int>& nums );

int main()
{
   vector<int> vec1 = {10, 24, 22, 62, 1, 50, 100, 75, 2, 3};

   radixSortInt(vec1);

   for( unsigned int i = 0; i < vec1.size(); i++ )
   {
      cout << vec1[ i ] << ' ';
   }

   return 0;
}

void radixSortInt(vector<int>& nums)
{
  for (int i = 0; i < 32; ++i)
  {
    vector<int> zeroBucket;
    vector<int> oneBucket;

    for ( unsigned int j = 0; j < nums.size(); ++j)
    {
      int bit = (nums[j] >> i) & 1;
      if (bit)
      {
        oneBucket.push_back(nums[j]);
      }
      else
      {
        zeroBucket.push_back(nums[j]);
      }
    }

    nums.clear();

    if (i == 31)
    {
      nums.insert(nums.end(), oneBucket.begin(), oneBucket.end());
      nums.insert(nums.end(), zeroBucket.begin(), zeroBucket.end());
    }
    else
    {
      nums.insert(nums.end(), zeroBucket.begin(), zeroBucket.end());
      nums.insert(nums.end(), oneBucket.begin(), oneBucket.end());
    }
  }
}