P,M = map(int,input().split())
nick_dict = dict() # {name,level}

class Room:
    def __init__(self,min_level, max_level):
        self.min_level = min_level
        self.max_level = max_level
        self.personList: list[str] = []

    def is_ok(self,level):
        if len(self.personList) >= M:
            return False
        if not (self.min_level <= level <= self.max_level):
            return False
        return True


rooms: list[Room] = []
for _ in range(P):
    level_str, name = input().split()
    level = int(level_str)
    nick_dict[name] = level
    # 적합한 방 찾기
    selected_room = None
    for room in rooms:
        if not room.is_ok(level):
            continue
        selected_room = room
        break
    if selected_room is not None:
        selected_room.personList.append(name)
    else:
        # 방못찾은경우 -> 새방파기
        new_room = Room(level-10,level+10)
        new_room.personList.append(name)
        rooms.append(new_room)


for room in rooms:
    if len(room.personList) == M:
        print("Started!")
    else:
        print("Waiting!")
    room.personList.sort()
    for person_name in room.personList:
        print(nick_dict[person_name],person_name)



