# /mnt/c/users/ninos/documents/csd2/ritmische_player
import os
import simpleaudio as sa
import time as t
import math as math
from threading import Thread
import random as rand
import midiutil as midi
from midiutil import MIDIFile

trig = 0
Bk = rand.randrange(4, 20)
Nk = rand.randrange(2, Bk)

Bs = rand.randrange(4, 20)
Ns = rand.randrange(2, Bs)

Bc = rand.randrange(4, 20)
Nc = rand.randrange(2, Bc)

Pk = 60
Ps = 61
Pc = 63

bpm = 127

numPlaybackTimes = 0
writemidi = 0


def write():
    global output_file
    global writemidi
    global numPlaybackTimes
    global midifile
    writemidi = 1
    tempo = bpm
    midifile = MIDIFile(1)
    midifile.addTempo(0, 0, tempo)
    t.sleep(numPlaybackTimes)
    with open("media/Sequence.mid", "wb") as output_file:
        midifile.writeFile(output_file)
    writemidi = 0


def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        pass


def ui_command():
    global inp
    global bpm
    global Bk
    global Nk
    global Bs
    global Ns
    global Bc
    global Nc
    global numPlaybackTimes
    inp = input(">")
    if inp[:4] == "play":
        if is_number(inp[5:10]):
            numPlaybackTimes = int(inp[5:10])
        else:
            print("play needs to be an integer value")

    elif inp[:4] == "info":
        info()

    elif inp[:5] == "write":
        if is_number(inp[5:10]):
            numPlaybackTimes = int((inp[5:10]))
            write()
        else:
            print("amount needs to be an integer value")

    elif inp[:3] == "bpm":
        if is_number(inp[4:8]):
            bpm = int(inp[4:8])
        else:
            print("bpm needs to be an integer value")

    elif inp[:2] == "Bk":
        if is_number(inp[3:8]):
            if int(inp[3:8]) >= Nk:
                Bk = int(inp[3:8])
            else:
                print("Bk needs to be more than Nk =", Nk)
        else:
            print("Bk needs to be an integer value")

    elif inp[:2] == "Nk":
        if is_number(inp[3:8]):
            if int(inp[3:8]) <= Bk:
                Nk = int(inp[3:8])
            else:
                print("Nk needs to be less than Bk =", Bk)
        else:
            print("Nk needs to be an integer value")


    elif inp[:2] == "Bs":
        if is_number(inp[3:8]):
            if int(inp[3:8]) >= Ns:
                Bs = int(inp[3:8])
            else:
                print("Bs needs to be more than Ns =", Ns)
        else:
            print("Bksneeds to be an integer value")



    elif inp[:2] == "Ns":
        if is_number(inp[3:8]):
            if int(inp[3:8]) <= Bs:
                Ns = int(inp[3:8])
            else:
                print("Ns needs to be less than Bs =", Bs)
        else:
            print("Ns needs to be an integer value")


    elif inp[:2] == "Bc":
        if is_number(inp[3:8]):
            if int(inp[3:8]) >= Nc:
                Bc = int(inp[3:8])
            else:
                print("Bc needs to be more than Nc =", Nc)
        else:
            print("Bc needs to be an integer value")


    elif inp[:2] == "Nc":
        if is_number(inp[3:8]):
            if int(inp[3:8]) <= Bc:
                Nc = int(inp[3:8])
            else:
                print("Nc needs to be less than Bc =", Bc)
        else:
            print("Nc needs to be an integer value")


    else:
        print("syntax error")


def euclidianGen(B, N):
    remainder = B % N
    inter = int(B / N)
    if remainder > 0:
        r = [inter] * N + [remainder]
    else:
        r = [inter] * N
    return r


intervalk = euclidianGen(Bk, Nk)
intervals = euclidianGen(Bs, Ns)
intervalc = euclidianGen(Bc, Nc)


def info():
    print("het  bpm is:", bpm)

    print("Euclidian waardes van de kick zijn:")
    print("Beats(Bk):", Bk)
    print("Aantal(Nk):", Nk)
    print(intervalk)
    print("Euclidian waardes van de snare zijn:")
    print("Beats(Bs):", Bs)
    print("Aantal(Ns):", Ns)
    print(intervals)
    print("Euclidian waardes van de clap zijn:")
    print("Beats(Bc):", Bc)
    print("Aantal(Nc):", Nc)
    print(intervalc)


info()

kick = sa.WaveObject.from_wave_file(os.path.join(".", "Kick.wav"))
snare = sa.WaveObject.from_wave_file(os.path.join(".", "Snare.wav"))
clap = sa.WaveObject.from_wave_file(os.path.join(".", "Clap.wav"))


def play():
    start = t.time()
    trigk = 0
    trigs = 0
    trigc = 0
    i = 0
    global numPlaybackTimes
    while numPlaybackTimes >= 0:
        numPlaybackTimes = numPlaybackTimes - 1
        i = i + 1
        multi = 60 / (bpm)
        trig = 0
        intervalk = euclidianGen(Bk, Nk)
        intervals = euclidianGen(Bs, Ns)
        intervalc = euclidianGen(Bc, Nc)
        while trig == 0:

            if (t.time() - start) > trigk:
                kick.play()
                trig = 1
                trigk = trigk + intervalk[i % len(intervalk)] * multi
                if writemidi == 1:
                    midifile.addNote(0, 0, int(Pk), int(trigk), int(intervalk[i % len(intervalk)]), 100)
                    print(int(Pk),int(trigk),int(intervalk[i % len(intervalk)]))

            if (t.time() - start) > trigs:
                snare.play()
                trig = 1
                trigs = trigs + intervals[i % len(intervals)] * multi
                if writemidi == 1:
                     midifile.addNote(0, 0, int(Ps), int(trigs), int(intervals[i % len(intervals)]), 100)
                     print(int(Ps),int(trigs),int(intervals[i % len(intervals)]))

            if (t.time() - start) > trigc:
                clap.play()
                trig = 1
                trigc = trigc + intervalc[i % len(intervalc)] * multi
                if writemidi == 1:
                     midifile.addNote(0, 0, int(Pc), int(trigc), int(intervalc[i % len(intervalc)]), 100)
                     print(int(Pc), int(trigc), int(intervalc[i % len(intervalc)]))


            else:
                t.sleep(0.1)
                trig = 0
    t.sleep(0.5)
    play()


def ui_thread():
    while True:
        ui_command()


thr1 = Thread(target=ui_thread)
thr1.start()

thr2 = Thread(target=play)
thr2.start()
