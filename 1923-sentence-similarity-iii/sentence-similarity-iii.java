class Solution {
    public boolean areSentencesSimilar(String s1, String s2) {
        String[] str1 = s1.split(" ");
        String[] str2 = s2.split(" ");
        int n1 = str1.length;
        int n2 = str2.length;
        if (n1 > n2) {
            return areSentencesSimilar(s2, s1);
        }
        int i = 0, j = 0;
        while (i < n1 && str1[i].equals(str2[i])) {
            i++;
        }
        while (j < n1 && str1[n1 - 1 - j].equals(str2[n2 - 1 - j])) {
            j++;
        }
        return i + j >= n1;
    }
}
