class Solution {
public:
    vector<string> arr1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten","Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> arr2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> arr3 = {"", "Thousand", "Million", "Billion"};
    string number_word(int n) {
        string result;
        if (n >= 100) {
            result += arr1[n / 100] + " Hundred ";
            n %= 100;
        }
        if (n >= 20) {
            result += arr2[n / 10] + " ";
            n %= 10;
        }
        if (n > 0) {
            result += arr1[n] + " ";
        }
        return result;
    }
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res;
        int i = 0;  
        while (num > 0) {
            if (num % 1000 != 0) {
                res = number_word(num % 1000) + arr3[i] + " " + res;
            }
            num /= 1000;
            i++;
        }
        while (res.back() == ' ') {
            res.pop_back();
        }
        return res;
    }
};