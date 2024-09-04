void = "00 "
ceiling = "01 "
floor = "02 "
platformL = "03 "
platformM = "04 "
platformR = "05 "
wallTL = "06 "
wallML = "07 "
wallBL = "08 "
wallTR = "09 "
wallMR = "10 "
wallBR = "11 "
blank = "-1 "

textArr = [1*(void*3 + wallML + void*52 + wallMR + void*3 + "\n"),
    1*(void*3 + wallML + ceiling*52 + wallMR + void*3 + "\n"),
    12*(void*3 + wallML + blank*52 + wallMR + void*3 + "\n"),
    1*(void*3 + wallML + blank*52 + wallBR + ceiling*3 + "\n"),
    2*(void*3 + wallML + blank*56 + "\n"),
    1*(void*3 + wallML + blank*52 + wallTR + floor*3 + "\n"),
    2*(void*3 + wallML + blank*52 + wallMR + void*3 + "\n"),
    1*(void*3 + wallML + blank*52 + wallBR + ceiling*3 + "\n"),
    2*(void*3 + wallML + blank*56 + "\n"),
    1*(ceiling*3 + wallBL + blank*56 + "\n"),
    6*(blank*60 + "\n"),
    1*(floor*60 + "\n"),
    3*(void*60 + "\n")]

textBuilder = ""

for line in textArr:
    textBuilder += line


f = open("output.txt", "w")
f.write(textBuilder)
f.close()
