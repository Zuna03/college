
import myPackage.myPackage.myClass;

public class PrintName {
    public static void main(String args[]) 
   {       
      // Initializing the String variable 
      // with a value 
      String name = "GeeksforGeeks";
      
      // Creating an instance of class MyClass in 
      // the package.
      myClass obj = new myClass();
      
      obj.getNames(name);
   }
}
