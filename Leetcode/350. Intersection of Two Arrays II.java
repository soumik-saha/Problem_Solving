class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        List<Integer> ans = new ArrayList<>();
        HashMap<Integer, Integer> mp = new HashMap<>();
        for(int num:nums1) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }
        for(int num:nums2) {
            if(mp.containsKey(num) && mp.get(num)>0) {
                ans.add(num);
                mp.put(num, mp.get(num)-1);
            }
        }
        int[] result = new int[ans.size()];
        for(int i=0; i<ans.size(); i++) {
            result[i] = ans.get(i);
        }
        return result;
    }
}
