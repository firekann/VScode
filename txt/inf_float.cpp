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
    int output_precision_length;

public:
    inf_float();
    inf_float(int);
    inf_float(long long);
    inf_float(float);
    inf_float(double);
    inf_float(long double);
    inf_float(const char*);
    inf_float(std::string);
    inf_float(const inf_float&);
    ~inf_float();
    friend void ltrim(std::string&);
    friend void rtrim(std::string&);
    friend void trim(std::string&);
    string getstr();
    void set_output_precision_length(int n);
    inf_float& operator=(const inf_float&);
    friend void FFT(std::vector<std::complex<double>>&, bool);
    friend bool operator==(const inf_float&, const inf_float&);
    friend bool operator!=(const inf_float&, const inf_float&);
    friend bool operator>(const inf_float&, const inf_float&);
    friend bool operator<(const inf_float&, const inf_float&);
    friend bool operator>=(const inf_float&, const inf_float&);
    friend bool operator<=(const inf_float&, const inf_float&);
    friend inf_float operator+(const inf_float&, const inf_float&);
    friend inf_float operator-(const inf_float&, const inf_float&);
    friend inf_float operator*(const inf_float&, const inf_float&);
    friend inf_float operator+(const inf_float&);
    friend inf_float operator-(const inf_float&);
    friend inf_float& operator++(inf_float&);
    friend inf_float operator++(inf_float&, int);
    friend inf_float& operator--(inf_float&);
    friend inf_float operator--(inf_float&, int);
    friend inf_float& operator+=(inf_float&, const inf_float&);
    friend inf_float& operator-=(inf_float&, const inf_float&);
    friend inf_float& operator*=(inf_float&, const inf_float&);
    friend std::ostream& operator<<(std::ostream&, const inf_float&);
    friend std::istream& operator>>(std::istream&, inf_float&);
};
inf_float abs(const inf_float& n) { return +n; }
std::string to_string(const inf_float& n)
{
    std::stringstream str_stream;
    str_stream << n;
    return str_stream.str();
}

