i=input()
print(i[0] == 'p' and all(j=='q' for j in i[1:]))
