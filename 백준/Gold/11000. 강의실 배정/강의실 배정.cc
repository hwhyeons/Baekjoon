#include <bits/stdc++.h>
using namespace std;



struct C {
    int start, end;
    // 정렬 기준: start가 큰 순(내림차순), 같다면 end가 큰 순(내림차순)
    bool operator<(const C& other) const {
        if (start != other.start) {
            return start > other.start;
        } else {
            return end > other.end;
        }
    }
};


struct Room {
    int s, e;
    // 정렬 기준: s가 큰 순(내림차순), 같다면 e가 큰 순(내림차순)
    bool operator<(const Room& other) const {
        return s < other.s;
    }
};


static const int CONST_MINMAX_INDEX = -1;


void add_new_room(multiset<Room>& rooms, int s, int e) {
    // rooms.push_back(Room{s, e});
    rooms.insert({s,e});
}

auto find_room_index_set(multiset<Room>& roomSet,int c_end) {
    auto lower_it = roomSet.lower_bound({c_end,0}); // e값은 필요 없으므로 0
    auto upper_it = roomSet.upper_bound({c_end,0});
    // 1. iterator의 start값을 확인
    // 2. 목표는 이 *it.start >= c_end 이면서 최대인 것
    // 3. upper_bound : start가 크거나 enditer
    // 4. lower_bound : start가 크거나 같거나 enditer
    // 예를들어 1 3 5 7 9 에서 c_end가 8이면 7의 위치가 나와야함 / c_end가 0이면 begin()의 위치가 나와야함


    // 작거나 같은게 없는 경우
    if (lower_it == roomSet.end()) {
        return roomSet.end();
    }

    // 가장 맨 앞에 오는 경우 : lower_it == upper_it
    if (lower_it == upper_it && lower_it == roomSet.begin()) {
        return roomSet.begin();
    }

    // 딱 맞는 값이 있을 경우 -> lower_it의 start가 c_end와 동일
    if ((*lower_it).s == c_end) {
        return lower_it;
    }

    // 같은건 없어도 작은건 있는 경우 -> upper_it--
    // upper_it--; -> 위치를 리턴하는게 아니라 삭제할걸 리턴해야됨
    return upper_it;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 입력받은 C 객체들을 담을 벡터
    vector<C> v(N);
    for(int i = 0; i < N; i++){
        int s, t;
        cin >> s >> t;
        v[i].start = s;
        v[i].end   = t;
    }

    sort(v.begin(), v.end());

    // vector<Room> rooms;
    multiset<Room> roomSet;


    // v의 각 C에 대해 처리
    for(int i = 0; i < N; i++){
        C cur_c = v[i];

        // rooms가 비어있다면 새로 추가
        if(roomSet.empty()) {
            add_new_room(roomSet, cur_c.start, cur_c.end);
            continue;
        }

        // cur_c.end를 기준으로 방을 찾음
        // 강의실의 start가 want_end보다 작거나 같은 경우
        // int room_idx = find_room_index_set(roomSet, cur_c.start,cur_c.end);
        auto room_it = find_room_index_set(roomSet, cur_c.end);

        // 가능한 room이 없다면 새로 생성
        if(room_it == roomSet.end()) {
            add_new_room(roomSet, cur_c.start, cur_c.end);
        }
        else {

            // 찾은 room을 갱신 (s만 바꾸고 다시 정렬)
            // new room : start = cur_c.start / end = (*room_it).end?
            // (C++) 룸 삭제

            int beforeEnd = (*room_it).e; // 삭제전 필요한 값 복사

            roomSet.erase(room_it);

            // 변경 후 rooms 전체를 다시 정렬
            // sort(rooms.begin(), rooms.end());
            // // rooms[room_idx].s = cur_c.start;

            roomSet.insert({cur_c.start,beforeEnd});
        }
    }

    // 결과 출력 (rooms의 개수)
    cout << roomSet.size() << "\n";
    return 0;
}
