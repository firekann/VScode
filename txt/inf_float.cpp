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
//ifstream in(INPUT_FILE);
//ofstream out(OUTPUT_FILE);

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

class inf_float {
private:
    std::string digits;
    unsigned int length;
    unsigned int precision_position;
    bool thesign;
    void ltrim(std::string& s)
    {
        s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) { return (ch == '0' ? false : true); }));
    }
    void rtrim(std::string& s)
    {
        s.erase(find_if(s.rbegin(), s.rend(), [](int ch) { return (ch == '0' ? false : true); }).base(), s.end());
    }
    void trim(std::string& s)
    {
        rtrim(s);
        ltrim(s);
    }

public:
    inf_float();
    inf_float(float);
    inf_float(double);
    inf_float(long double);
    inf_float(const char*);
    inf_float(std::string);
    inf_float(const inf_float&);
    ~inf_float();
    string getstr();
    inf_float& operator=(const inf_float&);
    friend void FFT(std::vector<std::complex<double>>&, bool);
    friend std::pair<inf_float, inf_float> divmod(const inf_float&, const inf_float&);
    friend bool operator==(const inf_float&, const inf_float&);
    friend bool operator!=(const inf_float&, const inf_float&);
    friend bool operator>(const inf_float&, const inf_float&);
    friend bool operator<(const inf_float&, const inf_float&);
    friend bool operator>=(const inf_float&, const inf_float&);
    friend bool operator<=(const inf_float&, const inf_float&);
    friend inf_float operator+(const inf_float&, const inf_float&);
    friend inf_float operator-(const inf_float&, const inf_float&);
    friend inf_float operator*(const inf_float&, const inf_float&);
    friend inf_float operator/(const inf_float&, const inf_float&);
    friend inf_float operator%(const inf_float&, const inf_float&);
    friend inf_float operator+(const inf_float&);
    friend inf_float operator-(const inf_float&);
    friend inf_float& operator++(inf_float&);
    friend inf_float operator++(inf_float&, int);
    friend inf_float& operator--(inf_float&);
    friend inf_float operator--(inf_float&, int);
    friend inf_float operator>>(const inf_float&, const inf_float&);
    friend inf_float operator<<(const inf_float&, const inf_float&);
    friend inf_float& operator+=(inf_float&, const inf_float&);
    friend inf_float& operator-=(inf_float&, const inf_float&);
    friend inf_float& operator*=(inf_float&, const inf_float&);
    friend inf_float& operator/=(inf_float&, const inf_float&);
    friend inf_float& operator%=(inf_float&, const inf_float&);
    friend inf_float& operator>>=(inf_float&, const inf_float&);
    friend inf_float& operator<<=(inf_float&, const inf_float&);
    friend inf_float abs(const inf_float&);
    friend std::ostream& operator<<(std::ostream&, const inf_float&);
    friend std::istream& operator>>(std::istream&, inf_float&);
};

int main()
{
    fastio;
}

