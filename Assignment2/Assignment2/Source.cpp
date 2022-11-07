//
//  created by Ahmad Hassan | i210403  on 30/10/22
//

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "Header.h"
using namespace std;




int main()
{
    fstream file;
    file.open("Assignment2_Materials/Output_files/Result-1.txt", ios::out);
    file << "";
    string str = "Assignment2_Materials/Test_files/Test-1.txt";

    string str5 = "Assignment2_Materials/Test_files/Test-5.txt";
    string str3 = "Assignment2_Materials/Test_files/Test-3.txt";
    string str4 = "Assignment2_Materials/Test_files/Test-4.txt";
    string str6 = "Assignment2_Materials/Test_files/Test-6.txt";
    string str2 = "Assignment2_Materials/Test_files/Test-2.txt";
    string str7_2 = "Assignment2_Materials/Test_files/Test-7.txt";
    string str7 = "Assignment2_Materials/AdditionalTests/Test-7.txt";
    string str8 = "Assignment2_Materials/AdditionalTests/Test-8.txt";
    parseFile(str);
    parseFile(str2);
    parseFile(str3);
    parseFile(str4);
    parseFile(str5);
    parseFile(str7_2);
    parseFile(str6);
    parseFile(str7);
    parseFile(str8);
    return 0;
}