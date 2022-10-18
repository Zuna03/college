Q1

DECLARE
    SID STUDENT_201.STUDENTID%TYPE;
 PH STUDENT_201.PHONE%TYPE;
    NAME STUDENT_201.FIRST%TYPE;
CITE STUDENT_201.CITY%TYPE;
    BEGIN
    SID :=&SID;
     update student_201 set phone = 2766657654; 

SELECT FIRST,CITY,PHONE,STUDENTID INTO NAME,CITE,PH,SID FROM STUDENT_201 WHERE STUDENTID=SID;
   DBMS_OUTPUT.PUT('THE NAME IS '||NAME);
   DBMS_OUTPUT.NEW_LINE;
   DBMS_OUTPUT.PUT('THE PHONE NUMBER IS '||PH);
   DBMS_OUTPUT.NEW_LINE;
   DBMS_OUTPUT.PUT('THE CITY IS '||CITE);
   DBMS_OUTPUT.NEW_LINE;

   END;
  /

Enter value for sid: 00101
old   1:     SID :=&SID;
new   1:     SID :=00181;
THE NAME IS SHUBHDEEP
THE PHONE NUMBER IS 98800
THE CITY IS DELHI

PL/SQL procedure successfully completed.


Q2

DECLARE
    temp1     NUMBER := &input_a_temp;
    t_scale   CHAR := '&input_temp_scale';
    new_temp  NUMBER;
    new_scale CHAR;
i number;
  BEGIN
while(i <= 5)
loop
 	temp1   := &input_a_temp;
  	 t_scale := '&input_temp_scale';
    	IF t_scale != 'C' AND t_scale != 'F' THEN
      	dbms_output.Put_line ('The scale you input is not a valid scale');
      	new_temp := 0;
      	new_scale := 'C';
    	ELSE
     	 IF t_scale = 'C' THEN
       	 new_temp := ( ( 9 * temp1 ) / 5 ) + 32;
        new_scale := 'F';
      ELSE
        new_temp := ( ( temp1 - 32 ) * 5 ) / 9;
        new_scale := 'C';
      END IF;
    END IF;
    dbms_output.Put_line ('The new temperature in scale '
    ||new_scale
    ||' is: '
    ||new_temp);
i := i + 1;
end loop;
  END;
/

Enter value for input_a_temp: 32
old   2:     temp1     NUMBER := &input_a_temp;
new   2:     temp1     NUMBER := 32;
Enter value for input_temp_scale: C
old   3:     t_scale   CHAR := '&input_temp_scale';
new   3:     t_scale   CHAR := 'C';
Enter value for input_a_temp: 100
old  10:  temp1   := &input_a_temp;
new  10:  temp1   := 100;
Enter value for input_temp_scale: F
old  11:    t_scale := '&input_temp_scale';
new  11:    t_scale := 'F';

PL/SQL procedure successfully completed.
