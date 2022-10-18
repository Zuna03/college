class que3 {

    public  void  checkleap(int year){
        boolean leap = false;

        if (year % 4 == 0) 
      {
        if (year % 100 == 0) 
        {        
          if (year % 400 == 0)
            leap = true;
          else
            leap = false;
        }
        else
          leap = true;
      }
      else
        leap = false;
  
      if (leap)
        System.out.println(year + " is a leap year.");
      else
        System.out.println(year + " is not a leap year.");
    }
    public static void main(String[] args) {
     que3 T1= new que3();
     T1.checkleap(2022);
    }
  }