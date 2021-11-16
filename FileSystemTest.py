#! Ran on Python 3.8.10
import math


class FileSystem:
    def __init__(self):
        self.file = [[] for i in range(10)]

    def createFile(self, inFilename: str, readOnly: bool):
        if self.file.count([]) == 0:
            return -1  # ! File system is full

        for i, j in enumerate(self.file):
            if not j:
                self.file[i] = [inFilename, readOnly, ""]
                break
        print(inFilename)

    def deleteFile(self, inFilename: str):
        begin_count = self.file.count([])
        
        for i,j in enumerate(self.file):
            if j:
                if j[0] == inFilename:
                    self.file[i] = []
                
     
        
        end_count = self.file.count([])
        
        if begin_count == end_count:
            return print(0) #! File does not exist
        
        return print(1) #! File deleted successfully
        
   
        #! Remove all files with the same name
        self.file = [x for x in self.file if x[0] != inFilename]
    

        #! Used length of the list to check if the file was deleted
        if prelen == postlen:
            return 0

        return 1

    def readFile(self, inFilename):

        for i in self.file:
            if i:
                if i[0] == inFilename:
                    print(i[2], end='')  # ! prints the message without newline
        print()

    def writefile(self, inFilename, inMessage):
        # ! Number of blocks needed for message
        message_block = math.ceil(len(inMessage) / 10)
        

        
        if not [inFilename, False, ""] in self.file:
            return print(0)  # ! File is read only or does not exist 
        
        index_of_head = self.file.index([inFilename, False, ""])
        
        if self.file.count([]) + 1 - message_block < 0:
            self.file[index_of_head] = []
            return print(0)  # ! File system is full
        
        #! split strings into blocks of 10
        string_split = [inMessage[y-10:y] for y in range(10, len(inMessage)+10, 10)]

        #! insert the blocks into the file system
        self.file[index_of_head][2] = string_split.pop(0)
        
        while string_split:
            empty_index = self.file.index([])
            self.file[empty_index] = [inFilename, False, string_split.pop(0)]
        
        print(1)

def main():
    fs = FileSystem()
    
    fs.createFile("file1", False)
    fs.writefile("file1", "This is the first phrase.")
    
    fs.createFile("file2", False)
    fs.writefile("file2", "Goodbye, cruel World! I can take it no more!!")
    
    fs.readFile("file1")
    fs.readFile("file2")
    
    fs.deleteFile("file1")
    
    fs.createFile("file3", False)
    fs.writefile("file3", "No! Wait!! I'm feeling better now!")
    fs.readFile("file3")
    
    fs.deleteFile("file2")
    
    fs.createFile("file4", False)
    fs.writefile("file4", "Eighteen chars!!!!")
    fs.readFile("file4")
    
    #! This should fail due to lack of space    
    fs.createFile("file5", False)
    fs.writefile("file5", "This is a very long string that is 55 characters long..")
    
    fs.createFile("file6", False)
    fs.writefile("file6", "We need a string with length 32.")
    fs.readFile("file6")

if __name__ == "__main__":
    main()
