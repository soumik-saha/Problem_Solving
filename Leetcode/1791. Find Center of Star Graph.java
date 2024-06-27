class Solution {
    public int findCenter(int[][] edges) {
        HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for(int[] edge:edges) {
            mp.put(edge[0], mp.getOrDefault(edge[0], 0) + 1);
            mp.put(edge[1], mp.getOrDefault(edge[1], 0) + 1);
        }

        for(HashMap.Entry<Integer, Integer> it:mp.entrySet()) {
            if(it.getValue()==edges.length) {
                return it.getKey();
            }
        }

        return -1;
    }
}
