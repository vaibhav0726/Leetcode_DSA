class Solution {
    HashMap<Integer, HashMap<Integer, Integer>> map;
    
    public int[] Indegree() {
        int[] in = new int[map.size()];
        for (int key : map.keySet()) {
            for (int nbrs : map.get(key).keySet()) {
                in[nbrs]++;
            }
        }
        return in;
    }
    
    public boolean IsCycle() {
        int[] in = Indegree();
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < in.length; i++) {
            if (in[i] == 0) {
                q.add(i);
            }
        }
        int count = 0;
        while (!q.isEmpty()) {
            int rv = q.poll();
            count++;
            for(int nbrs : map.get(rv).keySet()) {
                in[nbrs]--;
                if (in[nbrs] == 0) {
                    q.add(nbrs);
                }
            }
        }
        return count == map.size();
    }
    
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        map = new HashMap<>();
        Solution sl = new Solution();
        for (int i = 0; i < numCourses; i++) {
            map.put(i, new HashMap<>());
        }
        for(int i=0; i<prerequisites.length; i++){
            map.get(prerequisites[i][1]).put(prerequisites[i][0], 0);
        }
        return IsCycle();
    }
}