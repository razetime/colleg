import re
i=input()+" "
print(list(a for a,b in re.findall(re.compile("(([A-Za-z]+_)+[A-Za-z]+)"),i)))
