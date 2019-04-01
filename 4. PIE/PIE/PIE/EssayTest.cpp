///**********************************************************************************
/// Description: Essay Test
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 8, 2019
/// Status : Complete 
///***********************************************************************************
#include "Essay.h"
#include <iostream>
#include <sstream>
#include <string>



int main() {
    double tempScore;
    std::string input;
    std::stringstream ss;
    Essay essay;
    
    
    std::cout << "How many grammer points did the student earn ? (0 - 30) : ";
    getline(std::cin, input);
    ss << input;
    ss >> tempScore;
    essay.setGrammarScore(tempScore);
    ss.clear();

    std::cout << std::endl << "How many spelling points did the student earn ? (0 - 20) : ";
    getline(std::cin, input);
    ss << input;
    ss >> tempScore;
    essay.setSpellingScore(tempScore);
    ss.clear();

    std::cout << std::endl << "How many points for length did the student earn ? (0 - 20) :";
    getline(std::cin, input);
    ss << input;
    ss >> tempScore;
    essay.setCorrectLengthScore(tempScore);
    ss.clear();

    std::cout << std::endl << "How many points for content did the student earn ? (0 - 30) :";
    getline(std::cin, input);
    ss << input;
    ss >> tempScore;
    essay.setContentScore(tempScore);
    ss.clear();

    std::cout << "Grammer point: " << essay.getGrammar() << std::endl;
    std::cout << "Spelling point: " << essay.getSpelling() << std::endl;
    std::cout << "Length point: " << essay.getCorrectLength() << std::endl;
    std::cout << "Content point: " << essay.getContent() << std::endl;
    std::cout << "#Overall Score: " << essay.getFinalGrade().getScore() << std::endl;
    std::cout << "Grade: " << essay.getFinalGrade().getLetterGrade() << std::endl;

    std::cout << std::endl << "g85(85): " << std::endl;
    Essay g85(85);
    std::cout << "Graded Score: " << g85.getFinalGrade().getScore() << ", Grade: " << g85.getFinalGrade().getLetterGrade() << std::endl;

    Essay report85(25, 20, 20, 20);
    std::cout << std::endl << "report85(25, 20, 20, 20):" << std::endl;
    std::cout << "Grammer point: " << report85.getGrammar() << std::endl;
    std::cout << "Spelling point: " << report85.getSpelling() << std::endl;
    std::cout << "Length point: " << report85.getCorrectLength() << std::endl;
    std::cout << "Content point: " << report85.getContent() << std::endl;
    std::cout << "Graded Score: " << report85.getFinalGrade().getScore() << ", Grade: " << report85.getFinalGrade().getLetterGrade() << std::endl;


    Essay g65(65);
    std::cout << std::endl << "g65(65):" << std::endl;
    std::cout << "Graded Score: " << g65.getFinalGrade().getScore() << ", Grade: " << g65.getFinalGrade().getLetterGrade() << std::endl;

    Essay report65(15, 10, 20, 20);
    std::cout << "Grammer point: " << report65.getGrammar() << std::endl;
    std::cout << "Spelling point: " << report65.getSpelling() << std::endl;
    std::cout << "Length point: " << report65.getCorrectLength() << std::endl;
    std::cout << "Content point: " << report65.getContent() << std::endl;
    std::cout << "Graded Score: " << report65.getFinalGrade().getScore() << ", Grade: " << report65.getFinalGrade().getLetterGrade() << std::endl;





    return 0;
}