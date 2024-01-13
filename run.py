import os
from time import sleep

i = 0
j = 0

while (i < 20 and j == 0):
	j = os.system("make re")
	sleep(1)
	i += 1