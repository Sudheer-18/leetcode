class Solution {
    public List<Integer> partitionLabels(String s) {
        List<Integer> list = new ArrayList<>();
        Map<Character, Integer> hm = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            hm.put(ch, hm.getOrDefault(ch, 0) + 1);
        }
        Set<Character> HS = new HashSet<>();
        int LstIdx = -1;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            HS.add(ch);
            hm.put(ch, hm.get(ch) - 1); 

            if (hm.get(ch) == 0) {
                HS.remove(ch); 
            }

            if (HS.isEmpty()) { 
                list.add(i - LstIdx);
                LstIdx = i;
            }
        }

        return list;
    }
}
