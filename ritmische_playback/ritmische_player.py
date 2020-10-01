#/mnt/c/users/ninos/documents/csd2/ritmische_player
import os
import simpleaudio as sa
import time as t


trig = 0

numPlaybackTimes = int(input("Hoeveel keer spelen we de sample af?:"))

interval = [0]*numPlaybackTimes

for i in range(0,numPlaybackTimes):
    interval[i] = float(input("interval:"))

bpm = int(input("Wat is het bpm?:"))
multi = 60/bpm

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