#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int work(string s, int k) {
    if (s.size() < k) {
        return 0;
    }

    int total = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            ++total;
        }
    }

    int maxtotal = total;

    for (int i = 0; i < s.size() - k ; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            total -= 1;
        }
        if (s[i + k] == 'a' || s[i + k ] == 'e' || s[i + k ] == 'i' || s[i + k ] == 'o' || s[i + k ] == 'u') {
            total += 1;
        }
        maxtotal = max(maxtotal, total);
    }

    return maxtotal;
}





void solve() {
    string s;
    int k;
    cin >> s >> k;

    int ans = 0;

    for(int i=0;i<=s.size()-k;i++){
        string substring = s.substr(i, k);
        int vowelCount = work(substring, k);
        ans = max(ans,vowelCount);
    }

    cout<<ans<<endl;

    
}


int main() {
    FAST_IO;
    int t=1;
    while (t--) {
      solve();
    }
    return 0;
}

/*
class Solution {
public:

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int total = 0, maxTotal = 0;

        // Count vowels in the first window of size k
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                total++;
            }
        }
        maxTotal = total;

        // Sliding window to count vowels
        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i])) {
                total++; // Add the new character if it's a vowel
            }
            if (isVowel(s[i - k])) {
                total--; // Remove the first character of the previous window if it's a vowel
            }
            maxTotal = max(maxTotal, total);
        }

        return maxTotal;
    }
};

*/