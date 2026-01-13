#include <iostream>
#include <vector>
using namespace std;

int operations = 0;
int currDeapth = 0;
int maxDeapth = 0;

void complexRec(int n) {

    currDeapth++;
    maxDeapth = std::max(currDeapth , maxDeapth);

   if (n <= 2) {
        currDeapth--;
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           operations++;
       }
       p >>= 1;
       operations++;
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
       operations++;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
   } else {
       reverse(small.begin(), small.end());
   }

   operations++;

   complexRec(n / 2);
   complexRec(n / 2);
   complexRec(n / 2);
}

int main(){
    /*Time complexity -- T(n) = 3T(n/2) + nlogn;
    This should print out the deapth and the maxOperations
    counted reverse as an single operation else we can so operation += n where n 
    is the numeber of elements or the number we had*/

    int num = 8;
    complexRec(num);
    cout<<operations<<endl;
    cout<<maxDeapth<<endl;
}
