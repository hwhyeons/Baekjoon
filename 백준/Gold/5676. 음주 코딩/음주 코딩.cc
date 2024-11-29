#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
typedef long long ll;
using namespace std;

// -----------------------------------------
// -----------------------------------------
// -----------------------------------------

typedef int Num; // Num : -1,0,1


// s,e : index in vector
// curIndex : index in segtree
Num initTree(vector<int>& v, vector<Num>& segmentTree, int curIndex, int s, int e) {
    if (s == e) {
        int realValue = v[s];
        Num num;
        if (realValue == 0) {
            num = 0;
        } else if (realValue > 0) {
            num = 1;
        } else {
            num = -1;
        }
        segmentTree[curIndex] = num;
        return num;
    }
    if (e < s) throw "err";

    int lci = curIndex*2; // left child index (세그먼트트리)
    int rci = lci + 1;
    int midIndex = (s + e) / 2;
    Num leftChildAcc = initTree(v,segmentTree,lci,s,midIndex);
    Num rightChildAcc = initTree(v, segmentTree,rci ,midIndex+1,e);
    segmentTree[curIndex] = leftChildAcc * rightChildAcc;
    return segmentTree[curIndex];
}


void updateUp(vector<int>& v, vector<Num>& segmentTree, int curTreeIndex) {
    if (curTreeIndex <= 0) return; // 범위 벗어난 경우
    int childIndexInTree1 = curTreeIndex*2;
    int childIndexInTree2 = childIndexInTree1+1;
    Num n1 = segmentTree[childIndexInTree1];
    Num n2 = segmentTree[childIndexInTree2];
    segmentTree[curTreeIndex] = n1 * n2;
    if (curTreeIndex == 1) return;
    int parentTreeIndex = curTreeIndex / 2;
    updateUp(v,segmentTree, parentTreeIndex);
}


// 호출시 newValue는 - 1, 0, 1;
void updateDown(vector<int>& v, vector<Num>& segmentTree, const int changeVectorIndex, int curTreeIndex, int s, int e, Num newValue) {

    // 범위를 벗어난 경우
    if (!(s <= changeVectorIndex && changeVectorIndex <= e)) return;
    if (s > e || s < 0) throw "err";
    if (s == e) { // 마지막 update지점 -> 이제 updateUp방향으로 갱신
        // updateUp호출
        if (s != changeVectorIndex) throw "err";
        v[changeVectorIndex] = newValue;
        segmentTree[curTreeIndex] = newValue;
        updateUp(v, segmentTree, curTreeIndex/2); // 부모부터 시작
        return;
    }

    // 절반씩 재귀
    int midVectorIndex = (s + e) / 2;
    updateDown(v,segmentTree, changeVectorIndex, curTreeIndex * 2, s, midVectorIndex, newValue);
    updateDown(v, segmentTree, changeVectorIndex, curTreeIndex * 2 + 1, midVectorIndex + 1, e, newValue);
}

Num getAcc(vector<Num>& seg, int segIndex, int wantS, int wantE, int curSegStart, int curSegEnd) {
    if (wantE < curSegStart || wantS > curSegEnd) return 1; // 값 보존을 위해 1 리턴 (-1*1 = -1 / 0*1 = 0 / 1*1 = 1)
    if (curSegStart == curSegEnd) return seg[segIndex];
    // 현재 표현 범위가 원하는 범위 내에 들어갈 경우 바로 리턴
    if (curSegStart >= wantS && curSegEnd <= wantE) return seg[segIndex];

    int leftChildSegIndex = segIndex * 2;
    int rightChildSegIndex = leftChildSegIndex + 1;

    int midSegIndex = (curSegStart + curSegEnd) / 2;
    Num leftAnswer = getAcc(seg, leftChildSegIndex, wantS, wantE, curSegStart, midSegIndex);
    Num rightAnswer = getAcc(seg, rightChildSegIndex, wantS, wantE, midSegIndex+1, curSegEnd);
    return leftAnswer * rightAnswer;
}


//while (!cin.eof()) {    //EOF를 만날때까지 무한 입력
//    cin >> n;
//}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //auto vi = ranges::istream_view<string>(cin);
    //auto it = vi.begin();
    //string answer_str = "";
    //while (it != vi.end()) {
    while (!cin.eof()) {
        //string s1 = *it; it++;
        //const int N = stoi(s1);
        int N;
        cin >> N;
        //string s2 = *it; it++;
        //const int K = stoi(s2);
        int K;
        cin >> K;
        vector<int> v; // 0번 인덱스 추가
        
        // 4xN개 생성
        // 초기값 1로 초기화 (인덱스 벗어나도 영향 안받게)
        vector<Num> segmentTree(4 * N,1); 
        for (size_t i = 0; i < N; i++) {
            //string tmp = *it;
            //v.push_back(stoi(tmp));
            //it++;
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }

        initTree(v,segmentTree,1,0,v.size()-1);

        for (size_t i = 0; i < K; i++) {
            //string oper = *it; it++;
            string oper;
            cin >> oper;
            //int a = stoi((string)*it); it++;
            //int b = stoi((string)*it); it++;
            int a, b;
            cin >> a >> b;
            if (oper == "C") {
                int wantChangeIndex = a-1;  // b는 수정하면 안됨 (값이므로)
                Num newVal = b > 0 ? 1 : (b == 0 ? 0 : -1);
                updateDown(v, segmentTree, wantChangeIndex, 1, 0, v.size()-1, newVal);
            } else if (oper == "P") {
                a--;
                b--;
                Num answer = getAcc(segmentTree, 1, a, b, 0, v.size()-1);
                if (answer == -1) {
                    //answer_str += "-";
                    cout << "-";
                } else if (answer == 0) {
                    //answer_str += "0";
                    cout << "0";
                } else if (answer == 1) {
                    //answer_str += "+";
                    cout << "+";
                } else {
                    throw "err2";
                }
            }
        }
        // test case end -> endl
        //answer_str +="\n";
        cout << "\n";
    }
    //cout << answer_str;
}