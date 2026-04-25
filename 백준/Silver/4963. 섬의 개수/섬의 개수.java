import java.io.*;
import java.util.*;


class Island {
    IslandGroup group;
    public Island() {
        IslandGroup group = new IslandGroup(this);
        this.group = group;
    }
}

class IslandGroup {
    HashSet<Island> islands = new HashSet<>();
    IslandGroup() {

    }

    // 그룹 통합
    IslandGroup(HashSet<Island> group1,HashSet<Island> group2) {
        islands.addAll(group1);
        islands.addAll(group2);
        Iterator<Island> it = islands.iterator();
        while (it.hasNext()) {
            it.next().group = this;
        }
    }

    IslandGroup(Island island) {
        this.islands.add(island);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = br.readLine()) != null) {
            String[] tmp = line.split(" ");
            int w = Integer.parseInt(tmp[0]);
            int h = Integer.parseInt(tmp[1]);
            if (w == 0 && h == 0) {
                return;
            }
            Island[][] islands = new Island[h][w];
            int[][] numbers = new int[h][w];
            for (int i = 0; i < h; i++) { // numbers에 다 넣어준다
                int[] widths = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
                for (int j = 0; j < widths.length; j++) {
                    numbers[i][j] = widths[j];
                }
            }

            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    if (numbers[y][x] == 0) continue; // 현재 위치기ㅏ 바다면 스킵
                    // 좌,대각선왼쪽위,위,대각선오른쪽위 체크
                    Island exist = null;

                    // 왼쪽
                    if (x - 1 >= 0 && islands[y][x - 1] != null) {
                        exist = islands[y][x-1];
                    }

                    // 대각선 왼쪽 위
                    if (x - 1 >= 0 && y - 1 >= 0 && islands[y - 1][x - 1] != null) {
                        Island thisIsland = islands[y-1][x-1];
                        if (exist != null) { // 섬 중복 : 그룹을 묶어야함
                            HashSet<Island> groupMember1 = exist.group.islands;
                            HashSet<Island> groupMember2 = thisIsland.group.islands;
                            new IslandGroup(groupMember1,groupMember2); // 새로운 그룹으로 통합
                        } else { // 이어진 섬이 존재
                            exist = thisIsland;
                        }
                    }

                    // 위쪽
                    if (y - 1 >=0 && islands[y - 1][x] != null) {
                        Island thisIsland = islands[y-1][x];
                        if (exist != null) { // 섬 중복 : 그룹을 묶어야함
                            HashSet<Island> groupMember1 = exist.group.islands;
                            HashSet<Island> groupMember2 = thisIsland.group.islands;
                            new IslandGroup(groupMember1,groupMember2);
                        } else { // 이어진 섬이 존재
                            exist = thisIsland;
                        }
                    }

                    // 대각선 오른쪽 위
                    if (x+1 < w && y-1 >= 0 && islands[y-1][x+1] != null) {
                        Island thisIsland = islands[y-1][x+1];
                        if (exist != null) { // 섬 중복 : 그룹을 묶어야함
                            HashSet<Island> groupMember1 = exist.group.islands;
                            HashSet<Island> groupMember2 = thisIsland.group.islands;
                            new IslandGroup(groupMember1,groupMember2);
                        } else { // 이어진 섬이 존재
                            exist = thisIsland;
                        }
                    }

                    if (exist==null) { // 땅이 있지만 연결된 섬이 없는 경우
                        Island island = new Island(); // 섬 새로 생성
                        islands[y][x] = island; // 새로운 섬 추가
                    } else {
                        islands[y][x] = exist;
                    }
                }
            }
            HashSet<IslandGroup> groupCountSet = new HashSet<>();
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (islands[i][j] != null) {
                        groupCountSet.add(islands[i][j].group);
                    }
                }
            }
            System.out.println(groupCountSet.size());
        }
    }
}
