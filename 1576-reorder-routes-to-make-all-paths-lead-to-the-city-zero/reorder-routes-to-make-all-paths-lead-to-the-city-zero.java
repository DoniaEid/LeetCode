class Solution {
    public int minReorder(int n, int[][] connections) {
        List<int[]>[] adj = new List[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        
        for (int[] c : connections) {
            adj[c[0]].add(new int[]{c[1], 1});
            adj[c[1]].add(new int[]{c[0], 0});
        }

        boolean[] inFamily = new boolean[n];
        int count = 0;
        
        List<Integer> familyList = new ArrayList<>();
        familyList.add(0);
        inFamily[0] = true;

        for (int i = 0; i < familyList.size(); i++) {
            int currentMember = familyList.get(i);
            
            for (int[] edge : adj[currentMember]) {
                int neighbor = edge[0];
                int isOutbound = edge[1];
                
                if (!inFamily[neighbor]) {
                    count += isOutbound;
                    
                    inFamily[neighbor] = true;
                    familyList.add(neighbor);
                }
            }
        }
        
        return count;
    }
}