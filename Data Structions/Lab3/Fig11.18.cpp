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