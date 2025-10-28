tekst = 'abcabcabdaabdd'
wzorzec = 'abcabd'

n = len(tekst)
m = len(wzorzec)
ps = [0, 0, 0, 1, 2, 0]
#pd = [0, 0, 0, 1] # out of bounds

i = 0
j = 0

while i < n: # - m + 1, just cause it doesnt have to shorten it
    if tekst[i] == wzorzec[j]:
        j += 1
        i += 1
    else:
        if j!= 0: # if j = 0 it would have done j = ps[-1] -> out of bounds
            j = ps[j - 1]
        else: # if the word and pat doesn't match, it has to go further
            i += 1
    
    if j == m:
        print("WZORZEC ZNALEZIONY: ", (i-j))
        j = ps[j - 1]

