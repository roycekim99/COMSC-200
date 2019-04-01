///**********************************************************************************
/// Description: Essay Class
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 28, 2019
/// Status : Complete 
///***********************************************************************************

#include "GradedAcitivy.h"
#pragma once


class Essay {
private:
    double grammar, spelling, contentLen, content;
    GradedActivity finalGrade;

public:
    Essay(double g = 0, double s = 0, double len = 0, double c = 0) {
        grammar = g;
        spelling = s;
        contentLen = len;
        content = c;
        //set final score
        finalGrade.setScore(grammar + spelling + contentLen + content);
    }

    void setGrammarScore(double p) {
        grammar = p;
        finalGrade.setScore(grammar + spelling + contentLen + content);

    }
    void setSpellingScore(double p) {
        spelling = p;
        finalGrade.setScore(grammar + spelling + contentLen + content);

    }
    void setCorrectLengthScore(double p) {
        contentLen = p;
        finalGrade.setScore(grammar + spelling + contentLen + content);

    }
    void setContentScore(double p) {
        content = p;
        finalGrade.setScore(grammar + spelling + contentLen + content);

    }

    double getGrammar() const{
        return grammar;
    }
    double getSpelling() const {
        return spelling;
    }
    double getCorrectLength() const {
        return contentLen;
    }
    double getContent() const {
        return content;
    }

    GradedActivity getFinalGrade() {
        return finalGrade;
    }
    
    //calculate final score


};