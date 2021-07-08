This program will take the number of files to be compared, name of different files to be compared and the path of these files (between
which plagiarism is to be compared) as commandline arguments. 

Suppose you are saving your C code in the file 'Plagiarism_Detector.c', the executable is 'a.out', the number of files to be compared is 
'5' and these 5 files are 'Test_1.c', 'Test_2.c', 'Test_3.c', 'Test_4.c', 'Test_5.c', then the command to be executed in the terminal will 
be -- 
    "./a.out 5 Test_1.c Test_2.c Test_3.c Test_4.c Test_5.c", 
    
and for N files it's --
    "./a.out N file_1 file_2 file_3  …………………………. file_N".
        where  N = number of files to be checked,
            and file_1,  file_2,  .... , file_N are the names of the respective files(with extensions).
    
The constraints which should be kept in find regarding Test files are:
    ->  Maximum number of characters in file_name including extension is 100.
    ->  Maximum number of characters in a particular line of a code is 1000.

The output of the program is like:

    File_name   File_name   Percentage Plagiarism
    
     file_1.c   file_5.c        88.96 %
     file_4.c   file_9.c        80.56 %
      …...       …….             …….
      …..        …….             …….
      …...       …….             …….
      …..        …….             …….

        Average plagiarism = 82%