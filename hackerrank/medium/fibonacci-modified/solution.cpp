#include <bits/stdc++.h>

  using namespace std;

  string ltrim(const string &);
  string rtrim(const string &);
  vector<string> split(const string &);

  class BigInteger {
  private:
      static const long long BASE = 1000000000;
      vector<long long> digits;

  public:
      BigInteger(long long value = 0) {
          while (value > 0) {
              digits.push_back(value % BASE);
              value /= BASE;
          }
      }

      BigInteger operator+(const BigInteger &other) const {
          BigInteger result;
          long long carry = 0;
          int n = max(digits.size(), other.digits.size());

          for (int i = 0; i < n || carry; i++) {
              long long sum = carry;

              if (i < digits.size())
                  sum += digits[i];

              if (i < other.digits.size())
                  sum += other.digits[i];

              result.digits.push_back(sum % BASE);
              carry = sum / BASE;
          }

          return result;
      }

      BigInteger operator*(const BigInteger &other) const {
          BigInteger result;
          result.digits.assign(digits.size() + other.digits.size(), 0);

          for (int i = 0; i < digits.size(); i++) {
              long long carry = 0;

              for (int j = 0; j < other.digits.size() || carry; j++) {
                  long long current = result.digits[i + j] + carry;

                  if (j < other.digits.size())
                      current += digits[i] * other.digits[j];

                  result.digits[i + j] = current % BASE;
                  carry = current / BASE;
              }
          }

          while (!result.digits.empty() && result.digits.back() == 0)
              result.digits.pop_back();

          return result;
      }

      string toString() const {
          if (digits.empty())
              return "0";

          string result = to_string(digits.back());

          for (int i = digits.size() - 2; i >= 0; i--) {
              string part = to_string(digits[i]);
              result += string(9 - part.length(), '0') + part;
          }

          return result;
      }
  };

  /*
   * Complete the 'fibonacciModified' function below.
   *
   * The function is expected to return an INTEGER.
   * The function accepts following parameters:
   *  1. INTEGER t1
   *  2. INTEGER t2
   *  3. INTEGER n
   */

  string fibonacciModified(int t1, int t2, int n) {
      BigInteger a(t1);
      BigInteger b(t2);

      for (int i = 3; i <= n; i++) {
          BigInteger c = a + b * b;
          a = b;
          b = c;
      }

      return b.toString();
  }

  int main()
  {
      ofstream fout(getenv("OUTPUT_PATH"));

      string first_multiple_input_temp;
      getline(cin, first_multiple_input_temp);

      vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

      int t1 = stoi(first_multiple_input[0]);

      int t2 = stoi(first_multiple_input[1]);

      int n = stoi(first_multiple_input[2]);

      string result = fibonacciModified(t1, t2, n);

      fout << result << "\n";

      fout.close();

      return 0;
  }

  string ltrim(const string &str) {
      string s(str);

      s.erase(
          s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
      );

      return s;
  }

  string rtrim(const string &str) {
      string s(str);

      s.erase(
          find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
          s.end()
      );

      return s;
  }

  vector<string> split(const string &str) {
      vector<string> tokens;

      string::size_type start = 0;
      string::size_type end = 0;

      while ((end = str.find(" ", start)) != string::npos) {
          tokens.push_back(str.substr(start, end - start));

          start = end + 1;
      }

      tokens.push_back(str.substr(start));

      return tokens;
  }
