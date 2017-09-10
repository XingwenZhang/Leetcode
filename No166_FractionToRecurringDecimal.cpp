// 166. Fraction to Recurring Decimal

// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// For example,

// Given numerator = 1, denominator = 2, return "0.5".
// Given numerator = 2, denominator = 1, return "2".
// Given numerator = 2, denominator = 3, return "0.(6)".


#include<iostream>
#include<string>
#include<deque>
#include<vector>
#include<set>
#include<sstream>
#include<climits>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long n = numerator;
        long long d = denominator;
        if (n < 0 && d < 0) {
            n *= -1;
            d *= -1;
            cout << n << endl;
            cout << d << endl;
        }
        bool flag = true;
        if (n * d < 0) {
            if (n<0) {
                n *= -1;
            }
            else {
                d *= -1;
            }
            flag = false;
        }
        // 整除， 有限小数， 有限循环小数
        if (n % d == 0) {
            if (!flag) {
                return to_string(n*-1 / d);
            }
            return to_string(n / d);
        }
        // Judge if 有限小数
        long long gcd = n > d ? GCD(n, d) : GCD(d, n);
        n /= gcd;
        d /= gcd;

        if (!contain_exclude_2_and_5(d)) { // 有限小数
                                           // double r = double(n) / d;
                                           // ostringstream os;
                                           // os << r;
                                           // if (!flag) {
                                           //     return "-" + os.str();
                                           // }
                                           // return os.str();
            return non_loop_res(n, d, flag);
        }
        else { // 无限循环小数
            return find_loop_num(n, d, flag);
        }

    }
    long long GCD(long long a, long long b) { // a is bigger, b is smaller
        if (a%b == 0) {
            return b;
        }
        return GCD(b, a%b);
    }
    bool contain_exclude_2_and_5(long long a) {
        long long prev = INT_MAX;
        while (prev != a) {
            prev = a;
            if (!(a % 2)) {
                a /= 2;
            }
            if (!(a % 5)) {
                a /= 5;
            }
        }
        if (a == 1) {
            return false;
        }
        return true;
    }
    string non_loop_res(long long a, long long b, bool flag) {
        vector<long long> v;
        while (a%b) {
            v.push_back(a / b);
            a = (a%b) * 10;
        }
        v.push_back(a / b);
        cout << endl;
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << endl;
        string res;
        if (!flag) {
            res += "-";
        }
        res += to_string(v[0]);
        res += ".";
        for (int i = 1; i<v.size(); i++) {
            res += v[i] + '0';
        }
        return res;
    }
    string find_loop_num(long long a, long long b, bool flag) {
        vector<long long> v;
        set<long long> rmd;
        deque<long long> dq;
        while (rmd.insert(a%b).second) {
            dq.push_back(a%b);
            v.push_back(a / b);
            a = (a%b) * 10;
        }
        v.push_back(a / b);
        // v[0] 整数部分
        auto it = find(dq.begin(), dq.end(), a%b);
        long long dis = distance(dq.begin(), it) + 1;
        // v[dis] - v.end() //循环节

        string res;
        if (!flag) {
            res += "-";
        }
        res += to_string(v[0]);
        res += ".";
        for (long long i = 1; i<v.size(); i++) {
            if (i == dis)
                res += "(";
            res += v[i] + '0';
        }
        res += ")";
        return res;
    }
};

int main() {
    int a = 1;
    int b = 5;
    Solution s;
    cout << s.fractionToDecimal(a, b);
    return 0;
}