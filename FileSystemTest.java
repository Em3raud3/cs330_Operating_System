import java.nio.file.FileSystem;

/**
 * Exercises the FAT file system
 * 
 * @author Jonathan Thompson
 * @version 09-Nov-2015
 */
public class FileSystemTest {
   public static void main(String[] args) {
      FileSystem myFileSystem = new FileSystem();
      // Create file 1 and write string of 25 characters
      int myFile1 = myFileSystem.createFile("test1", false);
      int writeStatus1 = myFileSystem.writeFile(myFile1, "This is the first phrase.");
      // Create file 2 and write string of 45 characters
      int myFile2 = myFileSystem.createFile("test2", false);
      int writeStatus2 = myFileSystem.writeFile(myFile2, "Goodbye, cruel World! I can take it no more!!");
      // Read and display file 1
      if (writeStatus1 == 1)
         System.out.println(myFileSystem.readFile(myFile1));
      else
         System.out.println("Write failed");
      // Read and display file 2
      if (writeStatus2 == 1)
         System.out.println(myFileSystem.readFile(myFile2));
      else
         System.out.println("Write failed file 2");
      // Delete file 1
      int test1Delete = myFileSystem.deleteFile("test1");
      // Create file 3 and write string of 35 characters
      int myFile3 = myFileSystem.createFile("test3", false);
      int writeStatus3 = myFileSystem.writeFile(myFile3, "No! Wait!! I'm feeling better now!");
      // Read and display file 3
      if (writeStatus3 == 1)
         System.out.println(myFileSystem.readFile(myFile3));
      else
         System.out.println("Write failed file 3");
      // Delete file 2
      int test2Delete = myFileSystem.deleteFile("test2");
      // Create file 4 and write string of 18 characters
      int myFile4 = myFileSystem.createFile("test4", false);
      int writeStatus4 = myFileSystem.writeFile(myFile4, "Eighteen chars!!!!");
      // Read and display file 4
      if (writeStatus4 == 1)
         System.out.println(myFileSystem.readFile(myFile4));
      else
         System.out.println("Write failed file 4");
      // Create file 5 and write a string of 55 characters
      // This test should fail
      int myFile5 = myFileSystem.createFile("test5", false);
      int writeStatus5 = myFileSystem.writeFile(myFile5, "This is a very long string that is 55 characters long..");
      // Read and display file 5
      if (writeStatus5 == 1)
         System.out.println(myFileSystem.readFile(myFile5));
      else
         System.out.println("Write failed file 5");
      // Create file 6 and write a string of 32 characters
      int myFile6 = myFileSystem.createFile("test6", false);
      int writeStatus6 = myFileSystem.writeFile(myFile6, "We need a string with length 32.");
      // Read and display file 6
      if (writeStatus6 == 1)
         System.out.println(myFileSystem.readFile(myFile6));
      else
         System.out.println("Write failed file 6");
   }
}