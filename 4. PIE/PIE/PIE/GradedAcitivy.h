///**********************************************************************************
/// Description: Given graded Activity
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: Feb. 28, 2019
/// Status : Complete 
///***********************************************************************************

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

// GradedActivity class declaration

class GradedActivity {
private:
    double score;   // To hold the numeric score
public:
    // Default constructor
    GradedActivity() {
        score = 0.0;
    }

    // Constructor
    GradedActivity(double s) {
        score = s;
    }

    // Mutator function
    void setScore(double s) {
        score = s;
    }

    // Accessor functions
    double getScore() const {
        return score;
    }

    char getLetterGrade() const;
};
#endif 