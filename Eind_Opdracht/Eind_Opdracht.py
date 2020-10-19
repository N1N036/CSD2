#/mnt/c/users/ninos/documents/csd2/ritmische_player
import os
import simpleaudio as sa
import time as t
import math as math
from threading import Thread
import random as rand



trig = 0
Bk = rand.randrange(4, 20)
Nk = rand.randrange(2, Bk)

Bs = rand.randrange(4, 20)
Ns = rand.randrange(2, Bs)

Bc = rand.randrange(4, 20)
Nc = rand.randrange(2, Bc)

numPlaybackTimes = 1000

print("het standaard bpm is: 127")
bpm = 127




def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        pass

def ui_command():
    global inp
    global bpm
    inp = input(">")
    if inp[:3] == "bpm":
        if is_number(inp[4:8]):
            bpm = int(inp[4:8])
        else:
            print("bpm needs to be an integer value")
    else:
        print("syntax error")


def euclidianGen(B, N):
    remainder = B % N
    inter = int(B/N)
    if remainder > 0:
        r = [inter]*N + [remainder]
    else:
        r = [inter] * N
    return r



intervalk = euclidianGen(Bk,Nk)
intervals = euclidianGen(Bs,Ns)
intervalc = euclidianGen(Bc,Nc)

print(intervalk)
print(intervals)
print(intervalc)





kick = sa.WaveObject.from_wave_file(os.path.join(".","Kick.wav"))
snare = sa.WaveObject.from_wave_file(os.path.join(".","Snare.wav"))
clap = sa.WaveObject.from_wave_file(os.path.join(".","Clap.wav"))




def play():
    start = t.time()
    trigk = 0
    trigs = 0
    trigc = 0
    for i in range(0,numPlaybackTimes):
        multi = 60 / (bpm)
        trig = 0
        while trig == 0:
            if (t.time() - start) > trigk:
                kick.play()
                trig = 1
                trigk = trigk + intervalk[i % len(intervalk)] * multi
            if (t.time() - start) > trigs:
                snare.play()
                trig = 1
                trigs = trigs + intervals[i % len(intervals)] * multi

            if (t.time() - start) > trigc:
                clap.play()
                trig = 1
                trigc = trigc + intervalc[i % len(intervalc)] * multi

            else:
                t.sleep(0.1)
                trig = 0

def ui_thread():
    while True:
        ui_command()






thr1 = Thread(target=ui_thread)
thr1.start()
thr2 = Thread(target=play)
thr2.run()

