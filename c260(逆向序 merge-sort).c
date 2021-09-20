/*
https://emiliatancoding.blogspot.com/2020/02/c260.html
逆向序對, merge sort, 排容原理(A&B = A + B - A|B)
*/

#include <stdio.h>// 	AC (24ms, 3.1MB)
#include <stdlib.h>
#define MAXINPUT 100001
#define MAXLLINF 9223372036854775807
#define MINLLINF -9223372036854775808

long long prefixl[MAXINPUT] = {0}, prefixr[MAXINPUT] = {0}, ans = 0, *temp;

void mergeSortRecusive(long long int *array, int start, int end, char index){
    if(start == end){
        if(array[start] != MAXLLINF && array[start] != MINLLINF){
            if(index)
                ans += (array[start] <= 0);
            else
                ans += (array[start] >= 0);
        }
        return;
    }
    int mid = (start + end) >> 1;
    int st1 = start, st2 = mid + 1, ti = start;
    mergeSortRecusive(array, start, mid, index);
    mergeSortRecusive(array, st2, end, index);
    while(st1 <= mid && st2 <= end){
        if(array[st1] < array[st2])
            temp[ti++] = array[st1++];
        else{
            temp[ti++] = array[st2++];
            ans += (mid - st1 + 1);
        }
    }
    while(st1 <= mid)
        temp[ti++] = array[st1++];
    while(st2 <= end)
        temp[ti++] = array[st2++];
    while(start <= end)
        array[start++] = temp[start];
}


void mergeSort(long long int *array, long long int len, char index){
    temp = malloc((len + 10) * sizeof(long long int));
    mergeSortRecusive(array, 0, len, index);
    free(temp);
}

void SWAP(long long int *a, long long int *b){
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArr(long long int *a, long long int *b){
    while(a < b)
        SWAP(a++, b--);
}

static inline void solve(){
    long long int n, left, right;
    scanf("%lld%lld%lld", &n, &left, &right);
    for(int i = 1; i <= n; i++){
        scanf("%lld", prefixl + i);
        prefixr[i] = prefixl[i] +  - right + prefixr[i - 1];
        prefixl[i] += prefixl[i - 1] - left;
    }
    *prefixl = MAXLLINF;
    *prefixr = MINLLINF;
    reverseArr(prefixl, prefixl + n);
    /*for(int i = 0; i <= n; i++)
        printf("%lld ", prefixl[i]);
    putchar('\n');
    putchar('\n');

    reverseArr(prefixl, prefixl + n);

    for(int i = 0; i <= n; i++)
        printf("%lld ", prefixl[i]);
    putchar('\n');
    putchar('\n');
    for(int i = 0; i <= n; i++)
        printf("%lld ", prefixr[i]);
    putchar('\n');
    putchar('\n');*/

    ans = - ((n * (n + 1)) >> 1);
    mergeSort(prefixl, n, 0);
    mergeSort(prefixr, n, 1);
    printf("%lld\n", ans);
}

int main(){
    solve();
    return 0;
}


/*#include <stdio.h>
#define MAXINPUT 100000

long long int prefixl[MAXINPUT], prefixr[MAXINPUT];

static inline void solve(){
    int n, left, right;
    long long int ans = 0, temp;
    scanf("%d%d%d", &n, &left, &right);
    for(int i = 1; i <= n; i++){
        scanf("%lld", prefixl + i);
        prefixr[i] = prefixl[i] - right + prefixr[i - 1];
        prefixl[i] += prefixl[i - 1] - left;
    }
    for(int len = 1; len <= n; len++){
        for(int i = 0; i <= n - len; i++){
            if(prefixl[i + len] - prefixl[i] >= 0 && prefixr[i + len] - prefixr[i] <= 0)
                ans++;
        }
    }
    printf("%lld", ans);
}

int main(){
    solve();
    return 0;
}*/


// cpp answer

/*/* c260             */
/* AC (21ms, 2.4MB) */
/*
#pragma warning( disable : 4996 )
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <tuple>
#define ios_jazz ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define FOR(i, l, r) for (int i = (l); i < (r); ++i)
#define FORR(i, r, l) for (int i =(r); i >= (l); --i)
#define P(STR) puts(#STR)

using namespace std;

constexpr int Dir4[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
constexpr int Dir8[8][2] = { {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1} };
constexpr double EPS = 1e-8;
const double PI = acos(-1);

using int16 = short;
using uint16 = unsigned short;
using uint = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;
using pii = pair<int, int>;

auto Equal = [](double a, double b) { return fabs(a - b) < EPS; };

#include <vector>

constexpr int MAXN = 1e5;
int n;
int64 a, b;
int64 arr[2][MAXN + 1]{};
int64 tmp[MAXN + 10];

enum { A, B };
int64 sort(int idx, int l = 0, int r = n)
{
    if (r == l)
    {
        if (idx == A && arr[idx][l] == INT64_MAX) return 0;
        else if (idx == B && arr[idx][l] == INT64_MIN) return 0;
        if (idx == A)
            return (arr[idx][l] >= 0);
        else
            return (arr[idx][r] <= 0);
    }

    int mid = (l + r) / 2;

    int64 Lval = sort(idx, l, mid);
    int64 Rval = sort(idx, mid + 1, r);
    int64 Nowval = 0;

    int64 lptr = l;
    int64 rptr = mid + 1LL;
    int64 N = 0;

    for (; lptr <= mid; ++lptr)
    {
        while (rptr <= r && arr[idx][lptr] >= arr[idx][rptr])
        {
            tmp[N++] = arr[idx][rptr++];
            Nowval += ((int64)mid - lptr + 1);
        }

        tmp[N++] = arr[idx][lptr];
    }

    while (lptr <= mid)
        tmp[N++] = arr[idx][lptr++];
    while (rptr <= r)
        tmp[N++] = arr[idx][rptr++];

    for (int i = 0; i < N; ++i)
        arr[idx][l + i] = tmp[i];

    return Nowval + Lval + Rval;
}

int main()
{
    scanf("%d %lld %lld", &n, &a, &b);

    FOR(i, 1, n + 1)
        scanf("%lld", &arr[0][i]);

    FOR(i, 1, n + 1)
    {
        arr[1][i] = arr[0][i] - b;
        arr[1][i] += arr[1][i - 1];
        arr[0][i] -= a;
        arr[0][i] += arr[0][i - 1];
    }


    arr[A][0] = INT64_MAX;
    arr[B][0] = INT64_MIN;

    FOR(i, 0, n + 1)
        printf("%lld ", arr[A][i]);
    printf("\n");

    reverse(arr[A], arr[A] + n + 1);

    FOR(i, 0, n + 1)
        printf("%lld ", arr[A][i]);
    printf("\n");

    FOR(i, 0, n + 1)
        printf("%lld ", arr[B][i]);
    printf("\n");

    printf("%lld\n", sort(A) + sort(B) - n * (n + 1LL) / 2);

    return 0;
}*/