int main()
{
    fastio;
    inf_float a, b;
    cin >> a >> b;
    inf_float c = a + b;
    cout << c << "\n";
    cout << c.getstr() << "\n";
}

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
string inf_float::getstr()
{
    return this->digits;
}
void inf_float::set_output_precision_length(int n)
{
    this->output_precision_length = n;
}
inf_float::inf_float()
{
    this->digits = "0";
    this->length = 1;
    this->precision_position = 0;
    this->thesign = true;
    this->output_precision_length = -1;
}
inf_float::inf_float(int n) { new (this) inf_float(to_string(n)); }
inf_float::inf_float(long long n) { new (this) inf_float(to_string(n)); }
inf_float::inf_float(float n) { new (this) inf_float(to_string(n)); }
inf_float::inf_float(double n) { new (this) inf_float(to_string(n)); }
inf_float::inf_float(long double n) { new (this) inf_float(to_string(n)); }
inf_float::inf_float(const char* str) { new (this) inf_float(std::string(str)); }
inf_float::inf_float(std::string str)
{
    this->output_precision_length = -1;
    if (str[0] == '-') {
        this->thesign = false;
        str.erase(str.begin());
    } else {
        this->thesign = true;
    }
    ltrim(str);
    std::string buf = "";
    unsigned int str_len = (unsigned int)str.length();
    int pos = -1;
    for (int i = str_len - 1; i >= 0; i--) {
        if (str[i] != '.')
            buf += str[i];
        else
            pos = i;
    }
    unsigned int buf_len = (unsigned int)buf.length();
    if (str_len == 0 || buf == "0") {
        new (this) inf_float();
    } else {
        if (pos == -1) {
            this->digits = buf;
            this->length = buf_len;
            this->precision_position = 0;
        } else {
            trim(buf);
            this->digits = buf;
            this->length = (unsigned int)buf.length();
            this->precision_position = buf_len - pos;
        }
    }
}
inf_float::inf_float(const inf_float& a)
{
    this->digits = a.digits;
    this->length = a.length;
    this->thesign = a.thesign;
    this->precision_position = a.precision_position;
    this->output_precision_length = -1;
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
inf_float& inf_float::operator=(const inf_float& a)
{
    if (this->digits.length()) {
        this->digits = "";
    }
    this->digits = a.digits;
    this->length = a.length;
    this->thesign = a.thesign;
    this->precision_position = a.precision_position;
    this->output_precision_length = -1;
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
inf_float operator+(const inf_float& a, const inf_float& b)
{
    if (a.thesign != b.thesign && a.digits == b.digits && a.precision_position == b.precision_position) {
        return 0;
    }
    if (a.thesign == true && b.thesign == true) {
        unsigned int max_precision_position = max(a.precision_position, b.precision_position);
        std::string sa = a.digits;
        std::string sb = b.digits;
        if (a.precision_position < b.precision_position) {
            for (int i = 0; i < b.precision_position - a.precision_position; i++) {
                sa = '0' + sa;
            }
        } else {
            for (int i = 0; i < a.precision_position - b.precision_position; i++) {
                sb = '0' + sb;
            }
        }
        int a_len = (int)sa.length();
        int b_len = (int)sb.length();
        while ((int)sb.length() < a_len) {
            sb += '0';
        }
        while ((int)sa.length() < b_len) {
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
        inf_float res;
        unsigned int len = (unsigned int)result.length();
        if (max_precision_position == 0) {
            res.digits = result;
            res.length = len;
        } else if (len > max_precision_position) {
            int pos = -1;
            for (int i = 0; i < len; i++) {
                if (i == max_precision_position) {
                    break;
                }
                if (result[i] != '0') {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                pos = max_precision_position;
            }
            result = result.substr(pos, string::npos);
            res.length = (unsigned int)result.length();
            res.precision_position = max_precision_position - (len - res.length);
            res.digits = result;
        } else {
            ltrim(result);
            res.length = (unsigned int)result.length();
            res.precision_position = max_precision_position - (len - res.length);
            res.digits = result;
        }
        return res;
    } else if (a.thesign == false && b.thesign == false) {
        return -(abs(a) + abs(b));
    } else {
        inf_float c(b);
        c.thesign = a.thesign;
        return a - c;
    }
}
inf_float operator-(const inf_float& a, const inf_float& b)
{
    /*
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
        inf_float aa(a);
        inf_float bb(b);
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
        inf_float result(inf_float(aa.digits) + inf_float(bb.digits));
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
    */
}
inf_float operator*(const inf_float& a, const inf_float& b)
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
        std::string result = "";
        if (i < 0) {
            return 0;
        } else {
            for (; i >= 0; i--) {
                result += (r[i] + '0');
            }
        }
        ltrim(result);
        int len = (int)result.length();
        rtrim(result);
        inf_float res(result);
        res.length = (unsigned int)result.length();
        res.precision_position = a.precision_position + b.precision_position - (len - (int)res.length);
        if (res.length == 0) {
            return 0;
        } else {
            return res;
        }
    }
}
inf_float operator+(const inf_float& a)
{
    inf_float tmp(a);
    tmp.thesign = true;
    return tmp;
}
inf_float operator-(const inf_float& a)
{
    if (a == 0) {
        return 0;
    }
    inf_float tmp(a);
    tmp.thesign = a.thesign ? false : true;
    return tmp;
}
inf_float& operator++(inf_float& a) { return a += 1; }
inf_float operator++(inf_float& a, int)
{
    inf_float tmp(a);
    a += 1;
    return tmp;
}
inf_float& operator--(inf_float& a) { return a -= 1; }
inf_float operator--(inf_float& a, int)
{
    inf_float tmp(a);
    a -= 1;
    return tmp;
}
inf_float& operator+=(inf_float& a, const inf_float& b)
{
    a = a + b;
    return a;
}
inf_float& operator-=(inf_float& a, const inf_float& b)
{
    a = a - b;
    return a;
}
inf_float& operator*=(inf_float& a, const inf_float& b)
{
    a = a * b;
    return a;
}
std::ostream& operator<<(std::ostream& out, const inf_float& a)
{
    if (a.thesign == false) {
        out << '-';
    }
    if (a.output_precision_length == 0) {
        if (a.length > a.precision_position) {
            for (int i = a.length - 1; i >= (int)a.length - ((int)a.length - (int)a.precision_position); i--) {
                out << a.digits[i];
            }
        } else {
            out << "0";
        }
    } else {
        bool is_precision = false;
        int cnt = 0;
        if (a.length <= a.precision_position) {
            is_precision = true;
            out << "0.";
            for (int i = 0; i < a.precision_position - a.length; i++) {
                out << '0';
                cnt++;
            }
        }
        for (int i = a.length - 1; i >= 0; i--) {
            if (cnt == a.output_precision_length) {
                break;
            }
            if (is_precision) {
                cnt++;
            }
            out << a.digits[i];
            if (i == a.precision_position) {
                is_precision = true;
                out << ".";
                if (i == 0) {
                    out << "0";
                }
            }
        }
        if (a.output_precision_length != -1 && a.precision_position < a.output_precision_length) {
            for (int i = 0; i < a.output_precision_length - (a.precision_position == 0 ? 1 : a.precision_position); i++) {
                out << '0';
            }
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