import filecmp
import os
import sys
import time


def init():
    path = os.path.abspath('.')

    cpp = int(input("Use cpp maker ( 1 -> YES , 0 -> NO) :"))
    if cpp:
        name = input("Please input the file in 'cpp' dir name :")
        Check_Make_Path(path + '\\make\\cpp\\' + name + ".cpp")
    else:
        name = input("Please input the file in 'python' dir name :")
        Check_Make_Path(path + '\\make\\python\\' + name + ".py")

    tim = 1000000
    spj = int(input("Enable special judge ( 1 -> YES , 0 -> NO) :"))
    switch = int(input("Enable timelimites ( 1 -> YES , 0 -> NO) :"))
    if switch:
        tim = float(input("Please input the timelimits for the app (ms):")) / 1000
    # print (path)
    return spj, name, tim, path, switch, cpp


def Check_Make_Path(path):
    if os.path.isfile(path):
        # return 1
        pass
    else:
        print("No file")
        exit()
        # return 0


def compile_():
    os.system(".\\MinGW64\\bin\\g++ .\\pre\\code_1.cpp -o  .\\pre\\code_1.exe")
    os.system(".\\MinGW64\\bin\\g++ .\\pre\\code_2.cpp -o .\\pre\\code_2.exe")
    if spj:
        os.system(".\\MinGW64\\bin\\g++ .\\spj\\%s -o .\\spj\\%s" %
                  (spjname + '.cpp', spjname + '.exe'))
    if cpp:
        os.system(".\\MinGW64\\bin\\g++ .\\make\\cpp\\%s -o .\\make\\cpp\\%s" %
                  (name + '.cpp', name + '.exe'))


def merge():
    filepath = os.path.abspath('.')
    fileout1 = open('.\\file\\spjin_1.out', 'w')
    fileout2 = open('.\\file\\spjin_2.out', 'w')
    for l in open(filepath + '\\file\\tmp.in'):
        fileout1.writelines(l)
        fileout2.writelines(l)
    for l in open(filepath + '\\file\\code_1.out'):
        fileout1.writelines(l)
    for l in open(filepath + '\\file\\code_2.out'):
        fileout2.writelines(l)
    fileout1.close()
    fileout2.close()


def compair(st):
    if st:
        merge()
        os.system(".\\spj\\%s < .\\file\\spjin_1.out > .\\file\\spj1.out" %
                  (spjname + '.exe'))
        os.system(".\\spj\\%s < .\\file\\spjin_2.out > .\\file\\spj2.out" %
                  (spjname + '.exe'))
        return filecmp.cmp(".\\file\\spj1.out", ".\\file\\spj2.out")
    else:
        return filecmp.cmp(".\\file\\code_1.out", ".\\file\\code_2.out")


#--------------------------------------------------------------#
spj, name, tim, path, switch, cpp = init()
spjname = 0


if spj:
    spjname = input("Please input the file in 'spj' dir name :")
    Check_Make_Path(path + '\\spj\\' + spjname + '.cpp')


cnt = 0
mx = 1000


compile_()


print("Test start :")


while cnt < mx:
    if cpp:
        os.system(".\\make\\cpp\\%s > .\\file\\tmp.in" %
                  (name + '.exe'))
    else:
        os.system(".\\Python\\python.exe %s > .\\file\\tmp.in" %
                  ('.\\make\\python\\' + name + ".py"))
    if switch:
        Time_A = time.time()
    os.system(".\\pre\\code_1.exe < .\\file\\tmp.in > .\\file\\code_1.out")
    if switch:
        Time_B = time.time()
    os.system(".\\pre\\code_2.exe < .\\file\\tmp.in > .\\file\\code_2.out")
    if switch:
        Time_C = time.time()
    cnt = cnt + 1

    print("The %d \\ %d group" % (cnt, mx))
    if switch:
        A = Time_B-Time_A
        B = Time_C-Time_B
        if A > tim or B > tim:
            print("TLE")
            print("Time for code_1 : %f " % A)
            print("Time for code_2 : %f " % B)
            break

    if compair(spj):
        print("AC")
    else:
        print("WA")
        break
    if not switch:
        print('')
    # print (Time_A)
    # print (Time_B)
    # print (Time_C)
    if switch:
        print("Time for code_1 : %f " % A)
        print("Time for code_2 : %f \n" % B)


if cnt == mx:
    print("You pass the test , but check out carefully !")
else:
    print("G G !")
