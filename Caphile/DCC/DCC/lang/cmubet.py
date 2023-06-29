import utils as u

fp, fn = u.filePaths(u.txt)
for p, n in zip(fp, fn): 
    text = u.readFile(p, n, u.txt)

    words = {}
    for line in text:
        sep = line.split()
        word = sep[0]
        sign = ' '.join(sep[1 : ])

        words[word] = sign
        
    sen1 = 'They jump over the fence'
    sen2 = 'The sun gently warmed the soft green grass in the peaceful meadow'

    sign_sen1 = [words[w] for w in sen1.upper().split() if w in words]
    sign_sen2 = [words[w] for w in sen2.upper().split() if w in words]

    print(sen1)
    print(' '.join(sign_sen1))
    print(sen2)
    print(' '.join(sign_sen2))