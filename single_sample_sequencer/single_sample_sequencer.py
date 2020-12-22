#/mnt/c/users/ninos/documents/csd2/ritmische_player
import os
import simpleaudio as sa
import time as t

def durationsToTimestamps16th(noteDurations):
    global timestamps16th
    timestamps16th = len(noteDurations)*[0]
    for i in range (0, (len(noteDurations))):
        timestamps16th[i] = timestamps16th[i-1]+noteDurations[i]*4
    timestamps16th.insert(0,0)
    del timestamps16th[-1]

def timestamps16thToTimestamps(bpm):
        "HIER MOET JE NOG AAN WERKEN LULLO"


trig = 0


print("het standaard bpm is: 127")
bpm = 127
bpm = input("Wil je een ander bpm?:")
if not isinstance(bpm, int):
    bpm = 127
print(bpm)
multi = 60/bpm

noteDurations = [0.25, 0.5, 0.25, 0.5, 0.5, 1, 1]
durationsToTimestamps16th(noteDurations)
print(noteDurations)


print(timestamps16th)

clap = sa.WaveObject.from_wave_file(os.path.join(".","Clap.wav"))
#wave_obj = sa.WaveObject.from_wave_file(os.path.join(".","Clap.wav"))
#wave_obj = sa.WaveObject.from_wave_file(os.path.join(".","Clap.wav"))

start = t.time()
for i in range(0,numPlaybackTimes):
    while (t.time() - start) < trig:
        t.sleep(0.01)
    print(t.time() - start)
    clap.play()
    trig = trig + interval[i]*multi
    print(interval[i])
    print(trig)
t.sleep(1)