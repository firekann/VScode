#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
#define X first
#define Y second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mid ((l + r) >> 1)
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"
//ifstream input(INPUT_FILE);
//ofstream output(OUTPUT_FILE);

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

std::string ltrim(std::string s);
std::string rtrim(std::string s);
std::string trim(std::string s);
std::string tolowwercase(std::string s);
std::string touppercase(std::string s);
std::string removechar(std::string s, std::string r);
std::string replace(std::string s, std::string r, char k);
std::vector<std::string> split(std::string s, char k);
std::vector<std::string> split(std::string s, std::string k);

int main()
{
    fastio;
    cout << "test";
}

std::string ltrim(std::string s)
{
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) { return !isspace(ch); }));
    return s;
}
std::string rtrim(std::string s)
{
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch) { return !isspace(ch); }).base(), s.end());
    return s;
}
std::string trim(std::string s)
{
    s = rtrim(s);
    s = ltrim(s);
    return s;
}
std::string tolowwercase(std::string s)
{
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });
    return s;
}
std::string touppercase(std::string s)
{
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return toupper(c); });
    return s;
}
std::string removechar(std::string s, std::string r)
{
    for (auto i : r) {
        s.erase(remove(s.begin(), s.end(), i), s.end());
    }
    return s;
}
std::string replace(std::string s, std::string r, char k)
{
    for (auto& i : s) {
        for (auto j : r) {
            i = i == j ? k : i;
        }
    }
    return s;
}
std::vector<std::string> split(std::string s, char k)
{
    std::vector<std::string> rec;
    std::string ts = "";
    for (auto i : s) {
        if (i == k) {
            if ((int)ts.size()) {
                rec.push_back(ts);
            }
            ts = "";
        } else {
            ts += i;
        }
    }
    if ((int)ts.size()) {
        rec.push_back(ts);
    }
    return rec;
}
std::vector<std::string> split(std::string s, std::string k)
{
    std::vector<std::string> rec;
    std::string ts = "";
    for (auto i : s) {
        bool flag = false;
        for (auto j : k) {
            if (j == i) {
                flag = true;
                break;
            }
        }
        if (flag) {
            if ((int)ts.size()) {
                rec.push_back(ts);
            }
            ts = "";
        } else {
            ts += i;
        }
    }
    if ((int)ts.size()) {
        rec.push_back(ts);
    }
    return rec;
}