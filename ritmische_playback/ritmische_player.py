#/mnt/c/users/ninos/documents/csd2/ritmische_player
import os
import simpleaudio as sa
import time as t


trig = 0

numPlaybackTimes = int(input("Hoeveel keer spelen we de sample af?:"))

interval = [0]*numPlaybackTimes

for i in range(0,numPlaybackTimes):
    interval[i] = int(input("interval:"))

bpm = int(input("Wat is het bpm?:"))
multi = 60/(bpm*4)

clap = sa.WaveObject.from_wave_file(os.path.join(".","Clap.wav"))
#wave_obj = sa.WaveObject.from_wave_file(os.path.join(".","Clap.wav"))
#wave_obj = sa.WaveObject.from_wave_file(os.path.join(".","Clap.wav"))

s = t.time()
for i in range(0,numPlaybackTimes):
    while (t.time() - s) < trig:
        t.sleep(0.01)
    clap.play()
    trig = trig + interval[i]*multi
    #t.sleep(interval[i]*multi)
t.sleep(1)