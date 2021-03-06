//Leetcode...BEST TIME TO BUY AND SELL STOCK III

//Q. Now comes a bit hard q
//We can use atmost 2 transactions..1 in case answer is extreme elements
/*
So, how to solve this..
well just observe one stuff
if we are given an array ex: 1 2 3 4 5 8 3 6
what do i mean when i say exactly 2..
lets imagine the cases..
lets say for 4..we can buy one stock and sell it(2 3)
we get profit 1
we can take (3 6) after 4 as the 2nd one..making profit 3 + 1 =4
now,we can also take (4 5)
or we can take cases like a bit overlap..(3 4) then (4 5)
so these are the distinct ways of carrying the tests
for element 4(many more just examples)

So, now you must have observed...
i'need 2 things..
1. suppose 4..whats the maximum profit 4 can give me...
first calculate 4 - min(on left side of 4)=ans
then calculate max(max so far, ans)
store that in res1
now we start from the left..so res1[0]=0
now why start from left
because for ex 4..we need to find out the minimum price on which we should buy
it so that when we sell it on the day the price is 4..we are able to
get maximum profit

similarly, for res2 array..we go form right to left..(res2[n-1]=0
because diff of max(from last elements right)- last element is 0)
so that we can find for 4...what is the maximum profit we can get if we buy
it when price is 4...i.e(max value on right of 4 - 4)
and if it comes less than the curr max...store curr max instead..
means (max-4)is not giving us the maximum but (max- something on right of 4) does.

Now,add both res1[i] + res2[i] to get dp[i]
and the ans is maximum value in your dp array
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

int main() {

    cout << fixed;
    cout << setprecision(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int res1[n];
    res1[0] = 0;
    int min1 = arr[0], max1 = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] - min1 > max1) {
            max1 = arr[i] - min1;
        }
        if (arr[i] < min1) {
            min1 = arr[i];
        }
        res1[i] = max1;
    }
    for (auto x : res1)
        cout << x << " ";
    cout << '\n';

    int res2[n];
    res2[n - 1] = 0;
    int max2 = arr[n - 1], mxp2 = 0;//mxp2 means maximum profit
    for (int i = n - 2; i >= 0; i--) {
        if (max2 - arr[i] > mxp2) {//max2 means maximum element on right of i
            mxp2 = max2 - arr[i];
        }
        if (arr[i] > max2) {
            max2 = arr[i];
          //already expalined cannot write this line above
          //as i cannot take the same element though its the minimum
        }
        res2[i] = mxp2;
    }
    for (auto x : res2)
        cout << x << " ";
    cout << '\n';

    int dp[n], maxx = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = res1[i] + res2[i];
        if (dp[i] > maxx) {
            maxx = dp[i];
        }
    }
    for (auto x : dp)
        cout << x << " ";
    cout << '\n';

    cout << maxx << '\n';

    return 0;
}


//Time : O(n)...3 traversal needed
//Space: O(2*n)..2 arrays used
//can ignore the dp array

/*
O/P

0 0 2 2 2 3 3 4 ..res1 array
4 4 4 4 4 3 3 0 ..res2 array
4 4 6 6 6 6 6 4 ..dp array
6 ...final ans 

*/
