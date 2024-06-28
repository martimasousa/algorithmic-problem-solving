#include <cstdio>
#include <vector>

using namespace std;

vector<bool> isVisited;
vector<int> initialTime;
vector<int> finalTime;
int nVertices;
int time = -1;

// This vector will contain the main vertice in the cycle for each vertice (-1 if it's not in a cycle)
vector<int> cycleParent;

vector<vector<int>> graph2;
vector<vector<int>> graphT2;


/**
 * This function reads a line from the console and returns an array of integers.
 */
vector<int> readLine() {
    vector<int> numbers;
    int number;
    
    for (int i = 1; i <= 2; i++) {
        if(scanf("%d", &number) != 1) {
            break;
        }
        numbers.push_back(number);
    }

    return numbers;
}


void deleteVertices(vector<int> &vertices) {
    for (int v : vertices) {
        cycleParent[v] = vertices[0];
    }
}


void visitFirstTime(int v_id, vector<int> &queue, vector<vector<int>> &g) {
    isVisited[v_id] = true;
    queue.push_back(v_id);

    initialTime[v_id] = ++time;

    for (int v_adj : g[v_id]) {
        if (!isVisited[v_adj]) {
            queue.push_back(v_adj);
        }
    }
}

vector<int> dfsAlgorithm_visit(int v_id, vector<vector<int>> &g) {
    vector<int> visitedVertices;
    vector<int> queue;

    visitFirstTime(v_id, queue, g);

    while (queue.size() > 0) {
        v_id = queue[queue.size() - 1];
        queue.pop_back();

        if (isVisited[v_id]) {
            if (finalTime[v_id] == -1) {
                visitedVertices.push_back(v_id);
                finalTime[v_id] = ++time;
            }
            continue;
        }

        visitFirstTime(v_id, queue, g);
    }

    return visitedVertices;
}

void dfsAlgorithm() {
    vector<int> orderEndTimes;

    vector<int> visitedVertices;
    for(int v_id = 0; v_id < nVertices; v_id++) {
        if (!isVisited[v_id]) {            
            visitedVertices = dfsAlgorithm_visit(v_id, graph2);
            
            for (int v : visitedVertices) orderEndTimes.push_back(v);
        }
    }

    for (int i = 0; i < nVertices; i++) isVisited[i] = false, initialTime[i] = -1, finalTime[i] = -1;
    time = 0;

    vector<int> cycleVertices;
    for (int i = nVertices - 1; i >= 0; i--) {
        int v_id = orderEndTimes[i];
        if (!isVisited[v_id]) {            
            cycleVertices = dfsAlgorithm_visit(v_id, graphT2);

            if (cycleVertices.size() > 1) deleteVertices(cycleVertices);
        }
    }

    int maxSize = 0;
    vector<int> pathSizes(nVertices, 0);
    for (int i = 0; i < nVertices; i++) {
        int v_id = orderEndTimes[i];

        for (int v_adj : graph2[v_id]) {
            // The important values will be in the respective cycleParents
            int v_id_ref = (cycleParent[v_id] == -1) ? v_id : cycleParent[v_id];
            int v_adj_ref = (cycleParent[v_adj] == -1) ? v_adj : cycleParent[v_adj];

            if (v_adj_ref == v_id_ref) continue;

            pathSizes[v_id_ref] = (pathSizes[v_id_ref] < pathSizes[v_adj_ref] + 1) ? pathSizes[v_adj_ref] + 1 : pathSizes[v_id_ref];

            if (pathSizes[v_id_ref] > maxSize) maxSize = pathSizes[v_id_ref];
        }
    }

    printf("%d\n", maxSize);
}

int main() {
    // 1. Read the first line from input
    vector<int> firstLine = readLine();
    nVertices = firstLine[0] + 1;

    // 2. Initialize adjacencies table (graph) and graphT
    for (int i = 0; i < nVertices; i++) {
        vector<int> line;
        
        graph2.push_back({});
        graphT2.push_back({});

        isVisited.push_back(false);
        initialTime.push_back(-1);
        finalTime.push_back(-1);
        cycleParent.push_back(-1);
    }

    // 3. Read relationships from input and update connections between vertices
    for (int i = 0; i < firstLine[1]; i++) {
        vector<int> line = readLine();

        graph2[line[0]].push_back(line[1]);
        graphT2[line[1]].push_back(line[0]);
    }
    
    // 4. Call DFS to delete all the cycles
    dfsAlgorithm();

    return 0;
}