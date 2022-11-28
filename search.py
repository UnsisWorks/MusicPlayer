import io
import os
import time
def main():
    sounds = os.listdir("./sound")
    print(sounds)
    
    data = open("data.txt", "w")
    
    for sound in sounds:
        if(sound[-4:] == '.wav'):
            data.write(sound + "\n")
        else:
            print(f" no: {sound}")
    data.close()
    
    time.sleep(1)
    
if __name__ == '__main__':
    main()