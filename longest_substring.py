s = "abcabcdefgh"
leftIndex = 0
rightIndex = 0
record = 0
substr = ""
while rightIndex < len(s):
    if s[rightIndex] in substr:
        leftIndex += 1
    else:
        rightIndex += 1
    substr = s[leftIndex:rightIndex]
    if len(substr) > record:
        record = len(substr)
print(record)