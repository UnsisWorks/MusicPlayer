import io
import os
import time
def main():
    sounds = os.listdir("./sound")
    
    
    data = open("data.txt", "w")
    i = 0
    for sound in sounds:
        if(sound[-4:] == '.mp3'):
            data.write(sound + "\n")
            i += 1
        else:
            print(f" no: {sound}")
    data.close()
    
if __name__ == '__main__':
    main()