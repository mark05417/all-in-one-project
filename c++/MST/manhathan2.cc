#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <numeric>

using namespace std;

struct edge{
    int len, i, j;
};

// points: i -> {x, y}
// Graph: i -> {edges}
vector<edge> buildGraph(vector<vector<int>> &points){
    int n = points.size();
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    vector<edge> graph;
    for(int rotate=0;rotate<4;rotate++){
        // rotate for every rotation
        for(int i=0;i<n;i++){
            if(rotate == 2)
                points[i][0] *= -1;
            else if(rotate == 1 || rotate == 3)
                swap(points[i][0], points[i][1]);
        }
        // sort points according to x+y
        sort(ids.begin(), ids.end(), [&](int a, int b){
            return (points[a][0] + points[a][1]) < (points[b][0] + points[b][1]);
        });
        map<int,int> active; // according to x - y
        for(int i=0;i<n;i++){
            int v1 = ids[i], x1 = points[v1][0], y1 = points[v1][1];
            for(auto it = active.lower_bound(x1 - y1); it != active.end(); active.erase(it++)){
                int v2 = it->second, x2 = points[v2][0], y2 = points[v2][1];
                graph.push_back({abs(x1 - x2) + abs(y1 - y2), v1, v2});
            }
            active[x1 - y1] = v1;
        }
    }
    return graph;
}

int find(vector<int> &parent, int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}
void union2(vector<int> &parent, int x, int y){
    parent[find(parent, x)] = find(parent, y);
}
int minCostConnectPoints(vector<vector<int>>& points) {
    vector<edge> graph = buildGraph(points);

    // initialize
    int n = points.size(), ans = 0;
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);
    sort(graph.begin(), graph.end(), [&](edge a, edge b){
        return a.len < b.len;
    });
    for(int i=0;i<graph.size();i++){
        if(find(parent, graph[i].i) != find(parent, graph[i].j)){
            ans += graph[i].len;
            union2(parent, graph[i].i, graph[i].j);
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