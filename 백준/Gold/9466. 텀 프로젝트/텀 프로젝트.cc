#include <iostream>
#include <cstdio>
#include <memory.h>
#include <vector>
 
using namespace std;
 
int parent[100002];
int visit[100002];
int prevNum[100002];
 
int cycleTest;
vector<int> cycle;
 
int isCycle(int root, int prev, int here, int cnt)
{
    // 이미 체크된 노드에 대해서는 return -1
    if (parent[here] == -1)
        return -1;
 
    // 현재 cycleTest번째에 이미 방문한 적이 있는가?
    if (visit[here] == cycleTest)
    {
        // 시작->끝이 사이클인가?
        if (here == root)
            return cnt - 1;
 
        // 시작->끝이 사이클이 아니라면 사이클이 그사이 존재했는것
        // 따라서 꼬리부분을 제외한 사이클 부분을 return
        return cnt - prevNum[here];
    }
 
    // 자신의 뒷부분에 따라오는 노드를 추가
    prevNum[here] = prevNum[prev] + 1;
    
    // here은 cycleTest번째에 방문을 하고있다
    visit[here] = cycleTest;
    // 그에 해당하는 here을 벡터에 담아둔다.(사이클이든 아니든)
    cycle.push_back(here);
 
    return isCycle(root, here, parent[here], cnt + 1);
}
 
 
int main()
{
    int tCase;
 
    scanf("%d", &tCase);
 
    while (tCase--)
    {
        int n;
        int ans = 0;
 
        scanf("%d", &n);
 
        for (int i = 1; i <= n; i++)
            scanf("%d", &parent[i]);
 
        for (int i = 1; i <= n; i++)
        {
            // 이미 체크된 노드라면 continue;
            if (parent[i] == -1)
                continue;
            
            // cycleTest번째를 늘려준다.(visit를 memset하는것 대신 이용)
            cycleTest++;
            cycle.clear();
            // get에는 사이클의 크기가 담겨온다.
            int get = isCycle(i, 0, i, 1);
            
            // 사이클이 존재한다면
            if (get != -1)
            {
                ans += get;
                cycleTest++;
            }
            
            // 사이클이었든 아니었든 벡터에 담긴 값들은 모두 -1로 없앤다.
            int len = cycle.size();
            for (int i = 0; i < len; i++)
                parent[cycle[i]] = -1;
        }
 
        // 전체 노드 - 사이클을 이룬 수
        printf("%d\n", n - ans);
    }
 
    return 0;
}