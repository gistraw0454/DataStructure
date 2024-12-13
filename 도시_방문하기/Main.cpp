#include <iostream>
#include <string>
using namespace std;

// 간단한 큐 구현
class Queue {
private:
    int data[100]; // 최대 100개의 요소를 저장할 수 있는 큐
    int front, rear;

public:
    Queue() : front(0), rear(0) {}

    void enqueue(int value) {
        data[rear++] = value;
    }

    int getFront() {
        return data[front];
    }

    void dequeue(int& store) {
        store = this->getFront();
        front++;
    }

    bool empty() {
        return front == rear;
    }
};

// 그래프 구조체 정의
struct Graph {
    int numVertices = 10;              // 정점 개수
    string vertices[10];               // 정점 이름 (최대 10개)
    int edges[10][10];                 // 인접 행렬 (최대 10x10)

    // 그래프 초기화 함수
    void initialize() {
        // 초기 도시 리스트
        string defaultCities[] = {
            "Busan", "Changwon", "Daegu", "Daejeon", "Gangreung",
            "Gwangju", "Incheon", "Seoul", "Ulsan", "Yeosu"
        };

        for (int i = 0; i < numVertices; i++) {
            vertices[i] = defaultCities[i];
        }

        // 초기 연결 상태
        int defaultEdges[10][10] = {
            {0, 1, 1, 0, 0, 0, 0, 0, 1, 0},
            {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 0, 1, 0, 1, 0, 0, 1, 0},
            {0, 0, 1, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
            {0, 0, 1, 1, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 1, 1, 0, 1, 0, 0, 0},
            {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 1, 0, 0, 0, 0}
        };

        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                edges[i][j] = defaultEdges[i][j];
            }
        }
    }
};

// BFS 함수 정의
void bfs(Graph& graph, int start, int order[], int& orderCount) {
    bool visited[10] = {false}; // 방문 여부 확인
    Queue q;

    q.enqueue(start);           // 시작지점 enqueue
    visited[start] = true;      // 방문 표시

    while (!q.empty()) {
        int vertex;
        q.dequeue(vertex);      // 큐에서 정점을 꺼냄

        order[orderCount++] = vertex; // 방문 순서 기록

        // 인접 노드 탐색
        for (int i = 0; i < graph.numVertices; ++i) {
            if (graph.edges[vertex][i] == 1 && !visited[i]) { // 연결o && 방문X
                visited[i] = true; // 방문표시
                q.enqueue(i); // 큐에 추가
            }
        }
    }
}

int main() {
    Graph graph;
    graph.initialize(); // 그래프 초기화

    for (int i = 0; i < graph.numVertices - 1; ++i) {
        for (int j = 0; j < graph.numVertices - i - 1; ++j) {
            if (graph.vertices[j] > graph.vertices[j + 1]) {

                string tempCity = graph.vertices[j];
                graph.vertices[j] = graph.vertices[j + 1];
                graph.vertices[j + 1] = tempCity;

                for (int k = 0; k < graph.numVertices; ++k) {
                    swap(graph.edges[k][j], graph.edges[k][j + 1]);
                    swap(graph.edges[j][k], graph.edges[j + 1][k]);
                }
            }
        }
    }


    int start;
    cin >> start;

    int visitOrder[10];
    int orderCount = 0;

    bfs(graph, start, visitOrder, orderCount);

	int i=0;
    for (i = 0; i < orderCount - 1; ++i) {
        cout << graph.vertices[visitOrder[i]] << ", ";
    }
    cout << graph.vertices[i] << endl;

    return 0;
}
