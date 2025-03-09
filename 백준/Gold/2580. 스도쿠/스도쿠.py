class g:
    row_dict: dict[int,set[int]] = dict() # 특정 row에
    col_dict: dict[int,set[int]] = dict() # 특정 row에
    rectangle: dict[int,set[int]] = dict()
    left = 0

def print_answer():
    for i in range(9):
        for j in range(9):
            print(v[i][j], end=' ')
        print()
    exit(0)

def get_rectangle_num(y,x):
    if 0<=y<=2:
        if 0<=x<=2:
            return 1
        elif 3<=x<=5:
            return 2
        elif 6<=x<=8:
            return 3
    if 3<=y<=5:
        if 0<=x<=2:
            return 4
        elif 3<=x<=5:
            return 5
        elif 6<=x<=8:
            return 6
    if 6<=y<=8:
        if 0<=x<=2:
            return 7
        elif 3<=x<=5:
            return 8
        elif 6<=x<=8:
            return 9
    raise "err"

def dfs(need_idx: int):
    global v,needs
    # 후보군
    y,x = needs[need_idx]
    for num in range(1,10):
        if y not in g.row_dict:
            g.row_dict[y] = set()
        if x not in g.col_dict:
            g.col_dict[x] = set()
        rect_num = get_rectangle_num(y,x)
        if num in g.row_dict[y] or num in g.col_dict[x] or num in g.rectangle[rect_num]:
            continue
        v[y][x] = num
        g.left -=1
        if g.left ==0:
            print_answer()

        g.row_dict[y].add(num)
        g.col_dict[x].add(num)
        g.rectangle[rect_num].add(num)

        dfs(need_idx+1)

        v[y][x] = 0
        g.row_dict[y].remove(num)
        g.col_dict[x].remove(num)
        g.rectangle[rect_num].remove(num)
        g.left +=1




if __name__ == '__main__':
    v = []

    for _ in range(9):
        v.append(list(map(int,input().split())))


    needs: list[tuple[int,int]] = []
    for i in range(1,9+1):
        g.rectangle[i] = set()

    for i in range(9):
        for j in range(9):
            rect_num = get_rectangle_num(i,j)
            if v[i][j] == 0:
                needs.append((i,j))
                g.left+=1
            else:
                if i not in g.row_dict:
                    g.row_dict[i] = set()
                if j not in g.col_dict:
                    g.col_dict[j] = set()
                g.rectangle[rect_num].add(v[i][j])
                g.row_dict[i].add(v[i][j])
                g.col_dict[j].add(v[i][j])

    dfs(0)
