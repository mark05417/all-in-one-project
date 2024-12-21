#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct node{
    int dis, to;
};
bool operator < (node l, node r){
    return l.dis > r.dis;
}

bool done[1001];

int dis(vector<int> &a, vector<int> &b){
    return abs(a[0]-b[0]) + abs(a[1]-b[1]);
}
int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size(), ans = 0;
    done[0] = 1;
    
    priority_queue<node> heap;
    for(int j=0;j<n;j++)    heap.push({dis(points[0], points[j]), j});

    while(!heap.empty()){
        node t = heap.top(); heap.pop();
        
        if(done[t.to])    continue;
        done[t.to] = 1;
        
        ans += t.dis;
        for(int j=0;j<n;j++){
            if(done[j]) continue;
            heap.push({dis(points[t.to], points[j]), j});
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