/*
Suppose there are eight students and ten questions, and the answers are stored in a twodimensional
list. Each row records a student’s answers to the questions, as shown in the
following illustration

## Students’ Answers to the Questions

| Student   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|-----------|---|---|---|---|---|---|---|---|---|---|
| Student 0 | A | B | A | C | C | D | E | E | A | D |
| Student 1 | D | B | A | B | C | A | E | E | A | D |
| Student 2 | E | D | D | A | C | B | E | E | A | D |
| Student 3 | C | B | A | E | D | C | E | E | A | D |
| Student 4 | A | B | D | C | C | D | E | E | A | D |
| Student 5 | B | B | E | C | C | D | E | E | A | D |
| Student 6 | B | B | A | C | C | D | E | E | A | D |
| Student 7 | E | B | E | C | C | D | E | E | A | D |


The key is stored in a one-dimensional list:
### Key to the Questions

| Key   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|-------|---|---|---|---|---|---|---|---|---|---|
| Answer| D | B | D | C | C | D | A | E | A | D |

Write a program that grades the test and displays the result. To do this, the program compares each
student’s answers with the key, counts the number of correct answers, and displays it.
*/

#include <iostream>
using namespace std;

int main() {
    const int NUM_STUDENTS = 8;
    const int NUM_QUESTIONS = 10;

    // Students' answers, indexed as answers[student][question]
    char answers[NUM_STUDENTS][NUM_QUESTIONS] = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},  
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},  
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},  
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},  
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},  
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},  
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},  
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}   
    };

    // Key to the questions
    char keyToQuestions[NUM_QUESTIONS] =
        {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

    // Grade each student's answers
    for (int i = 0; i < NUM_STUDENTS; i++) {
        int correctCount = 0;  // Count correct answers for student i

        for (int j = 0; j < NUM_QUESTIONS; j++) {
            if (answers[i][j] == keyToQuestions[j]) {
                correctCount++;
            }
        }

        cout << "Student " << i << "'s correct count is "
             << correctCount << endl;
    }

    return 0;
}