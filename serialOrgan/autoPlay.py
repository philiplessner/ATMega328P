## Scripting in python to drive the serial-port organ

## So far, the "protocol" is simple.  
## Python routine sends a note, waits for a return character, then sends next, etc.
## Organ listens for notes, when it gets one sends an 'N' to say it's ready
 
import serial

def playString(noteString, serialPort):
  for letter in noteString:
    print(letter)
    serialPort.write(letter.encode())
    returnValue = serialPort.read(1)
    
if __name__ == "__main__":

  import time
  from urllib.request import urlopen

  ## Need to consider alternatives for Mac / Windows
  ## list all serial ports being used: python -m serial.tools.list_ports
  PORT = "/dev/ttyUSB1" # Change this to the current serial port being used
  BAUD = 19200

  s = serial.Serial(PORT, BAUD)
  s.flush()                     
  ## flush clears the buffer so that we're starting fresh
  ## More on serial buffers later.

  ## An intentional example.  You can use this for playing music on purpose.
  playString("f g h j k l ; ]'[", s)
  input("Press enter for next demo\n")

  ## A fun / stupid example.  You can just type stuff and see what comes out.
  playString("hello there, this is a random string turned into 'music'", s)
  input("Press enter for next demo\n")

  ## Website no longer alive... skipping:
  ## A really frivolous example.  Play websites!
  ## Bonus points for first person to tweet themselves a song.
  #print ("Downloading song data from http://serialorgansongs.jottit.com/...")
  #import re
  #contentFilter = re.compile(r'<p>(.*?)</p>')
  #songSite = urlopen("http://serialorgansongs.jottit.com/").read()
  #songText = contentFilter.findall(songSite)[0]
  #playString(songText, s)
 
  ## Or interactive
  mySong = input("\nType in your own song: ")
  playString(mySong, s)
