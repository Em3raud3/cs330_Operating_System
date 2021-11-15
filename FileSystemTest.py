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
        prelen = len(self.file)
        #! Remove all files with the same name
        self.file = [x for x in self.file if x[0] != inFilename]
        postlen = len(self.file)

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

        for i, j in enumerate(self.file):
            if j:
                if j[0] == inFilename and j[1] == False:
                    if self.file.count([]) + 1 - message_block > 10:
                        return print(0)  # ! File system is full

                if len(inMessage) <= 10:
                    self.file[i][2] = inMessage
                    return print(1)

                else:
                    #! split strings into blocks of 10
                    string_split = [inMessage[y-10:y]
                                    for y in range(10, len(inMessage)+10, 10)]

                    # ! remove item as they are used
                    self.file[i][2] = string_split.pop(0)

                    for i, j in enumerate(self.file):
                        if not j:
                            self.file[i] = [inFilename,
                                            False,
                                            string_split.pop(0)]

                            if not string_split:
                                break


def main():
    fs = FileSystem()
    fs.createFile("file1", False)
    fs.writefile("file1", "This is the first phrase.")

    # fs.createFile("file2", False)
    # fs.writefile("file2", "Goodbye, cruel World! I can take it no more!!")

    # fs.readFile("file1")


if __name__ == "__main__":
    main()
