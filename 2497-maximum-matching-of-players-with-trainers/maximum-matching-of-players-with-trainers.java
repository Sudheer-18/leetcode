class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        int i = 0, j = 0;
        int PN = players.length , TN = trainers.length;
        Arrays.sort(players);
        Arrays.sort(trainers);
        int ans = 0;
        while (i < PN && j < TN) {
            if(players[i] <= trainers[j]) {
                ans++;
                i++;
            }
            j++;
        }

        return ans;
       
    }
}