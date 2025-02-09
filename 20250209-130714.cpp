#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    const int MAX_N = 100000; // Safe limit
    vector<int> sum_digits(MAX_N + 1, 0);
    vector<int> div_by_3(MAX_N + 1, 0);

    // Precompute sum of digits and count divisibility by 3
    int digit_sum = 0;
    for (int i = 1; i <= MAX_N; i++) {
        int num = i, sum = 0;
        
        // Compute digit sum of 'i'
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        digit_sum += sum;
        sum_digits[i] = digit_sum;
        
        // Check divisibility by 3
        div_by_3[i] = div_by_3[i - 1] + (digit_sum % 3 == 0 ? 1 : 0);
    }

    // Process test cases
    for (int t = 1; t <= T; t++) {
        int A, B;
        cin >> A >> B;

        // Get count of numbers divisible by 3 in range [A, B]
        int count = div_by_3[B] - div_by_3[A - 1];

        cout << "Case " << t << ": " << count << endl;
    }

    return 0;
}
