남아프리카 케이프타운 초원의 잠자리들이 자신들의 영역을 지키기 위한 전투가 시작되었습니다.
잠자리들은 자신의 구역을 뱅뱅 돌다가, 자신의 구역에 침범한 상대방과 부딫친 경우 전투가 일어납니다.
부딪친 두 마리의 잠자리 중 전투력이 더 높은 잠자리가 상대방을 잡아먹을 수 있습니다.

15초 후 전쟁이 종료됩니다. 
전쟁이 종료된 후, 가장 강력한 잠자리의 전투력을 출력 해 주세요.


[잠자리 전투력 상승 조건]
잠자리들은 초기 상태 전투력을 갖고 있으며, 아래 조건에 의해 전투력이 상승합니다.
1. 잠자리가 자신보다 전투력이 낮은 잠자리를 잡아먹고, 잡아먹은 잠자리의 전투력 만큼 전투력이 상승합니다. 
2. 잠자리가 비행반경 만큼 비행하여 원래 위치로 살아 돌아온 경우 잠자리의 전투력은 +1 상승합니다.

[세부 조건]
1. 0초 부터 배치가 되고, 1초부터 잠자리가 움직이면서 전쟁이 시작됩니다. 15초 후 전쟁이 종료 됩니다. 
2. 15초 되는 순간에도 전투가 일어난 뒤, 전쟁이 종료 됩니다.
3. 같은 전투력의 잠자리가 전투를 하면, 비행거리가 더 큰 잠자리가 이깁니다.
4. 만약 전투력도 같고, 비행거리도 같은 잠자리가 전투를 한다면 두 잠자리는 모두 죽습니다.
5. 전투력이 +1 되는 위치로 돌아왔는데 즉시 전투가 시작된다면, +1 전투력으로 전투를 하게 됩니다.
6. 잠자리는 비행 중 맵 밖으로 나가지 않는 입력만 주어집니다.

7. 세 마리 이상의 잠자리가 동시에 싸우는 입력은 주어지지 않습니다.

입력
N x M 사이즈의 Map을 먼저 입력 받으세요. (세로 x 가로)
그리고 잠자리의 수 T와, T개의 잠자리 정보를 입력 받습니다. (y, x, power, dist)

 

(1 <= 잠자리 최대 이동거리 dist <= 5)
(1 <= N, M, T <= 100)

출력
전쟁이 종료된 후, 가장 강력한 잠자리의 전투력을 출력 해 주세요.
만약 모든 잠자리가 전멸했다면 0 을 출력 해주세요.

입력 예시 1 
7 7
3
1 1 4 2
0 2 5 4
2 2 13 3

출력 예시 1
14
