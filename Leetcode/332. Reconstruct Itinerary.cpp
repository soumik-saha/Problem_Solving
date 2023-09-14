vector<int> FindEulerPath(int len, const vector<vector<int>>& graph, int start) {
  const int N = graph.size();
  vector<int> counts(N);

  vector<int> path = {start};
  vector<int> tail;
  while (true) {
    for (int node = path.back(); counts[node] < graph[node].size();) {
      int next = graph[node][counts[node]++];
      path.push_back(next);
      node = next;
    }

    if (path.size() + tail.size() >= len) {
      break;
    }
    while (counts[path.back()] == graph[path.back()].size()) {
      tail.push_back(path.back());
      path.pop_back();
    }
  }
  path.insert(path.end(), tail.rbegin(), tail.rend());
  return path;
}

vector<string_view> GetAllNames(const vector<vector<string>>& tickets) {
  vector<string_view> names;
  for (const vector<string>& edge : tickets) {
    names.push_back(edge[0]);
    names.push_back(edge[1]);
  }
  std::sort(names.begin(), names.end());
  names.erase(std::unique(names.begin(), names.end()), names.end());
  return names;
}

struct IdGen {
  vector<string_view> names;
  unordered_map<string_view, int> ids;

  int GetId(string_view name) const {
    return ids.find(name)->second;
  }

  string_view GetName(int id) const {
    return names[id];
  }

  int GetOrCreateId(string_view name) {
    auto it = ids.find(name);
    if (it == ids.end()) {
      int id = names.size();
      names.push_back(name);
      it = ids.insert(it, {name, id});
    }
    return it->second;
  }
};

class Solution {
public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string_view> all_names = GetAllNames(tickets);
    IdGen id_gen;
    for (string_view name : all_names) {
      id_gen.GetOrCreateId(name);
    }

    vector<vector<int>> graph;
    for (const vector<string>& edge : tickets) {
      int a = id_gen.GetId(edge[0]);
      int b = id_gen.GetId(edge[1]);
      if (int node = max(a, b); graph.size() <= node) {
        graph.resize(node + 1);
      }
      graph[a].push_back(b);
    }
    for (vector<int>& outgoing : graph) {
      std::sort(outgoing.begin(), outgoing.end());
    }

    vector<int> path = FindEulerPath(tickets.size() + 1, graph, id_gen.GetId("JFK"));

    vector<string> answer(path.size());
    for (int i = 0; i < path.size(); ++i) {
      answer[i] = id_gen.GetName(path[i]);
    }
    return answer;
  }
};
