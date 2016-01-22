There must have a loop in the calculation,check the fast and slow, when they're not equal.
when they are equal check the fast or slow is equal 1 or not.
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = squareDigits(slow);
            fast = squareDigits(squareDigits(fast));
        } while (slow != fast);
        return fast == 1;
    }
private:
    int squareDigits(int n) {
        int sq = 0;
        while (n) {
            sq += (n % 10) * (n % 10);
            n /= 10;
        }
        return sq;
    }
};
