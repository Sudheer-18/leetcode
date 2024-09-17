class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        String[] arr1 = s1.split(" ");
        String[] arr2 = s2.split(" ");
        HashMap<String, Integer> hm = new HashMap<>();
        for (String st : arr1) {
            hm.put(st, hm.getOrDefault(st, 0) + 1);
        }
        for (String st : arr2) {
            hm.put(st, hm.getOrDefault(st, 0) + 1);
        }
        List<String> result = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : hm.entrySet()) {
            String key = entry.getKey();
            int value = entry.getValue();
            if (value == 1) {
                result.add(key);
            }
        }
        return result.toArray(new String[0]);
    }
}
