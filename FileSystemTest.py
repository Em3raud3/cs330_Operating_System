#! Ran on Python 3.8.10

class FileSystem:
    def __init__(self):
        self.file = list()

    def createFile(self, inFilename, readOnly):
        if len(self.file) >= 10:
            return -1  # ! File system is full
        self.file.append([inFilename, readOnly])

    def deleteFile(self, inFilename):
        prelen = len(self.file)
        #! Remove all files with the same name
        self.file = [x for x in self.file if x[0] != inFilename]
        postlen = len(self.file)

        #! Used length of the list to check if the file was deleted
        if prelen == postlen:
            return 0

        else:
            return 1

    def readFile(self, inFilename):

        for i in self.file:
            if i[0] == inFilename:
                print(i[1], end='')  # ! prints the message without newline


def main():
    fs = FileSystem()
    fs.createFile("file1", False)
    fs.createFile("file2", False)
    fs.createFile("file3", False)


if __name__ == "__main__":
    main()
