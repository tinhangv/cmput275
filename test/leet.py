

strs = ["dog","racecar",""]

l = min([len(s) for s in strs])
print(l)
for i in range(l):
    if not all([(s[i]==strs[0][i]) for s in strs]):
        print(strs[0][:i])
        break
