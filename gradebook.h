//Gradebook Class Header File

#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>
#include <string>




/*   ///( Assigned to: Sam )\\\\

    Taking care of documentation in code implementation on 
    GitHub Repository, Class function files, and necessary 
    comments in code

*/

class Gradebook{

    private:

    /*
        Necessary Vector(s) && Pairs: ///( Assigned to: Sam G and Grant )\\\\

            -> LAB_names
            -> LAB_grades
            -> ASSIGNMENT_names
            -> ASSIGNMENT_grades
            -> PROJ1-pair <string, int> == Name, Grade
            -> PROJ2-pair <string, int> == Name, Grade
            -> Exam-pair <string, int> == Name, Grade
    */
        std::vector<std::string> LAB_names;
        std::vector<std::string> LAB_grades;
        std::vector<std::string> ASSIGNMENT_names;
        std::vector<std::string> ASSIGNMENT_grades;
        std::pair<std::string, std::string> PROJ1;
        std::pair<std::string, std::string> PROJ2;
        std::pair<std::string, std::string> EXAM;

        std::vector<int> LAB_lowest_idx;

        int invalidNums;
        std::string fname;
        std::string student_name;
        std::string course_name;
        std::string course_overall = "N/A";

        bool valid_num(std::string num);
        int readFile(std::string file_name);
        void check_file_name(std::string* file_name);
        void find_lowest_idx();


    public:

    /*
        gradebook Class Functions

        default constructor  ///( Assigned to: Grant )\\\\ 
        constructor for Vetcors ///( Assigned to: Sam G )\\\\
        constructor for pairs ///( Assigned to: Sam G and Grant )\\\\
        void Menu ///( Assigned to: Sam )\\\\
            -> terminal command line args to specify menu board

            individual Grade 1 ///( Assigned to: Sam G and Grant )\\\\
                -> 1( "Lab" keyword name) " " 2( "Week#" for expected grade) ==> Labs
                -> 1( "Assignment" keyword name) " " 2("Assignment#" for expected grade) ==> Assignments
                -> 1( "Project1" keyword name)
                -> 1( "Project2"  keyword name)
                -> 1( "Exam" keyword name)

            category grade   2 ///( Assigned to: Sam )\\\\
                -> 1( "Projects" keyword name) ==> Overall Category Grade in Projects
                    -> Shows individual grades from "Projects"
                -> 1( "Labs" keyword name) ==> Overall Category Grade in Labs
                    -> Shows individual grades from "Labs"
                -> 1( "Assignments" keyword name) ==> Overall Category Grade in Assignments
                    -> Shows individual grades from "Assignments"
                -> 1( "Exam" keyword name) ==> Overall Category Grade in Exam
                    -> Shows individual grades from "Exam"

            All grades        3 ///( Assigned to: Sam )\\\\
                -> Condition1
                    ==> showing complete layout of all grades, category totals, and overalls
                -> Condition2
                    ==>ONLY the Category total and Course overall
                -> Condition3
                    ==> ONLY the Course Overall
        
        Reading the file ///( Assigned to: Claudia )\\\\
            -> string_stream that seperates keywords by '|' into certain vector or pair
            -> *** READ file name as command line argument ***

        Writing output ///( Assigned to: Sam G )\\\\
            -> Mandatory file check (incase if something is deleted, regardless or nothing is deleted)

        Helper Functions ( ^^^^ Used in above functions ^^^^ )
            -> checking for invalid grades ( num>100 or num < 0) ///( Assigned to: Claudia )\\\\
                -> Manual check to see if grade is with bounds
                    ==> if not, put "###" and demand for new grade in bounds 


            -> Find keyword from terminal for individual grade(string, int *index) of found keyword ///( Assigned to: Grant )\\\\


            -> If the file is not present in the directory ///( Assigned to: Claudia )\\\\
                -> *** Based on command line file name ***
        
    
    */
        Gradebook(std::string fname);
        
        double computeCategoryScores(int choice);
        double computeOverall();
        std::string getIndividualGrade(std::string weekNum, int choice);
        void allGradedAssignments();
        void writeFile(std::string file_name);
   
};


#endif