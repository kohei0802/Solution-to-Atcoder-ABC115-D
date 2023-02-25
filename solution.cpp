#include <iostream>
#include <vector>

using namespace std;

// L[i] == length -> level i burger
vector<long long> L(51);
// S[i] == No. of patties -> level i burger
vector<long long> S(51);

long long countPatty(long long N, long long X);

int main()
{
    long long N, X;
    cin >> N >> X;
    for (int i = 0; i < N+1; i++)
    {
        if (i == 0)
        {
            L[0] = 1;
            S[0] = 1;
        }
        else {
            L[i] = 2 * L[i - 1] + 3;
            S[i] = 2 * S[i - 1] + 1;
        }
    }
    
    cout << countPatty(N, X) << endl;

    return 0;
}

long long countPatty(long long N, long long X)
{
    if (X==1){
        return 0;
    }
    
    else if (X<=L[N-1] + 1) {
        return countPatty(N-1, X-1);
    }
    
    else if (X == (L[N-1]+2)) {
        return S[N-1] + 1;
    } 
    
    else if (X <= 2*L[N-1]+2) {
        return countPatty(N-1, X-2-L[N-1]) + S[N-1] + 1;
    }
    
    else {
        return S[N];
    }
    
}
