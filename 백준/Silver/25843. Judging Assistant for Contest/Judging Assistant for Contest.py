import sys
# sys.setrecursionlimit(10**6)
# 메모리 초과 -> pypy 대신 python / recursionlimit 제한 하기
input = sys.stdin.readline
print = sys.stdout.write


name_no_ext:str = input().rstrip("\n")
name_with_ext:str = input().rstrip("\n")

if not "." in name_with_ext or name_with_ext[:name_with_ext.rfind(".")] != name_no_ext:
    print("Compile Error")
    exit(0)

r,d,e = map(int,input().split())
if e > d:
    print("Time Limit Exceeded")
    exit(0)
elif r != 0:
    print("Run-Time Error")
    exit(0)


cnt_input = int(input().rstrip("\n"))
list_input = [input() for _ in range(cnt_input)]


cnt_output = int(input().rstrip("\n"))
list_output = [input() for _ in range(cnt_input)]

if cnt_input != cnt_output:
    print("Wrong Answer")
elif list_input == list_output:
    print("Correct")
else:
    print("Wrong Answer")






