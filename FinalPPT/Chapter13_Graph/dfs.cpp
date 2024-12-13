// stack 만들기
// stack.push(startvertex);
bool found = false;
do
{
    stack.Pop(vertext);
    if (vertex== endVertex){
        Write final vertex;
        found = true;
    }
    else{
        vertex에 mark 하기
        push all unmarked 인접 vertices onto stack
    }
} while (!stack.InEmpty()&&!found);

if (!found){
    // 경로 읍다.
}
