class Solution {
    public int minimumPushes(String word) {
        int[] arr = new int[26];
        int j=0,cnt=1,ans=0;
        for(int i=0;i<word.length();i++) {
            arr[word.charAt(i)-'a']++;
        }
        Arrays.sort(arr);
        for(int i=25;i>=0;i--) {
            ans+=cnt*arr[i];
            j++;
            if(j%8==0) cnt++;
        }
        return ans;
    }
}