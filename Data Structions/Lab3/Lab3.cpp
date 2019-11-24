#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
typedef pair <int, int> P;
typedef pair <int, P> PP;
const int MAXN = 1e5+7;
const DB EPS = 1e-9;
const DB DB_INF = 1e100;
const DB PI=acos(-1.0);
const int INT_INF = 1e9 + 7;
const int MOD = 1e9 + 7;
void Dijkatra(Graph *G, int *D, int *F, int n) {
    int i, v, w;
    DijkElem temp;
    DijkElem E[G->e()];
    temp.distance = 0; temp.vertex = s;
    E[0] = temp;
    heap <DijkElem, DDComp> H(E, 1, G->e());
    for (i = 0; i < G->n(); i++) {
        do {
            if (H.size() == 0) return;
            temp = H.removefirst();
            v = temp.vertex;
        } while (G->getMark(v) == VISITED);
        G->setMark(v, VISITED);
        if (D[v] == INFINITY) return;
        for (w = G->first(v); w < G->n(); w = G->next(v, w))
            if (D[w] > (D[v] + G->weight(v, w))) {
                D[w] = D[v] + G->weight(v, w);
                F[w] = v;
                temp.distance = D[w]; temp.vertex = w;
                H.insert(temp);
            }
    }
}
void printPath(int *F, int ed) {
    stack <int> path;
    for (int i = ed; i != 1; i = F[i]) path.push(i);
    cout << 1;
    for (; !path.empty(); ) cout << " -> " << path.top();
    cout << endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.precision(6); cout << fixed;
    
    return 0;
}