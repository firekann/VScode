#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

string sum(string x, string y, bool ckx, bool cky);
string multi(string x, string y, bool ckx, bool cky);

int main() {
	fastio
	string a, b;
	string result;
	cin >> a;
	cin >> b;
	bool cka = true, ckb = true;
	if (a[0] == '-') {
		a.erase(a.begin() + 0);
		cka = false;
	}
	if (b[0] == '-') {
		b.erase(b.begin() + 0);
		ckb = false;
	}
	result = multi(a, b, cka, ckb);
	cout << result << endl;
	return 0;
}

string sum(string x, string y, bool ckx, bool cky)			//더하기 함수
{
	int num;
	int carry = 0;
	string result;
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	while (x.length() < y.length()) {
		x += '0';
	}
	while (x.length() > y.length()) {
		y += '0';
	}
	for (int i = 0; i < x.length(); ++i) {
		num = (x[i] - '0' + y[i] - '0' + carry) % 10;
		result += to_string(num);
		carry = (x[i] - '0' + y[i] - '0' + carry) / 10;
	}
	if (carry != 0) {
		result += to_string(carry);
	}
	if (!ckx && !cky || ckx == false) {
		result += '-';
	}
	reverse(result.begin(), result.end());
	return result;
}

string multi(string x, string y, bool ckx, bool cky)		//곱하기 함수
{
	string result;
	if (x == "0" || y == "0") {
		return "0";
	}
	string tmpx = x;
	reverse(tmpx.begin(), tmpx.end());
	for (int i = 0; i < x.length(); i++) {
		int cnt = tmpx[i] - '0';
		for (int i = 0; i < cnt; i++) {
			result = sum(result, y, true, true);
		}
		y += "0";
	}
	reverse(result.begin(), result.end());
	if (ckx != cky) {
		result += '-';
	}
	reverse(result.begin(), result.end());
	return result;
}