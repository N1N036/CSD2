#/mnt/c/users/ninos/documents/csd2/python_basics
import os
import simpleaudio as sa
import time as t


wave_obj = sa.WaveObject.from_wave_file(os.path.join(".","Clap.wav"))


#print("Hoeveel keer wil je de clap afspelen?")

x =int(input("Hoeveel keer wil je de clap afspelen?:"))


for i in range(0,x):
    play_obj = wave_obj.play()
    play_obj.wait_done()