string inf_float::getstr()
{
    return this->digits;
}
inf_float::inf_float()
{
    this->digits = "0";
    this->length = 1;
    this->precision_position = 0;
    this->thesign = true;
}
inf_float::inf_float(float n) { new (this) inf_float((long double)n); }
inf_float::inf_float(double n) { new (this) inf_float((long double)n); }
inf_float::inf_float(long double n) { new (this) inf_float(to_string(n)); }
inf_float::inf_float(const char* str) { new (this) inf_float(std::string(str)); }
inf_float::inf_float(std::string str)
{
    if (str[0] == '-') {
        this->thesign = false;
        str.erase(str.begin());
    } else {
        this->thesign = true;
    }
    ltrim(str); // 왼쪽 부분을 trim해서 불필요한 0을 제거해줌
    if (str[0] == '.') { // .이 먼저 나오면 0을 더해줌
        str = "0" + str;
    }
    std::string buf = "";
    unsigned int string_len = (unsigned int)str.size(), pos = 0;
    for (int i = string_len - 1; i >= 0; i--) {
        if (str[i] != '.')
            buf += str[i];
        else
            pos = i;
    }
    if (string_len == 0) {
        new (this) inf_float();
    } else if (this->digits == "0" && this->length == 1) {
        this->thesign = true;
    } else {
        this->digits = buf;
        if (pos == 0) { // 소수점이 존재하지 않으면 digit len이 1 줄어들지 않고 precision_position이 0이 됨
            this->length = string_len;
            this->precision_position = 0;
        } else {
            this->length = string_len - 1;
            this->precision_position = string_len - pos - 1;
        }
    }
}
inf_float::inf_float(const inf_float& a)
{
    this->digits = a.digits;
    this->length = a.length;
    this->thesign = a.thesign;
    this->precision_position = a.precision_position;
}
inf_float::~inf_float() { }
void FFT(std::vector<std::complex<double>>& f, bool inv = false)
{
    int size = f.size();
    for (int i = 1, j = 0; i < size; i++) {
        int tmp = size / 2;
        while (!((j ^= tmp) & tmp)) {
            tmp /= 2;
        }
        if (i < j) {
            std::swap(f[i], f[j]);
        }
    }
    for (int i = 1; i < size; i *= 2) {
        double tmp = (inv ? acos(-1) / i : -acos(-1) / i);
        std::complex<double> w(cos(tmp), sin(tmp));
        for (int j = 0; j < size; j += i * 2) {
            std::complex<double> wp(1, 0);
            for (int k = 0; k < i; k++) {
                std::complex<double> x = f[j + k], y = f[i + j + k] * wp;
                f[j + k] = x + y;
                f[i + j + k] = x - y;
                wp *= w;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < size; i++) {
            f[i] /= size;
        }
    }
}
std::pair<inf_int, inf_int> divmod(const inf_int& a, const inf_int& b)
{
    if (b == 0)
        throw "div by zero";
    if (a == 0)
        return { 0, 0 };
    if (a == b)
        return { 1, 0 };
    if (abs(a) < abs(b))
        return { 0, inf_int(a) };
    inf_int quotient, remainder(abs(a));
    inf_int absb = abs(b);
    long long n = a.length - b.length;
    for (long long i = n; i >= 0; i--) {
        long long powv = pow(10, i);
        for (;;) {
            inf_int tmp = absb * powv;
            if (remainder >= tmp) {
                quotient += powv;
                remainder -= tmp;
            } else
                break;
        }
        if (remainder < absb)
            break;
    }
    if (!a.thesign && !b.thesign)
        return { quotient, -remainder };
    if (a.thesign && !b.thesign)
        return { -quotient, remainder };
    if (!a.thesign && b.thesign)
        return { -quotient, -remainder };
    return { quotient, remainder };
}
inf_float& inf_float::operator=(const inf_float& a)
{
    if (this->digits.length()) {
        this->digits = "";
    }
    this->digits = a.digits;
    this->length = a.length;
    this->thesign = a.thesign;
    this->precision_position = a.precision_position;
    return *this;
}
bool operator==(const inf_float& a, const inf_float& b)
{
    if (a.digits == b.digits && a.thesign == b.thesign && a.precision_position == b.precision_position) {
        return true;
    }
    return false;
}
bool operator!=(const inf_float& a, const inf_float& b) { return !(a == b); }
bool operator>(const inf_float& a, const inf_float& b)
{
    if (a == b) {
        return false;
    }
    bool abs = false;
    if (a.length - a.precision_position > b.length - b.precision_position) {
        abs = true;
    } else if (a.length - a.precision_position == b.length - a.precision_position) {
        int i = a.length;
        while (i--) {
            int tmp = a.digits[i] - b.digits[i];
            if (tmp == 0) {
                continue;
            } else if (tmp > 0) {
                abs = true;
                break;
            } else {
                abs = false;
                break;
            }
        }
    }
    return a.thesign ? abs : !abs;
}
bool operator<(const inf_float& a, const inf_float& b) { return ((a > b) || (a == b)) ? false : true; }
bool operator>=(const inf_float& a, const inf_float& b) { return (a > b) || (a == b); }
bool operator<=(const inf_float& a, const inf_float& b) { return (a < b) || (a == b); }
inf_int operator+(const inf_int& a, const inf_int& b)
{
    if (a.thesign != b.thesign && abs(a) == abs(b)) {
        return 0;
    }
    if (a.thesign == true && b.thesign == true) {
        std::string sa = a.digits;
        std::string sb = b.digits;
        while ((int)sb.length() < a.length) {
            sb += '0';
        }
        while ((int)sa.length() < b.length) {
            sa += '0';
        }
        std::string result = "";
        int carry = 0, num;
        for (int i = 0; i < (int)sa.length(); i++) {
            num = (sa[i] - '0' + sb[i] - '0' + carry);
            result += ((num % 10) + '0');
            carry = num / 10;
        }
        if (carry) {
            result += (carry + '0');
        }
        reverse(result.begin(), result.end());
        return inf_int(result);
    } else if (a.thesign == false && b.thesign == false) {
        return -(abs(a) + abs(b));
    } else {
        inf_int c = b;
        c.thesign = a.thesign;
        return a - c;
    }
}
inf_int operator-(const inf_int& a, const inf_int& b)
{
    if (a == b) {
        return 0;
    }
    if (a.thesign == true && b.thesign == false) {
        return a + abs(b);
    } else if (a.thesign == false && b.thesign == true) {
        return -(abs(a) + b);
    } else if (a.thesign == false && b.thesign == false) {
        return -(abs(a) - abs(b));
    } else if (a.thesign == true && b.thesign == true) {
        bool flag = false;
        inf_int aa(a);
        inf_int bb(b);
        if (aa < bb) {
            aa = b;
            bb = a;
            flag = true;
        }
        int len = abs((int)(aa.length - bb.length));
        for (int i = 0; i < len; i++) {
            bb.digits += '0';
        }
        for (auto& i : bb.digits) {
            i = '9' - i + '0';
        }
        bb.digits[0]++;
        reverse(aa.digits.begin(), aa.digits.end());
        reverse(bb.digits.begin(), bb.digits.end());
        inf_int result(inf_int(aa.digits) + inf_int(bb.digits));
        result.digits = result.digits.substr(0, result.length);
        reverse(result.digits.begin(), result.digits.end());
        result.digits.erase(result.digits.begin());
        for (int i = 0;;) {
            if (result.digits[i] == '0') {
                result.digits.erase(result.digits.begin());
            } else if (result.digits[i] != '0') {
                break;
            }
        }
        reverse(result.digits.begin(), result.digits.end());
        if (flag) {
            result.thesign = false;
        }
        result.length = (int)result.digits.length();
        result.digits.substr(0, result.length);
        return result;
    }
}
inf_int operator*(const inf_int& a, const inf_int& b)
{
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == 1 || a == -1) {
        return a.thesign ? b : -b;
    }
    if (b == 1 || b == -1) {
        return b.thesign ? a : -a;
    }
    if (a.thesign != b.thesign) {
        return -(abs(a) * abs(b));
    } else if (a.thesign == false && b.thesign == false) {
        return abs(a) * abs(b);
    } else {
        std::vector<std::complex<double>> A, B, C;
        for (auto i : a.digits) {
            A.push_back(std::complex<double>(i - '0', 0));
        }
        for (auto i : b.digits) {
            B.push_back(std::complex<double>(i - '0', 0));
        }
        int num = 1;
        int Asize = A.size();
        int Bsize = B.size();
        while (num < Asize + 1 || num < Bsize + 1) {
            num *= 2;
        }
        num *= 2;
        A.resize(num);
        B.resize(num);
        C.resize(num);
        FFT(A);
        FFT(B);
        for (int i = 0; i < num; i++) {
            C[i] = A[i] * B[i];
        }
        FFT(C, true);
        int carry = 0;
        std::vector<int> r;
        int Csize = C.size();
        for (int i = 0; i < Csize; i++) {
            int tmp = (int)round(C[i].real()) + carry;
            r.push_back(tmp % 10);
            carry = tmp / 10;
        }
        while (carry > 0) {
            r.push_back(carry % 10);
            carry /= 10;
        }
        int rsize = r.size();
        int i;
        for (i = rsize - 1; i >= 0 && r[i] == 0; i--) { }
        std::string ans = "";
        if (i < 0) {
            return 0;
        } else {
            for (; i >= 0; i--) {
                ans += (r[i] + '0');
            }
        }
        return inf_int(ans);
    }
}
inf_int operator/(const inf_int& a, const inf_int& b) { return divmod(a, b).first; }
inf_int operator%(const inf_int& a, const inf_int& b) { return divmod(a, b).second; }
inf_int operator+(const inf_int& a)
{
    inf_int tmp(a);
    tmp.thesign = true;
    return tmp;
}
inf_int operator-(const inf_int& a)
{
    if (a == 0) {
        return 0;
    }
    inf_int tmp(a);
    tmp.thesign = a.thesign ? false : true;
    return tmp;
}
inf_int& operator++(inf_int& a) { return a += 1; }
inf_int operator++(inf_int& a, int)
{
    inf_int tmp(a);
    a += 1;
    return tmp;
}
inf_int& operator--(inf_int& a) { return a -= 1; }
inf_int operator--(inf_int& a, int)
{
    inf_int tmp(a);
    a -= 1;
    return tmp;
}
inf_int operator>>(const inf_int& a, const inf_int& b)
{
    inf_int tmp(a);
    for (inf_int i = 0; i < b; i++) {
        tmp /= 2;
    }
    return tmp;
}
inf_int operator<<(const inf_int& a, const inf_int& b)
{
    inf_int tmp(a);
    for (inf_int i = 0; i < b; i++) {
        tmp *= 2;
    }
    return tmp;
}
inf_int& operator+=(inf_int& a, const inf_int& b)
{
    a = a + b;
    return a;
}
inf_int& operator-=(inf_int& a, const inf_int& b)
{
    a = a - b;
    return a;
}
inf_int& operator*=(inf_int& a, const inf_int& b)
{
    a = a * b;
    return a;
}
inf_int& operator/=(inf_int& a, const inf_int& b)
{
    a = a / b;
    return a;
}
inf_int& operator%=(inf_int& a, const inf_int& b)
{
    a = a % b;
    return a;
}
inf_int& operator>>=(inf_int& a, const inf_int& b)
{
    a = a >> b;
    return a;
}
inf_int& operator<<=(inf_int& a, const inf_int& b)
{
    a = a << b;
    return a;
}
inf_int abs(const inf_int& a) { return +a; }
std::ostream& operator<<(std::ostream& out, const inf_float& a)
{
    if (a.thesign == false) {
        out << '-';
    }
    for (int i = a.length - 1; i >= 0; i--) {
        if (i == a.precision_position) {
            out << ".";
            if (i == 0) {
                out << "0";
            }
        } else {
            out << a.digits[i];
        }
    }
    return out;
}
std::istream& operator>>(std::istream& in, inf_float& a)
{
    std::string s;
    in >> s;
    a = inf_float(s);
    return in;
}