
# west_move = {"a":"b", "b":"c", "c":"d", "d":"a", "e":"e", "f":"f"}
# east_move = {"a":"d", "d":"c", "c":"b", "b":"a", "e":"e", "f":"f"}
# north_move = {"a":"f", "f":"c", "c":"e", "e":"a","b":"b","d":"d"}
# south_move = {"a":"e", "e":"c", "c":"f", "f":"a","b":"b","d":"d"}


class Dice:
    cur_pos_y = 0
    cur_pos_x = 0
    dct = {"a":0,"b":0,"c":0,"d":0,"e":0,"f":0}
    cur_up = 'a'
    cur_north = 'e'
    cur_south = 'f'
    cur_east = 'b'
    cur_west = 'd'
    cur_down = 'c'

    @staticmethod
    def print_up():
        print(Dice.dct[Dice.cur_up])

    @staticmethod
    def move_east():
        west_tmp = Dice.cur_west
        down_tmp = Dice.cur_down
        east_tmp = Dice.cur_east
        up_tmp = Dice.cur_up

        Dice.cur_east = up_tmp
        Dice.cur_down = east_tmp
        Dice.cur_west = down_tmp
        Dice.cur_up = west_tmp
        Dice.cur_pos_y+=1

    @staticmethod
    def move_west():
        west_tmp = Dice.cur_west
        down_tmp = Dice.cur_down
        east_tmp = Dice.cur_east
        up_tmp = Dice.cur_up
        north_tmp = Dice.cur_north
        south_tmp = Dice.cur_south

        Dice.cur_east = down_tmp
        Dice.cur_down = west_tmp
        Dice.cur_up = east_tmp
        Dice.cur_west = up_tmp
        Dice.cur_pos_y-=1


    @staticmethod
    def move_north():
        west_tmp = Dice.cur_west
        down_tmp = Dice.cur_down
        east_tmp = Dice.cur_east
        up_tmp = Dice.cur_up
        north_tmp = Dice.cur_north
        south_tmp = Dice.cur_south

        Dice.cur_up = south_tmp
        Dice.cur_down = north_tmp
        Dice.cur_north = up_tmp
        Dice.cur_south = down_tmp

        Dice.cur_pos_x-=1

    @staticmethod
    def move_south():
        west_tmp = Dice.cur_west
        down_tmp = Dice.cur_down
        east_tmp = Dice.cur_east
        up_tmp = Dice.cur_up
        north_tmp = Dice.cur_north
        south_tmp = Dice.cur_south

        Dice.cur_up = north_tmp
        Dice.cur_down = south_tmp
        Dice.cur_north = down_tmp
        Dice.cur_south = up_tmp

        Dice.cur_pos_x+=1


N, M,X_START,Y_START,K = map(int,input().split())
Dice.cur_pos_x = X_START
Dice.cur_pos_y = Y_START

v = []
for _ in range(N):
    v.append(list(map(int,input().split())))

operation_list = list(map(int,input().split()))

def is_proper_op(op):
    next_x = Dice.cur_pos_x
    next_y = Dice.cur_pos_y
    if op == 1:
        next_y+=1
    elif op == 2:
        next_y-=1
    elif op == 3:
        next_x-=1
    elif op == 4:
        next_x+=1
    if next_x < 0 or next_y <0 or next_x >= len(v) or next_y >= len(v[0]):
        return False
    return True

for op in operation_list:
    if not is_proper_op(op):
        # print(f"{op}는 불가능")
        continue
    if op == 1:
        Dice.move_east()
    elif op == 2:
        Dice.move_west()
    elif op == 3:
        Dice.move_north()
    elif op == 4:
        Dice.move_south()
    else:
        raise "err"

    # 복사 작업
    # 주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다
    if v[Dice.cur_pos_x][Dice.cur_pos_y] == 0:
        v[Dice.cur_pos_x][Dice.cur_pos_y] = Dice.dct[Dice.cur_down]
    else:
        # 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다
        Dice.dct[Dice.cur_down] = v[Dice.cur_pos_x][Dice.cur_pos_y]
        v[Dice.cur_pos_x][Dice.cur_pos_y] = 0
    Dice.print_up()
