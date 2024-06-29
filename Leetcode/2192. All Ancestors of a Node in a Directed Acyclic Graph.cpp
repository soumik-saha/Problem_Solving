class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacencyList(n);

        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            adjacencyList[to].push_back(from);
        }

        vector<vector<int>> ancestorsList;

        for (int i = 0; i < n; i++) {
            vector<int> ancestors;
            unordered_set<int> visited;
            findChildren(i, adjacencyList, visited);
            for (int node = 0; node < n; node++) {
                if (node == i) continue;
                if (visited.find(node) != visited.end())
                    ancestors.push_back(node);
            }
            ancestorsList.push_back(ancestors);
        }

        return ancestorsList;
    }

private:
    void findChildren(int currentNode, vector<vector<int>>& adjacencyList,
                      unordered_set<int>& visitedNodes) {
        visitedNodes.insert(currentNode);

        for (int neighbour : adjacencyList[currentNode]) {
            if (visitedNodes.find(neighbour) == visitedNodes.end()) {
                findChildren(neighbour, adjacencyList, visitedNodes);
            }
        }
    }
};
