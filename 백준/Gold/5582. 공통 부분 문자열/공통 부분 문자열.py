from difflib import SequenceMatcher

str1 = input()
str2 = input()

match = SequenceMatcher(None,str1,str2,autojunk=False).find_longest_match(0,len(str1),0,len(str2))
# print(str1[match.a:match.a+match.size])
print(match.size)