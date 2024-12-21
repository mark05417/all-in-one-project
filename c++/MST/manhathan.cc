#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <numeric>

using namespace std;

struct edge{
    int len, to;
};
bool operator < (edge l, edge r){
    return l.len > r.len;
}

// points: i -> {x, y}
// Graph: i -> {edges}
vector<vector<edge>> buildGraph(vector<vector<int>> &points){
    int n = points.size();
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    vector<vector<edge>> graph(n);
    for(int rotate=0;rotate<4;rotate++){
        // sort points according to x+y
        sort(ids.begin(), ids.end(), [&](int a, int b){
            return (points[a][0] + points[a][1]) < (points[b][0] + points[b][1]);
        });
        // use active set to find the nearest vertex v2 in R1 for every vertex v1
        map<int, int, greater<int>> active; // (x, id)
        for(int i=0;i<n;i++){
            int v1 = ids[i], x1 = points[v1][0], y1 = points[v1][1];
            // find the nearest vertex in R1
            for(auto it = active.lower_bound(x1); it != active.end(); active.erase(it++)){
                int v2 = it->second, x2 = points[v2][0], y2 = points[v2][1];
                if(x1 - y1 > x2 - y2) break;
                graph[v1].push_back({abs(x1 - x2) + abs(y1 - y2), v2});
                graph[v2].push_back({abs(x1 - x2) + abs(y1 - y2), v1});
            }
            active[x1] = v1;
        }
        // rotate for every rotation
        for(int i=0;i<n;i++){
            if(rotate & 1) points[i][0] *= -1;
            else swap(points[i][0], points[i][1]);
        }
    }
    return graph;
}

int minCostConnectPoints(vector<vector<int>>& points) {
    vector<vector<edge>> graph = buildGraph(points);
    int n2 = graph.size();

    // initialize
    int n = points.size(), ans = 0;
    vector<bool> done(n, false);
    priority_queue<edge> heap; // min heap
    
    // handle vertex 0
    for(int i=0;i<graph[0].size();i++){
        heap.push({graph[0][i].len, graph[0][i].to});
    }
    done[0] = true;
    
    // kruskal
    while(!heap.empty()){
        edge t = heap.top(); heap.pop();
        if(done[t.to]) continue;
        done[t.to] = true;
        ans += t.len;
        for(int i=0;i<graph[t.to].size();i++){
            heap.push({graph[t.to][i].len, graph[t.to][i].to});
        }
    }
    return ans;
}

int main(void){
    int n;
    vector<vector<int>> points;
    cin >> n;
    for(int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    cout << minCostConnectPoints(points) << endl;
    return 0;
}