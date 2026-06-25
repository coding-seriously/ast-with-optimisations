// // // input.cpp
// // // int main() {
// // //     int a = 5;
// // //     int b = 10;
// // //     for(int i = 0; i < 3; ++i) {
// // //         a += i;
// // //     }
// // //     if (a < b) {
// // //         return a + b;
// // //     }
// // //     return a-b;
// // // }

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pp pop_back
#define vld vector<long double>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long int, long long int>>
#define fi first
#define se second
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define trav(a, x) for (auto &a : x)
#define endl "\n"

int mod = 1e9 + 7;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
// // using pq2 = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
// // using pq3 = priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>;
// // void yes() { cout << "YES" << endl; }
// // void no() { cout << "NO" << endl; }
// // //------------------------------ DSU ---------------------------------------
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
bool isset(int l, int i)
{
    if (l & (1 << i))
        return true;
    else
        return false;
}
int sums(vector<int> &a)
{
    int sum = 0;
    for (auto it : a)
        sum += it;
    return sum;
}
// vector<bool> sieve(int n)
// {
//     vector<bool> is_prime(n + 1, true);
//     is_prime[0] = is_prime[1] = false;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (is_prime[i])
//         {
//             for (int j = i * i; j <= n; j += i)
//                 is_prime[j] = false;
//         }
//     }
//     return is_prime;
// }
// vector<bool> is_prime = sieve(limit);
//  ---------------------- SOLUTION ------------------------

void solution()
{

    int s, k, m;
    cin >> s >> k >> m;

    int numberflip = m / k;
    int timeremain = m % k;

    int l = s, r = 0;
    bool inv = (numberflip & 1);
    int ftime = 0;

    if (inv)
    {
        l = (s - k > 0 ? s - k : 0);
        r = s - l;
    }

    if (inv)
    {
        ftime = (r - timeremain > 0 ? r - timeremain : 0);
    }
    else
    {
        ftime = (l - timeremain > 0 ? l - timeremain : 0);
    }

    cout << ftime << endl;

    // r = (s-timeremain > 0 ? s-timeremain : 0);
    // l = (s-r > 0? s-r : 0);

    //  cout << l  << "  " << r << endl;
    // if(inv){
    //     cout << r << endl;
    // }else{
    //     cout << l <<endl;
    // }
    // if (m < k)
    // {
    //     int t = (s - m) > 0 ? (s - m) : 0;
    //     cout << t << endl;
    //     return;
    // }

    // while (m >= k)
    // {
    //     m -= k;
    //     if (inv)
    //     {
    //         if (r - k > 0)
    //         {
    //             l = k;
    //             r -= k;
    //         }
    //         else
    //         {
    //             l = r;
    //             r = 0;
    //         }
    //     }
    //     else
    //     {
    //         if (l - k > 0)
    //         {
    //             r = k;
    //             l -= k;
    //         }
    //         else
    //         {
    //             r = l;
    //             l = 0;
    //         }
    //     }
    //     inv = !inv;
    // }

    // // cout << m << endl;

    // int remain  ;

    // if(inv){
    //     remain = (m > r ? 0 : r-m);
    // }else{
    //     remain = (m > l ? 0 : l-m);
    // }

    // cout << remain << endl;

    // cout << l << r << ct;
    // if (m < 0)
    // {
    //     m = 0;
    // }
    // if (inv)
    // {
    //     cout << (r - m > 0 ? r - m : 0) << endl;
    // }
    // else
    // {
    //     cout << (l - m > 0 ? l - m : 0) << endl;
    // }
}

#include <stdio.h>
#include <string.h>

int rev(char string[], int len)
{

    int k, j;
    k = len;

    for (int i = 0; i < k; i++)
    {
        putchar(string[k - i - 1]);
        //  j = j + (str[k-1-i]-'0');
    }
    // printf("\n%d,%d\n",j,k);
    return len;
}

int main()
{
    char nm[100];
    char nw[100];
    int j = 0;
    printf("Enter the number: ");
    fgets(nm, 100, stdin);

    int l = strlen(nm);
    int k = l;
    for (int i = 0; i < l; i++)
    {
        // j = (nm[i]-'0');
        nw[i] = (j + (nm[k - 1 - i] - '0'));
        j++;
        k++;
        putchar(nw[i]);
    }
    // main2();
    return rev(nw, l);
}

void solution2()
{

    int s, k, m;
    cin >> s >> k >> m;

    int numberflip = m / k;
    int timeremain = m % k;

    int l = s, r = 0;
    bool inv = (numberflip & 1);
    int ftime = 0;

    if (inv)
    {
        l = (s - k > 0 ? s - k : 0);
        r = s - l;
    }

    if (inv)
    {
        ftime = (r - timeremain > 0 ? r - timeremain : 0);
    }
    else
    {
        ftime = (l - timeremain > 0 ? l - timeremain : 0);
    }

    cout << ftime << endl;
}

int32_t main2()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "error", stderr);
#endif

    int al;

    int t = 1;
    cin >> t;
    while (t--)
    {

        solution2();
    }

    int jkl return 0;
}
