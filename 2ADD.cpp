#include <iostream>
#include <bitset>
using namespace std;

// 1) Convert using bitwise operations
string toBinaryBitwise(int n) {
    if (n == 0) return "0";

    string bin = "";
    while (n > 0) {
        bin = char('0' + (n & 1)) + bin;   // take last bit
        n >>= 1;                           // right shift
    }
    return bin;
}

// 2) Convert using division by 2
string toBinaryDivision(int n) {
    if (n == 0) return "0";

    string bin = "";
    while (n > 0) {
        int rem = n % 2;
        bin = char('0' + rem) + bin;
        n /= 2;
    }
    return bin;
}

// 3) Convert using built-in bitset
string toBinaryBitset(int n) {
    return bitset<32>(n).to_string();   // prints 32-bit binary
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "\nBinary (Bitwise method):     " << toBinaryBitwise(num) << endl;
    cout << "Binary (Division by 2):       " << toBinaryDivision(num) << endl;
    cout << "Binary (Using bitset<32>):    " << toBinaryBitset(num) << endl;

    return 0;
}
