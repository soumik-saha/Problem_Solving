class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> st = new Stack<>();
        int result[] = new int[temperatures.length];
        for(int i = temperatures.length - 1; i >= 0; i--) {
            while(st.size() > 0 && temperatures[i] >= temperatures[st.peek()])
                st.pop();
            if(st.size() > 0)
                result[i] = st.peek() - i;
            st.push(i);
        }
        return result;
    }
}
