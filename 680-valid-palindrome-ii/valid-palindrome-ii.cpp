class Solution {
public:
    // Function to check if a string is a palindrome
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    // Function to check if a string can be a palindrome by removing at most one character
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) {
                // Check the substrings by removing one character either from the left or the right
                string s1 = s.substr(left + 1, right - left);
                string s2 = s.substr(left, right - left);
                return isPalindrome(s1) || isPalindrome(s2);
            }
            left++;
            right--;
        }
        return true;  // If no mismatches, the string is already a palindrome
    }
};
