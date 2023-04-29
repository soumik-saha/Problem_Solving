class UnionFind {
public:
    vector<int> group;
    vector<int> rank;

    UnionFind(int size) {
        group = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; ++i) {
            group[i] = i;
        }
    }

    int find(int node) {
        if (group[node] != node) {
            group[node] = find(group[node]);
        }
        return group[node];
    }

    void join(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);

        if (group1 == group2) {
            return;
        }

        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group1] < rank[group2]) {
            group[group1] = group2;
        } else {
            group[group1] = group2;
            rank[group2] += 1;
        }
    }

    bool areConnected(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);
        return group1 == group2;
    }
};


class Solution {
public:
    bool static compare(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        UnionFind uf(n);
        int queriesCount = queries.size();
        vector<bool> answer(queriesCount);

        vector<vector<int>> queriesWithIndex(queriesCount);
        for (int i = 0; i < queriesCount; ++i) {
            queriesWithIndex[i] = queries[i];
            queriesWithIndex[i].push_back(i);
        }

        int edgesIndex = 0;

        sort(edgeList.begin(), edgeList.end(), compare);
        
        sort(queriesWithIndex.begin(), queriesWithIndex.end(), compare);

        for (auto& query : queriesWithIndex) {
            int p = query[0];
            int q = query[1];
            int limit = query[2];
            int queryOriginalIndex = query[3];

            while (edgesIndex < edgeList.size() && edgeList[edgesIndex][2] < limit) {
                int node1 = edgeList[edgesIndex][0];
                int node2 = edgeList[edgesIndex][1];
                uf.join(node1, node2);
                edgesIndex += 1;
            }

            answer[queryOriginalIndex] = uf.areConnected(p, q);
        }

        return answer;
    }
};
