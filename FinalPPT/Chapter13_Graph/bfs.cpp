// bfs
bool found = false;

queue.Enqueue(startVertex);

do
{
    /* code */
    queue.Dequeue(vertex);  // 날리면서 vertex에 날린거 저장
    if (vertex == endVertex){
        // write final vertex;
        found = true;
    }
    else{
        // mark this vertex
        // enqueue all unmarked adjacent vertices
    }
} while (!queue.IsEmpty()&&!found);

if (!found){
    // 경로 읍다.
}