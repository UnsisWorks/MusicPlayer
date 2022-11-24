import io
import os
import time
def main():
    sounds = os.listdir("./sound")
    print(sounds)
    
    data = open("data.txt", "w")
    
    for sound in sounds:
        data.write(sound + "\n")
    
    data.close()
    
    time.sleep(1)
    
if __name__ == '__main__':
    main()