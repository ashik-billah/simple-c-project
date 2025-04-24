#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Question {
    string text;
    string options[4];
    char correctAnswer;
};

void loadQuestions(vector<Question> &quiz) {
    // Sample hardcoded questions
    quiz.push_back({"What is the capital of France?", {"A) Berlin", "B) Madrid", "C) Paris", "D) Rome"}, 'C'});
    quiz.push_back({"Which planet is known as the Red Planet?", {"A) Earth", "B) Venus", "C) Mars", "D) Jupiter"}, 'C'});
    quiz.push_back({"What is 5 + 3?", {"A) 6", "B) 8", "C) 9", "D) 7"}, 'B'});
}

void runQuiz(const vector<Question>& quiz) {
    int score = 0;
    char answer;

    for (int i = 0; i < quiz.size(); i++) {
        cout << "\nQ" << i + 1 << ": " << quiz[i].text << endl;
        for (string opt : quiz[i].options)
            cout << opt << endl;

        cout << "Enter your answer (A/B/C/D): ";
        cin >> answer;
        answer = toupper(answer);

        if (answer == quiz[i].correctAnswer) {
            cout << "✅ Correct!" << endl;
            score++;
        } else {
            cout << "❌ Wrong! Correct answer is: " << quiz[i].correctAnswer << endl;
        }
    }

    cout << "\n🎯 Your Score: " << score << " / " << quiz.size() << endl;
}

int main() {
    vector<Question> quiz;
    loadQuestions(quiz);
    cout << "=== Welcome to the Quiz Game ===\n";
    runQuiz(quiz);
    return 0;
}
